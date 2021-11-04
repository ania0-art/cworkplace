/*
 * @Author: your name
 * @Date: 2021-11-03 18:02:33
 * @LastEditTime: 2021-11-03 23:42:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cworkplace\���ݽṹʵ��һ.c
 */
#include <stdio.h>
#define MaxSize 100
typedef int DataType;

typedef struct
{
  DataType list[MaxSize];
  int size;
} SeqList;

void ListInitiate(SeqList *L) /*��ʼ��˳���L*/
{
  L->size = 0; /*�����ʼ����Ԫ�ظ���*/
}

int ListLength(SeqList L) /*����˳���L�ĵ�ǰ����Ԫ�ظ���*/
{
  return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*��˳���L��λ��i��0 �� i �� size��ǰ��������Ԫ��ֵx*/
/*����ɹ�����1������ʧ�ܷ���0*/
{
  int j;
  if (L->size >= MaxSize)
  {
    printf("˳��������޷�����! \n");
    return 0;
  }
  else if (i < 0 || i > L->size)
  {
    printf("����i���Ϸ�! \n");
    return 0;
  }
  else
  { //�˶γ�����һ������
    //for(j = L->size; j > i; j--)
    for (j = L->size; j >= i; j--) //����
      L->list[j + 1] = L->list[j]; /*Ϊ������׼��*/
    L->list[i] = x;                /*����*/
    L->size++;                     /*Ԫ�ظ�����1*/
    return 1;
  }
}

int ListDelete(SeqList *L, int i, DataType *x)
/*ɾ��˳���L��λ��i��0 �� i �� size - 1��������Ԫ��ֵ����ŵ�����x��*/
/*ɾ���ɹ�����1��ɾ��ʧ�ܷ���0*/
{
  int j;
  if (L->size <= 0)
  {
    printf("˳����ѿ�������Ԫ�ؿ�ɾ! \n");
    return 0;
  }
  else if (i < 0 || i > L->size - 1)
  {
    printf("����i���Ϸ�");
    return 0;
  }
  else
  { //�˶γ�����һ������

    *x = L->list[i]; /*����ɾ����Ԫ�ص�����x��*/
    for (j = i + 1; j <= L->size - 1; j++)
      //L->list[j] = L->list[j-1];/*����ǰ��*/
      L->list[j - 1] = L->list[j]; //����
    L->size--;                     /*����Ԫ�ظ�����1*/
    return 1;
  }
}

int ListGet(SeqList L, int i, DataType *x)
/*ȡ˳���L�е�i������Ԫ�ص�ֵ����x�У��ɹ��򷵻�1��ʧ�ܷ���0*/
{
  if (i < 0 || i > L.size - 1)
  {
    printf("����i���Ϸ�! \n");
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
    //ListGet(,i,&x); //�˶γ�����һ������
    ListGet(myList, i, &x); //����
    printf("%d", x);
  }
  printf("\n");
  //����
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
