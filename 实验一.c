/*
 * @Author: your name
 * @Date: 2021-11-03 18:02:33
 * @LastEditTime: 2021-11-03 23:42:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cworkplace\数据结构实验一.c
 */
#include <stdio.h>
#define MaxSize 100
typedef int DataType;

typedef struct
{
  DataType list[MaxSize];
  int size;
} SeqList;

void ListInitiate(SeqList *L) /*初始化顺序表L*/
{
  L->size = 0; /*定义初始数据元素个数*/
}

int ListLength(SeqList L) /*返回顺序表L的当前数据元素个数*/
{
  return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*在顺序表L的位置i（0 ≤ i ≤ size）前插入数据元素值x*/
/*插入成功返回1，插入失败返回0*/
{
  int j;
  if (L->size >= MaxSize)
  {
    printf("顺序表已满无法插入! \n");
    return 0;
  }
  else if (i < 0 || i > L->size)
  {
    printf("参数i不合法! \n");
    return 0;
  }
  else
  { //此段程序有一处错误
    //for(j = L->size; j > i; j--)
    for (j = L->size; j >= i; j--) //更正
      L->list[j + 1] = L->list[j]; /*为插入做准备*/
    L->list[i] = x;                /*插入*/
    L->size++;                     /*元素个数加1*/
    return 1;
  }
}

int ListDelete(SeqList *L, int i, DataType *x)
/*删除顺序表L中位置i（0 ≤ i ≤ size - 1）的数据元素值并存放到参数x中*/
/*删除成功返回1，删除失败返回0*/
{
  int j;
  if (L->size <= 0)
  {
    printf("顺序表已空无数据元素可删! \n");
    return 0;
  }
  else if (i < 0 || i > L->size - 1)
  {
    printf("参数i不合法");
    return 0;
  }
  else
  { //此段程序有一处错误

    *x = L->list[i]; /*保存删除的元素到参数x中*/
    for (j = i + 1; j <= L->size - 1; j++)
      //L->list[j] = L->list[j-1];/*依次前移*/
      L->list[j - 1] = L->list[j]; //更正
    L->size--;                     /*数据元素个数减1*/
    return 1;
  }
}

int ListGet(SeqList L, int i, DataType *x)
/*取顺序表L中第i个数据元素的值存于x中，成功则返回1，失败返回0*/
{
  if (i < 0 || i > L.size - 1)
  {
    printf("参数i不合法! \n");
    return 0;
  }
  else
  {
    *x = L.list[i];
    return 1;
  }
}
SeqList ListMerge(SeqList L1, SeqList L2)
{
  SeqList new;
  ListInitiate(&new);
  int index = 0;
  for (int i = 0; i < L1.size; ++i)
  {
    ListInsert(&new, index++, L1.list[i]);
  }
  for (int i = 0; i < L2.size; ++i)
  {
    ListInsert(&new, index++, L2.list[i]);
  }
  return new;
}

void main(void)
{
  SeqList myList;
  int i, x;
  ListInitiate(&myList);
  for (i = 0; i < 10; i++)
    ListInsert(&myList, i, i + 1);
  ListDelete(&myList, 4, &x);
  for (i = 0; i < ListLength(myList); i++)
  {
    //ListGet(,i,&x); //此段程序有一处错误
    ListGet(myList, i, &x); //更正
    printf("%d", x);
  }
  printf("\n");
  //测试
  SeqList secondList;
  ListInitiate(&secondList);
  for (i = 0; i < 5; i++)
    ListInsert(&secondList, i, i + 3);
  SeqList new = ListMerge(myList, secondList);

  for (i = 0; i < ListLength(new); i++)
  {
    ListGet(new, i, &x);
    printf("%d\t", x);
  }
}
