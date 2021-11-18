/*
 * @Author: your name
 * @Date: 2021-11-01 15:09:33
 * @LastEditTime: 2021-11-08 19:41:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cworkplace\数据结构作业.c
 */
#include <stdio.h>
#include <stdlib.h>
#define maxsiz 20
#include <string.h>
typedef struct Ssring //串的定长顺序结构
{
    char ch[maxsiz + 1]; //储存串的一维数组;
    int length;          //串的当前长度
} Ssring;
int GetLength(char *L) //得到字符数组的长度
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

int Index(Ssring L1, char *L2, int pos, int L2_length) //返回模式L2在主串L1中第pos个字符开始第一次出现的位置。如果不存在，则返回值为0
{
    int i = pos; //初始化
    int j = 1;
    while (i <= L1.length && j <= L2_length) //俩串都未比较到串尾
    {
        if (L1.ch[i] == L2[j])
        {
            i++;
            j++;
        }
        else //指针回退，重新开始比较
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
void virus_detection(Ssring person, Ssring virus) //利用BF算法实现病毒检测
{
    int flag = 0; //设置一个标志
    int m = virus.length;
    char temp[virus.length + 1];            //定义一个辅助数组，但我们为了方便，储存数据时，在下标为一时开始。所以要length+1个空间
    for (int i = m + 1, j = 1; j <= m; j++) //将病毒的dna再复制一遍，跟在原来的dna后面。因为病毒dna是循环的。所以，我们要检测它所有的可能
    {
        virus.ch[i++] = virus.ch[j];
    }
    virus.ch[2 * m + 1] = '\0'; //别忘记这里
    for (int i = 0; i < m; i++) //知道了病毒dna的长度，每循环一次可得到病毒的一种dna序列
    {
        for (int j = 1; j <= m; j++)
        {
            temp[j] = virus.ch[i + j];
        }
        temp[m + 1] = '\0';
        flag = Index(person, temp, 1, virus.length); //在这里采用BF算法即可
        if (flag)
            break;
    }
    if (flag)
        printf("已经感染病毒\n");
    else
        printf("没有感染病毒\n");
}

int main()
{
    FILE *fp = fopen("1.txt", "r");
    char num[20];
    fgets(num, 20, fp); //读取num
    int i = atoi(num);
    while (i--)
    {
        printf("\n现在进行匹配\n");
        Ssring L1;
        Ssring L2;
        char a[maxsiz];
        fgets(a, maxsiz, fp);
        char *p = L1.ch;
        strcpy(++p, a);
        L1.length = GetLength(a);
        printf("人类dna:");
        puts(a);
        char b[maxsiz];
        fgets(b, maxsiz, fp);
        char *q = L2.ch;
        strcpy(++q, b);
        L2.length = GetLength(b);
        printf("病毒dna:");
        puts(b);
        virus_detection(L1, L2);
    }
    fclose(fp);
    return 0;
}