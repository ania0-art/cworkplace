/*
 * @Author: your name
 * @Date: 2021-11-01 15:09:33
 * @LastEditTime: 2021-11-02 17:52:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cworkplace\���ݽṹ��ҵ.c
 */
#include <stdio.h>
#include <stdlib.h>
#define maxsiz 20
#include<string.h>
typedef struct Ssring//���Ķ���˳��ṹ
{
    char ch[maxsiz+1];//���洮��һά����;
    int length;//���ĵ�ǰ����
}Ssring;
int GetLength(char *L)//�õ��ַ�����ĳ���
{
    int n = 0;
    char *p = L;
    while(*p!='\0')
    {
        n++;
        p++;
    }
    return n;
}
void inistSstring(Ssring * L)//��ʼ����
{
    char a[maxsiz];//����һ����������
    scanf("%s",a);
    char *p= L->ch;//����һ���ַ�ָ�룬ָ�����������
    strcpy(++p,a);//��������±�Ϊ1��λ�ÿ�ʼ��ֵ��ע��Ϊ�˷��㣬���ǲ�����0��ʼ���±�
    L->length = GetLength(a);//˳������ȸ�ֵ
}
int index(Ssring L1,char* L2,int pos,int L2_length)//����ģʽL2������L1�е�pos���ַ���ʼ��һ�γ��ֵ�λ�á���������ڣ��򷵻�ֵΪ0
{
    int i = pos;//��ʼ��
    int j = 1;
    while(i<=L1.length&&j<=L2_length)//������δ�Ƚϵ���β
    {
        if(L1.ch[i]==L2[j])
        {
            i++;
            j++;
        }else//ָ����ˣ����¿�ʼ�Ƚ�
        {
            i = i-j+2;
            j=1;
        }
    }
    if(j>L2_length)
    {
        return i-L2_length;
    }else
    {
        return 0;
    }
}
void  virus_detection(Ssring person,Ssring virus)//����BF�㷨ʵ�ֲ������
{
    int flag = 0;//����һ����־
    int  m = virus.length;
    char temp[virus.length+1];//����һ���������飬������Ϊ�˷��㣬��������ʱ�����±�Ϊһʱ��ʼ������Ҫlength+1���ռ�
    for(int i = m+1,j=1;j<=m;j++)//��������dna�ٸ���һ�飬����ԭ����dna���档��Ϊ����dna��ѭ���ġ����ԣ�����Ҫ��������еĿ���
    {
        virus.ch[i++]=virus.ch[j];
    }
    virus.ch[2*m+1]='\0';//����������
    for(int i=0;i<m;i++)//֪���˲���dna�ĳ��ȣ�ÿѭ��һ�οɵõ�������һ��dna����
    {
        for(int j=1;j<=m;j++)
         {
             temp[j]=virus.ch[i+j];
         }
         temp[m+1]='\0';
         flag = index(person,temp,1,virus.length);//���������BF�㷨����
         if(flag) break;
    }
    if(flag)
        printf("�Ѿ���Ⱦ����\n");
    else
        printf("û�и�Ⱦ����\n");
}
int main()
{
    while(1)
    {
    printf("����������dna\n");
    Ssring L1;
    Ssring L2;
    inistSstring(&L1);
    printf("�����벡��dna\n");
    inistSstring(&L2);
    printf("���ڽ���ƥ��\n");
    virus_detection(L1,L2);
    }

    return 0;
}