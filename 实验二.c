/*
 * @Author: your name
 * @Date: 2021-11-03 21:54:30
 * @LastEditTime: 2021-11-04 11:21:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cworkplace\���ݽṹʵ���.c
 */
#include <stdio.h> /*���ļ�����printf()�Ⱥ���*/
#include <stdlib.h>/*���ļ�����exit()�Ⱥ���*/
#include <malloc.h>/*���ļ�����malloc()�Ⱥ���*/
#include <assert.h>

typedef int DataType; /*����DataTypeΪint*/

typedef struct Node
{
    DataType data;
    struct Node *next;
} SLNode, *Linklist;

void ListInitiate(SLNode **head) /*��ʼ��*/
{
    /*������ڴ�ռ䣬����ͷ���ռ䲢ʹͷָ��headָ��ͷ���*/
    if ((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL)
        exit(1);
    (*head)->next = NULL; /*����β���NULL */
}

int ListLength(SLNode *head) /* ������ĳ���*/
{
    SLNode *p = head; /*pָ����Ԫ���*/
    int size = 0;     /*size��ʼΪ0*/

    while (p->next != NULL) /*ѭ������*/
    {
        p = p->next;
        size++;
    }
    return size;
}

int ListInsert(SLNode *head, int i, DataType x)
/*�ڴ�ͷ���ĵ�����head������Ԫ��ai��0 �� i �� size�����ǰ*/
/*����һ���������Ԫ��x�Ľ��*/
{
    SLNode *p, *q;
    int j;

    p = head; /*pָ����Ԫ���*/
    j = -1;   /*j��ʼΪ-1*/
    while (p->next != NULL && j < i - 1)
    /*������ָ��pָ������Ԫ��ai-1���*/
    {
        p = p->next;
        j++;
    }

    if (j != i - 1)
    {
        printf("����λ�ò�����");
        return 0;
    }

    /*�����½����ָ��qָʾ*/
    if ((q = (SLNode *)malloc(sizeof(SLNode))) == NULL)
        exit(1);
    q->data = x;

    //�˶γ�����һ������
    //p->next = q->next;/*��ָ��q->next��ֵ*/
    q->next = p->next; //������
    p->next = q;       /*��ָ��p->next���¸�ֵ*/
    return 1;
}

int ListDelete(SLNode *head, int i, DataType *x)
/*ɾ����ͷ���ĵ�����head������Ԫ��ai��0 �� i �� size - 1�����*/
/*ɾ����������Ԫ����ֵ��x���ء�ɾ���ɹ�ʱ����1��ʧ�ܷ���0*/
{
    SLNode *p, *s;
    int j;

    p = head; /*pָ����Ԫ���*/
    j = -1;   /*j��ʼΪ-1*/
    while (p->next != NULL && p->next->next != NULL && j < i - 1)
    /*������ָ��pָ������Ԫ��ai-1���*/
    {
        p = p->next;
        j++;
    }

    if (j != i - 1)
    {
        printf("ɾ��λ�ò�����");
        return 0;
    }

    //�˶γ�����һ������
    //s->next = p; /*ָ��sָ������Ԫ��ai���*/
    s = p->next;       //������
    *x = s->data;      /*��ָ��s��ָ��������Ԫ����ֵ����x*/
    p->next = s->next; /*������Ԫ��ai���ӵ�������ɾ��*/
    free(s);           /*�ͷ�ָ��s��ָ�����ڴ�ռ�*/
    return 1;
}

int ListGet(SLNode *head, int i, DataType *x)
/*ȡ����Ԫ��ai��ɾ��������ͬ��ֻ�ǲ�ɾ������Ԫ��ai���*/
{
    SLNode *p;
    int j;

    p = head;
    j = -1;
    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }

    if (j != i)
    {
        printf("ȡԪ��λ�ò�����");
        return 0;
    }

    //�˶γ�����һ������
    //*x = p->next;
    *x = p->data; //������
    return 1;
}

/*��������ĺϲ�������һ������ĵ������ݹ�����*/
Linklist MergerLinklist(Linklist L0, Linklist L1)
{
    SLNode *Newhead;
    if (L0 == NULL)
    {
        return L1;
    }
    else if (L1 == NULL)
    {
        return L0;
    }
    else
    {
        if (L0->data < L1->data)
        {
            Newhead = L0;
            Newhead->next = MergerLinklist(L0->next, L1);
        }
        else
        {
            Newhead = L1;
            Newhead->next = MergerLinklist(L1->next, L0);
        }
    }
    return Newhead;
}

void Destroy(SLNode **head)
{
    SLNode *p, *p1;

    p = *head;
    while (p != NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
    *head = NULL;
}

void Print_Linklist(Linklist *L)
{
	SLNode *p;
	p = *L;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}


void main(void)
{
    SLNode *head;
    int i, x;
    ListInitiate(&head); /*��ʼ��*/
    for (i = 0; i < 10; i++)
    {
        if (ListInsert(head, i, i + 1) == 0) /*����10������Ԫ��*/
        {
            printf("����! \n");
            return;
        }
    }

    if (ListDelete(head, 4, &x) == 0) /*ɾ������Ԫ��5*/
    {
        printf("����! \n");
        return;
    }

    for (i = 0; i < ListLength(head); i++)
    {
        if (ListGet(head, i, &x) == 0) /*ȡԪ��*/
        {
            printf("����! \n");
            return;
        }
        else
            printf("%d    ", x); /*��ʾ����Ԫ��*/
    }
    Destroy(&head);
    printf("\n");
    //����
    printf("���Ժϲ�����\n");
    Linklist L0, L1, newhead;
    ListInitiate(&L0);
    for (i = 0; i < 10; i++)
    {
        if (ListInsert(L0, i, i + 1) == 0) /*����10������Ԫ��*/
        {
            printf("����! \n");
            return;
        }
    }
    ListInitiate(&L1);
    for (i = 0; i < 10; i++)
    {
        if (ListInsert(L1, i, i + 1) == 0) /*����10������Ԫ��*/
        {
            printf("����! \n");
            return;
        }
    }
    newhead=MergerLinklist(L0->next,L1->next);
    Print_Linklist(&newhead);
    Destroy(&newhead);
    Destroy(&L1);
    Destroy(&L0);
}
