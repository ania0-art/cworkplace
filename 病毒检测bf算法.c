/*
 * @Author: your name
 * @Date: 2021-11-01 15:09:33
 * @LastEditTime: 2021-11-08 19:41:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cworkplace\���ݽṹ��ҵ.c
 */
#include <stdio.h>
#include <stdlib.h>
#define maxsiz 20
#include <string.h>
typedef struct Ssring //���Ķ���˳��ṹ
{
    char ch[maxsiz + 1]; //���洮��һά����;
    int length;          //���ĵ�ǰ����
} Ssring;
int GetLength(char *L) //�õ��ַ�����ĳ���
{
    int n = 0;
    char *p = L;
    while (*p != '\0')
    {
        n++;
        p++;
    }
    return n;
}

int Index(Ssring L1, char *L2, int pos, int L2_length) //����ģʽL2������L1�е�pos���ַ���ʼ��һ�γ��ֵ�λ�á���������ڣ��򷵻�ֵΪ0
{
    int i = pos; //��ʼ��
    int j = 1;
    while (i <= L1.length && j <= L2_length) //������δ�Ƚϵ���β
    {
        if (L1.ch[i] == L2[j])
        {
            i++;
            j++;
        }
        else //ָ����ˣ����¿�ʼ�Ƚ�
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > L2_length)
    {
        return i - L2_length;
    }
    else
    {
        return 0;
    }
}
void virus_detection(Ssring person, Ssring virus) //����BF�㷨ʵ�ֲ������
{
    int flag = 0; //����һ����־
    int m = virus.length;
    char temp[virus.length + 1];            //����һ���������飬������Ϊ�˷��㣬��������ʱ�����±�Ϊһʱ��ʼ������Ҫlength+1���ռ�
    for (int i = m + 1, j = 1; j <= m; j++) //��������dna�ٸ���һ�飬����ԭ����dna���档��Ϊ����dna��ѭ���ġ����ԣ�����Ҫ��������еĿ���
    {
        virus.ch[i++] = virus.ch[j];
    }
    virus.ch[2 * m + 1] = '\0'; //����������
    for (int i = 0; i < m; i++) //֪���˲���dna�ĳ��ȣ�ÿѭ��һ�οɵõ�������һ��dna����
    {
        for (int j = 1; j <= m; j++)
        {
            temp[j] = virus.ch[i + j];
        }
        temp[m + 1] = '\0';
        flag = Index(person, temp, 1, virus.length); //���������BF�㷨����
        if (flag)
            break;
    }
    if (flag)
        printf("�Ѿ���Ⱦ����\n");
    else
        printf("û�и�Ⱦ����\n");
}

int main()
{
    FILE *fp = fopen("1.txt", "r");
    char num[20];
    fgets(num, 20, fp); //��ȡnum
    int i = atoi(num);
    while (i--)
    {
        printf("\n���ڽ���ƥ��\n");
        Ssring L1;
        Ssring L2;
        char a[maxsiz];
        fgets(a, maxsiz, fp);
        char *p = L1.ch;
        strcpy(++p, a);
        L1.length = GetLength(a);
        printf("����dna:");
        puts(a);
        char b[maxsiz];
        fgets(b, maxsiz, fp);
        char *q = L2.ch;
        strcpy(++q, b);
        L2.length = GetLength(b);
        printf("����dna:");
        puts(b);
        virus_detection(L1, L2);
    }
    fclose(fp);
    return 0;
}