/*
 * @Author: 6371.393
 * @Date: 2021-06-28 09:58:56
 * @LastEditTime: 2021-06-28 15:41:59
 * @LastEditors: Please set LastEditors
 * @Description: vs code
 * @FilePath: \cworkplace\学生信息管理系统.c
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 15		/* 学号和姓名最大字符数*/
#define N 50		/* 人数*/

int k = 1, n = 0;/* n代表当前记录的学生人数*/

//函数声明
void seekStu();
void modifyStu();
void insertStu();
void delStu();
void displayStu();
void saveStu();
void menu();
void help();
int flushStu();

//结构体保存学生信息
struct student {
	char StudentId[LEN + 1];
	char StudentName[LEN + 1];
	int StudentAge;
	char StudentSex;
	float score[3];
}stu[N];

//主函数
int main()
{
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}

//系统帮助函数
void help()
{
	printf("\n0.欢迎使用系统帮助！\n");
	printf("\n1.初次进入系统后,请先选择增加学生信息;\n");
	printf("\n2.按照菜单提示键入数字代号;\n");
	printf("\n3.增加学生信息后,切记保存;\n");
	printf("\n4.谢谢您的使用！\n");
	system("pause");
}

//刷新文件
int flushStu() {
	char filename[LEN + 1];
	//int i = 0;
	printf("请输入要刷新学生信息的文件名：\n");
	scanf("%s", filename);
	int j = 0;
	FILE* fp = fopen(filename, "r");
	if (fp  == NULL)
	{
		printf("错误\n");
		system("pause");
		return 0;
	}
	//从文件读取信息
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
	printf("刷新成功!!!");
	return n;
}

