/*
 * @Author: your name
 * @Date: 2021-09-03 15:22:19
 * @LastEditTime: 2021-09-03 16:15:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cworkplace\计算机二级考试.c
 */
/*#include<stdio.h>
int Wordcount(char str[]);
int main()
{
    char str[20];
    printf("Input a string:");
    gets(str);
    printf("Numbers of words = %d\n", Wordcount(str));
    return 0;
}
int Wordcount(char str[])
{
    int i, num; 
    num = (str[0] != ' ') ? 1 : 0; 
    for (i = 1; str[i] != '\0'; i++) 
    { 
        if (str[i] != ' ' && str[i - 1] == ' ') 
            { 
                num++; 
            } 
    }  
 return num; 
}*/
/*Q1683.(10 分)用二维数组作为函数参数，实现矩阵转置。按如下函数原型编程计算并输出
m×n 阶矩阵的转置矩阵。其中，m 和 n 的值由用户从键盘输入。已知 m 和 n 的值都不超过
10。
void Transpose(int a[][N], int at[][M], int m, int n); 
void InputMatrix(int a[][N], int m, int n); 
void PrintMatrix(int at[][M], int n, int m); 
输入提示信息："Input m, n:" 
输入格式："%d,%d" 
输出提示信息和格式："The transposed matrix is:\n。*/
/*#include<stdio.h>
#define M 10
#define N 10
void Transpose(int a[][N], int at[][M], int m, int n); 
void InputMatrix(int a[][N], int m, int n); 
void PrintMatrix(int at[][M], int n, int m);
void main()
{
    int s[M][N], st[N][M], m, n; 
    printf("Input m, n:");
    scanf("%d,%d",&m,&n);
    InputMatrix(s, m, n); 
    Transpose(s, st, m, n); 
    printf("The transposed matrix is:\n"); 
    PrintMatrix(st, n, m); 
    return 0; 
} 
/* 函数功能：计算 m*n 矩阵 a 的转置矩阵 at */
/*void Transpose(int a[][N], int at[][M], int m, int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            at[j][i]=a[i][j];
        }
    }
}
/* 函数功能：输入 m*n 矩阵 a 的值 */ 
/*void InputMatrix(int a[][N], int m, int n)
{
    int i, j; 
    printf("Input %d*%d matrix:\n", m, n); 
    for (i = 0; i < m; i++) 
    { 
        for (j = 0; j < n; j++) 
        { 
            scanf("%d", &a[i][j]); 
        } 
    } 
} */
/* 函数功能：输出 n*m 矩阵 at 的值 */ 
/*void PrintMatrix(int at[][M], int n, int m) 
{ 
    int i, j; 
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            printf("%d\t", at[i][j]); 
        } 
        printf("\n"); 
    } 
} */
/*如果整数 A 的全部因子（包括 1，不包括 A 本身）之和等于 B；且整数 B 的全
部因子（包括 1，不包括 B 本身）之和等于 A，则 A 和 B 称为亲密数。求 10000 以内的亲
密数。
**输出格式要求："(%4d,%4d)\n" 
程序运行示例如下：
( 220, 284) 
(1184,1210) 
(2620,2924) 
(5020,5564) 
(6232,6368) */
#include<stdio.h>
void main()
{
    
}