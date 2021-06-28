/*
 * @Author: 6371.393
 * @Date: 2021-06-28 09:58:56
 * @LastEditTime: 2021-06-28 15:41:59
 * @LastEditors: Please set LastEditors
 * @Description: vs code
 * @FilePath: \cworkplace\ѧ����Ϣ����ϵͳ.c
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 15		/* ѧ�ź���������ַ���*/
#define N 50		/* ����*/

int k = 1, n = 0;/* n����ǰ��¼��ѧ������*/

//��������
void seekStu();
void modifyStu();
void insertStu();
void delStu();
void displayStu();
void saveStu();
void menu();
void help();
int flushStu();

//�ṹ�屣��ѧ����Ϣ
struct student {
	char StudentId[LEN + 1];
	char StudentName[LEN + 1];
	int StudentAge;
	char StudentSex;
	float score[3];
}stu[N];

//������
int main()
{
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}

//ϵͳ��������
void help()
{
	printf("\n0.��ӭʹ��ϵͳ������\n");
	printf("\n1.���ν���ϵͳ��,����ѡ������ѧ����Ϣ;\n");
	printf("\n2.���ղ˵���ʾ�������ִ���;\n");
	printf("\n3.����ѧ����Ϣ��,�мǱ���;\n");
	printf("\n4.лл����ʹ�ã�\n");
	system("pause");
}

//ˢ���ļ�
int flushStu() {
	char filename[LEN + 1];
	//int i = 0;
	printf("������Ҫˢ��ѧ����Ϣ���ļ�����\n");
	scanf("%s", filename);
	int j = 0;
	FILE* fp = fopen(filename, "r");
	if (fp  == NULL)
	{
		printf("����\n");
		system("pause");
		return 0;
	}
	//���ļ���ȡ��Ϣ
	fscanf(fp, "%d", &n);
	for (j = 0; j < n; j++) {
		fscanf(fp, "%s\t%s\t%d\t%c\t%f\t%f\t%f\n", &stu[j].StudentId
			, &stu[j].StudentName
			, &stu[j].StudentAge
			, &stu[j].StudentSex
			, &stu[j].score[0]
			, &stu[j].score[1]
			, &stu[j].score[2]);
	}
	fclose(fp);
	printf("ˢ�³ɹ�!!!");
	return n;
}