//查找学生信息
void seekStu() /*查找*/
{
	int i, item, flag;
	char s1[21]; /* 以姓名和学号最长长度+1为准*/
	printf("------------------\n");
	printf("-----1.按学号查询-----\n");
	printf("-----2.按姓名查询-----\n");
	printf("-----3.退出本菜单-----\n");
	printf("------------------\n");
	while (1)
	{
		printf("请选择子菜单编号:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("请输入要查询的学生的学号:\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
				if (strcmp(s1, stu[i].StudentId) == 0)
				{
					flag = 1;
					printf("--------------------------------------------------------------------\n");
					printf("学生学号：%s 学生姓名：%s 年龄：%d 性别：%c c语言成绩：%.1f 高等数学：%.1f 大学英语成绩：%.1f\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentAge, stu[i].StudentSex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				}
			if (0 == flag)
				printf("该学号不存在！\n"); break;
		case 2:
			printf("请输入要查询的学生的姓名:\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
				if (strcmp(stu[i].StudentName, s1) == 0)
				{
					flag = 1;
					printf("--------------------------------------------------------------------\n");
					printf("学生学号：%s 学生姓名：%s 年龄：%d 性别：%c c语言成绩：%.1f 高等数学：%.1f 大学英语成绩：%.1f\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentAge, stu[i].StudentSex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				}
			if (0 == flag)
				printf("该姓名不存在！\n"); break;
		case 3:return;
		default:printf("请在1-3之间选择\n");
		}
	}
}

//修改学生信息
void modifyStu() /*修改信息*/
{
	int i, item, num = -1;
	char sex1, s1[LEN + 1], s2[LEN + 1]; /* 以姓名和学号最长长度+1为准*/
	float score1;
	printf("请输入要要修改的学生的学号:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++) {
		if (strcmp(stu[i].StudentId, s1) == 0) {/*比较字符串是否相等*/
			num = i;
			printf("------------------\n");
			printf("1.修改姓名\n");
			printf("2.修改年龄\n");
			printf("3.修改性别\n");
			printf("4.修改C语言成绩\n");
			printf("5.修改高等数学成绩\n");
			printf("6.修改大学英语成绩\n");
			printf("7.退出本菜单\n");
			printf("------------------\n");
			while (1)
			{
				printf("请选择子菜单编号:");
				scanf("%d", &item);
				switch (item)
				{
				case 1:
					printf("请输入新的姓名:\n");
					scanf("%s", s2);
					strcpy(stu[num].StudentName, s2);
					break;
				case 2:
					printf("请输入新的年龄:\n");
					scanf("%d", stu[num].StudentAge);
					break;
				case 3:
					printf("请输入新的性别:\n");
					scanf("%s", &sex1);
					stu[i].StudentSex = sex1;
					break;
				case 4:
					printf("请输入新的C语言成绩:\n");
					scanf("%f", &score1);
					stu[num].score[0] = score1;
					break;
				case 5:
					printf("请输入新的高等数学成绩:\n");
					scanf("%f", &score1);
					stu[num].score[1] = score1;
					break;
				case 6:
					printf("请输入新的大学英语成绩:\n");
					scanf("%f", &score1);
					stu[num].score[2] = score1;
					break;
				case 7:	return;
				default:printf("请在1-7之间选择\n");
				}
			}
			printf("修改完毕！请及时保存！\n");
		}
	}
}

void sortStu()//按学号排序
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

//添加学生信息函数
void insertStu() /*插入函数*/
{
	int i = n, j, flag,m;
	printf("请输入待增加的学生数:\n");
	scanf("%d", &m);
	if (m > 0) {
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("请输入第%d位学生的学号:\n", i + 1);
				scanf("%s", stu[i].StudentId);
				for (j = 0; j < i; j++) {
					if (strcmp(stu[i].StudentId, stu[j].StudentId) == 0) {
						printf("该学号已存在，请重新输入！\n");
						flag = 1;
						break;
					}
				}
			}
			printf("请输入第%d 个学生的姓名:\n", i + 1);
			scanf("%s", stu[i].StudentName);
			printf("请输入第%d 个学生的年龄:\n", i + 1);
			scanf("%d", &stu[i].StudentAge);
			printf("请输入第%d 个学生的性别（m or f):\n", i + 1);
			scanf(" %c", &stu[i].StudentSex);
			printf("请输入第%d 个学生的C语言成绩:\n", i + 1);
			scanf("%f", &stu[i].score[0]);
			printf("请输入第%d 个学生的高等数学成绩:\n", i + 1);
			scanf("%f", &stu[i].score[1]);
			printf("请输入第%d 个学生的大学英语成绩:\n", i + 1);
			scanf("%f", &stu[i].score[2]);
			if (0 == flag) {
				i++;
			}
		} while (i < n + m);
	}
	n += m;
	printf("学生信息增加完毕！！！\n");
	system("pause");
}

//删除学生信息函数
void delStu()
{
	int i, j, flag = 0;
	char s1[LEN + 1];
	printf("请输入要删除学生的学号:\n");
	scanf("%s", s1);
	for (i = 0; i < n; i++) {
		if (strcmp(stu[i].StudentId, s1) == 0) {
			flag = 1;
			//要删除学生后面的学生往前移一位
			for (j = i; j < n - 1; j++) {
				stu[j] = stu[j + 1];
			}
		}
	}
	//查找失败
	if (0 == flag) {
		printf("该学号不存在!!!\n");
	}
	if (1 == flag) {
		printf("删除成功！！！");
		//删除成功，学生人数减1
		n--;
	}
	system("pause");
}

//显示全部数据信息
void displayStu()
{
	int i;
	printf("共有%d位学生的信息:\n", n);
	if (0 != n)
	{
		printf("----------------------------------------------------------------------------------\n");
		for (i = 0; i < n; i++)
		{
			printf("学生学号：%s 学生姓名：%s 年龄：%d 性别：%c c语言成绩：%.1f 高等数学：%.1f 大学英语成绩：%.1f\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentAge, stu[i].StudentSex, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
		}
	}
	system("pause");
}

void saveStu() {
	int i;
	FILE* fp;
	char filename[LEN + 1];
	printf("请输入要保存的文件名：\n");
	scanf("%s", filename);
	fp = fopen(filename, "w");
	fprintf(fp, "%d\n", n);//储存总人数
	for (i = 0; i < n; i++) {
		fprintf(fp, "%s\t%s\t%d\t%c\t%.lf\t%.lf\t%.lf\n", stu[i].StudentId, stu[i].StudentName, stu[i].StudentAge, stu[i].StudentSex,
			stu[i].score[0], stu[i].score[1], stu[i].score[2]);
	}
	printf("保存成功！！！\n");
	fclose(fp);
	system("pause");
}

void menu()/* 界面*/
{
	int num;
	printf(" \n\n                    \n\n");
	printf("  ******************************************************\n\n");
	printf("  *                欢迎使用学生信息管理系统            *\n \n");
	printf("  ******************************************************\n\n");
	printf("*********************系统功能菜单*************************       \n");
	printf("     ----------------------   ----------------------   \n");
	printf("     *********************************************     \n");
	printf("     * 0.如何使用本系统  * *  1.刷新学生信息    *     \n");
	printf("     *********************************************     \n");
	printf("     * 2.查询学生信息    * *  3.修改学生信息    *     \n");
	printf("     *********************************************     \n");
	printf("     * 4.增加学生信息    * *  5.删除学生信息    *     \n");
	printf("     *********************************************     \n");
	printf("     * 6.显示已有信息    * *  7.保存当前学生信息*     \n");
	printf("     *********************************************     \n");
	printf("     * 8.学号排序        * *  9.退出程序        *      \n");
	printf("     *********************************************     \n");
	printf("     ----------------------   ----------------------                           \n");
	printf("请选择菜单编号:");
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
		printf("即将退出程序!\n");
		break;
	default:printf("请在0-9之间选择\n");
	}
}