//����ѧ����Ϣ
void seekStu() /*����*/
{
	int i, item, flag;
	char s1[21]; /* ��������ѧ�������+1Ϊ׼*/
	printf("------------------\n");
	printf("-----1.��ѧ�Ų�ѯ-----\n");
	printf("-----2.��������ѯ-----\n");
	printf("-----3.�˳����˵�-----\n");
	printf("------------------\n");
	while (1)
	{
		printf("��ѡ���Ӳ˵����:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("������Ҫ��ѯ��ѧ����ѧ��:\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
				if (strcmp(s1, stu[i].StudentId) == 0)
				{
					flag = 1;
					printf("--------------------------------------------------------------------\n");
					printf("ѧ��ѧ�ţ�%s ѧ��������%s ���䣺%d �Ա�%c c���Գɼ���%.1f �ߵ���ѧ��%.1f ��ѧӢ��ɼ���%.1f\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentAge, stu[i].StudentSex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				}
			if (0 == flag)
				printf("��ѧ�Ų����ڣ�\n"); break;
		case 2:
			printf("������Ҫ��ѯ��ѧ��������:\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
				if (strcmp(stu[i].StudentName, s1) == 0)
				{
					flag = 1;
					printf("--------------------------------------------------------------------\n");
					printf("ѧ��ѧ�ţ�%s ѧ��������%s ���䣺%d �Ա�%c c���Գɼ���%.1f �ߵ���ѧ��%.1f ��ѧӢ��ɼ���%.1f\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentAge, stu[i].StudentSex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				}
			if (0 == flag)
				printf("�����������ڣ�\n"); break;
		case 3:return;
		default:printf("����1-3֮��ѡ��\n");
		}
	}
}

//�޸�ѧ����Ϣ
void modifyStu() /*�޸���Ϣ*/
{
	int i, item, num = -1;
	char sex1, s1[LEN + 1], s2[LEN + 1]; /* ��������ѧ�������+1Ϊ׼*/
	float score1;
	printf("������ҪҪ�޸ĵ�ѧ����ѧ��:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++) {
		if (strcmp(stu[i].StudentId, s1) == 0) {/*�Ƚ��ַ����Ƿ����*/
			num = i;
			printf("------------------\n");
			printf("1.�޸�����\n");
			printf("2.�޸�����\n");
			printf("3.�޸��Ա�\n");
			printf("4.�޸�C���Գɼ�\n");
			printf("5.�޸ĸߵ���ѧ�ɼ�\n");
			printf("6.�޸Ĵ�ѧӢ��ɼ�\n");
			printf("7.�˳����˵�\n");
			printf("------------------\n");
			while (1)
			{
				printf("��ѡ���Ӳ˵����:");
				scanf("%d", &item);
				switch (item)
				{
				case 1:
					printf("�������µ�����:\n");
					scanf("%s", s2);
					strcpy(stu[num].StudentName, s2);
					break;
				case 2:
					printf("�������µ�����:\n");
					scanf("%d", stu[num].StudentAge);
					break;
				case 3:
					printf("�������µ��Ա�:\n");
					scanf("%s", &sex1);
					stu[i].StudentSex = sex1;
					break;
				case 4:
					printf("�������µ�C���Գɼ�:\n");
					scanf("%f", &score1);
					stu[num].score[0] = score1;
					break;
				case 5:
					printf("�������µĸߵ���ѧ�ɼ�:\n");
					scanf("%f", &score1);
					stu[num].score[1] = score1;
					break;
				case 6:
					printf("�������µĴ�ѧӢ��ɼ�:\n");
					scanf("%f", &score1);
					stu[num].score[2] = score1;
					break;
				case 7:	return;
				default:printf("����1-7֮��ѡ��\n");
				}
			}
			printf("�޸���ϣ��뼰ʱ���棡\n");
		}
	}
}

void sortStu()//��ѧ������
{
	int i, j, a, * p, * q, s;
	char temp[LEN + 1], ctemp;
	float ftemp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
			if (strcmp(stu[j - 1].StudentId, stu[j].StudentId) > 0)
			{
				strcpy(temp, stu[j - 1].StudentId);
				strcpy(stu[j - 1].StudentId, stu[j].StudentId);
				strcpy(stu[j].StudentId, temp);
				strcpy(temp, stu[j - 1].StudentName);
				strcpy(stu[j - 1].StudentName, stu[j].StudentName);
				strcpy(stu[j].StudentName, temp);
				ctemp = stu[j - 1].StudentSex;
				stu[j - 1].StudentSex = stu[j].StudentSex;
				stu[j].StudentSex = ctemp;
				p = &stu[j - 1].StudentAge;
				q = &stu[j].StudentAge;
				s = *q;
				*q = *p;
				*p = s;
				for (a = 0; a < 3; a++)
				{
					ftemp = stu[j - 1].score[a];
					stu[j - 1].score[a] = stu[j].score[a];
					stu[j].score[a] = ftemp;
				}
			}
	}
}

//���ѧ����Ϣ����
void insertStu() /*���뺯��*/
{
	int i = n, j, flag,m;
	printf("����������ӵ�ѧ����:\n");
	scanf("%d", &m);
	if (m > 0) {
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("�������%dλѧ����ѧ��:\n", i + 1);
				scanf("%s", stu[i].StudentId);
				for (j = 0; j < i; j++) {
					if (strcmp(stu[i].StudentId, stu[j].StudentId) == 0) {
						printf("��ѧ���Ѵ��ڣ����������룡\n");
						flag = 1;
						break;
					}
				}
			}
			printf("�������%d ��ѧ��������:\n", i + 1);
			scanf("%s", stu[i].StudentName);
			printf("�������%d ��ѧ��������:\n", i + 1);
			scanf("%d", &stu[i].StudentAge);
			printf("�������%d ��ѧ�����Ա�m or f):\n", i + 1);
			scanf(" %c", &stu[i].StudentSex);
			printf("�������%d ��ѧ����C���Գɼ�:\n", i + 1);
			scanf("%f", &stu[i].score[0]);
			printf("�������%d ��ѧ���ĸߵ���ѧ�ɼ�:\n", i + 1);
			scanf("%f", &stu[i].score[1]);
			printf("�������%d ��ѧ���Ĵ�ѧӢ��ɼ�:\n", i + 1);
			scanf("%f", &stu[i].score[2]);
			if (0 == flag) {
				i++;
			}
		} while (i < n + m);
	}
	n += m;
	printf("ѧ����Ϣ������ϣ�����\n");
	system("pause");
}

//ɾ��ѧ����Ϣ����
void delStu()
{
	int i, j, flag = 0;
	char s1[LEN + 1];
	printf("������Ҫɾ��ѧ����ѧ��:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++) {
		if (strcmp(stu[i].StudentId, s1) == 0) {
			flag = 1;
			//Ҫɾ��ѧ�������ѧ����ǰ��һλ
			for (j = i; j < n - 1; j++) {
				stu[j] = stu[j + 1];
			}
		}
	}
	//����ʧ��
	if (0 == flag) {
		printf("��ѧ�Ų�����!!!\n");
	}
	if (1 == flag) {
		printf("ɾ���ɹ�������");
		//ɾ���ɹ���ѧ��������1
		n--;
	}
	system("pause");
}

//��ʾȫ��������Ϣ
void displayStu()
{
	int i;
	printf("����%dλѧ������Ϣ:\n", n);
	if (0 != n)
	{
		printf("----------------------------------------------------------------------------------\n");
		for (i = 0; i < n; i++)
		{
			printf("ѧ��ѧ�ţ�%s ѧ��������%s ���䣺%d �Ա�%c c���Գɼ���%.1f �ߵ���ѧ��%.1f ��ѧӢ��ɼ���%.1f\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentAge, stu[i].StudentSex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
		}
	}
	system("pause");
}

void saveStu() {
	int i;
	FILE* fp;
	char filename[LEN + 1];
	printf("������Ҫ������ļ�����\n");
	scanf("%s", filename);
	fp = fopen(filename, "w");
	fprintf(fp, "%d\n", n);//����������
	for (i = 0; i < n; i++) {
		fprintf(fp, "%s\t%s\t%d\t%c\t%.lf\t%.lf\t%.lf\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentAge, stu[i].StudentSex,
			stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}
	printf("����ɹ�������\n");
	fclose(fp);
	system("pause");
}

void menu()/* ����*/
{
	int num;
	printf(" \n\n                    \n\n");
	printf("  ******************************************************\n\n");
	printf("  *                ��ӭʹ��ѧ����Ϣ����ϵͳ            *\n \n");
	printf("  ******************************************************\n\n");
	printf("*********************ϵͳ���ܲ˵�*************************       \n");
	printf("     ----------------------   ----------------------   \n");
	printf("     *********************************************     \n");
	printf("     * 0.���ʹ�ñ�ϵͳ  * *  1.ˢ��ѧ����Ϣ    *     \n");
	printf("     *********************************************     \n");
	printf("     * 2.��ѯѧ����Ϣ    * *  3.�޸�ѧ����Ϣ    *     \n");
	printf("     *********************************************     \n");
	printf("     * 4.����ѧ����Ϣ    * *  5.ɾ��ѧ����Ϣ    *     \n");
	printf("     *********************************************     \n");
	printf("     * 6.��ʾ������Ϣ    * *  7.���浱ǰѧ����Ϣ*     \n");
	printf("     *********************************************     \n");
	printf("     * 8.ѧ������        * *  9.�˳�����        *      \n");
	printf("     *********************************************     \n");
	printf("     ----------------------   ----------------------                           \n");
	printf("��ѡ��˵����:");
	scanf("%d", &num);
	getchar();
	switch (num)
	{
	case 0:help(); break;
	case 1:flushStu(); break;
	case 2:seekStu(); break;
	case 3:modifyStu(); break;
	case 4:insertStu(); break;
	case 5:delStu(); break;
	case 6:displayStu(); break;
	case 7:saveStu(); break;
	case 8:sortStu(); break;
	case 9:
		k = 0;
		printf("�����˳�����!\n");
		break;
	default:printf("����0-9֮��ѡ��\n");
	}
}
