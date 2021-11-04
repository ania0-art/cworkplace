/*
 * @Author: your name
 * @Date: 2021-11-03 21:54:30
 * @LastEditTime: 2021-11-04 11:21:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cworkplace\数据结构实验二.c
 */
#include <stdio.h> /*该文件包含printf()等函数*/
#include <stdlib.h>/*该文件包含exit()等函数*/
#include <malloc.h>/*该文件包含malloc()等函数*/
#include <assert.h>

typedef int DataType; /*定义DataType为int*/

typedef struct Node
{
    DataType data;
    struct Node *next;
} SLNode, *Linklist;

void ListInitiate(SLNode **head) /*初始化*/
{
    /*如果有内存空间，申请头结点空间并使头指针head指向头结点*/
    if ((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL)
        exit(1);
    (*head)->next = NULL; /*置链尾标记NULL */
}

int ListLength(SLNode *head) /* 单链表的长度*/
{
    SLNode *p = head; /*p指向首元结点*/
    int size = 0;     /*size初始为0*/

    while (p->next != NULL) /*循环计数*/
    {
        p = p->next;
        size++;
    }
    return size;
}

int ListInsert(SLNode *head, int i, DataType x)
/*在带头结点的单链表head的数据元素ai（0 ≤ i ≤ size）结点前*/
/*插入一个存放数据元素x的结点*/
{
    SLNode *p, *q;
    int j;

    p = head; /*p指向首元结点*/
    j = -1;   /*j初始为-1*/
    while (p->next != NULL && j < i - 1)
    /*最终让指针p指向数据元素ai-1结点*/
    {
        p = p->next;
        j++;
    }

    if (j != i - 1)
    {
        printf("插入位置参数错！");
        return 0;
    }

    /*生成新结点由指针q指示*/
    if ((q = (SLNode *)malloc(sizeof(SLNode))) == NULL)
        exit(1);
    q->data = x;

    //此段程序有一处错误
    //p->next = q->next;/*给指针q->next赋值*/
    q->next = p->next; //更正后
    p->next = q;       /*给指针p->next重新赋值*/
    return 1;
}

int ListDelete(SLNode *head, int i, DataType *x)
/*删除带头结点的单链表head的数据元素ai（0 ≤ i ≤ size - 1）结点*/
/*删除结点的数据元素域值由x带回。删除成功时返回1；失败返回0*/
{
    SLNode *p, *s;
    int j;

    p = head; /*p指向首元结点*/
    j = -1;   /*j初始为-1*/
    while (p->next != NULL && p->next->next != NULL && j < i - 1)
    /*最终让指针p指向数据元素ai-1结点*/
    {
        p = p->next;
        j++;
    }

    if (j != i - 1)
    {
        printf("删除位置参数错！");
        return 0;
    }

    //此段程序有一处错误
    //s->next = p; /*指针s指向数据元素ai结点*/
    s = p->next;       //更正后
    *x = s->data;      /*把指针s所指结点的数据元素域值赋予x*/
    p->next = s->next; /*把数据元素ai结点从单链表中删除*/
    free(s);           /*释放指针s所指结点的内存空间*/
    return 1;
}

int ListGet(SLNode *head, int i, DataType *x)
/*取数据元素ai和删除函数类同，只是不删除数据元素ai结点*/
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
        printf("取元素位置参数错！");
        return 0;
    }

    //此段程序有一处错误
    //*x = p->next;
    *x = p->data; //更正后
    return 1;
}

/*有序单链表的合并，生成一个有序的单链表，递归做法*/
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
    ListInitiate(&head); /*初始化*/
    for (i = 0; i < 10; i++)
    {
        if (ListInsert(head, i, i + 1) == 0) /*插入10个数据元素*/
        {
            printf("错误! \n");
            return;
        }
    }

    if (ListDelete(head, 4, &x) == 0) /*删除数据元素5*/
    {
        printf("错误! \n");
        return;
    }

    for (i = 0; i < ListLength(head); i++)
    {
        if (ListGet(head, i, &x) == 0) /*取元素*/
        {
            printf("错误! \n");
            return;
        }
        else
            printf("%d    ", x); /*显示数据元素*/
    }
    Destroy(&head);
    printf("\n");
    //测试
    printf("测试合并函数\n");
    Linklist L0, L1, newhead;
    ListInitiate(&L0);
    for (i = 0; i < 10; i++)
    {
        if (ListInsert(L0, i, i + 1) == 0) /*插入10个数据元素*/
        {
            printf("错误! \n");
            return;
        }
    }
    ListInitiate(&L1);
    for (i = 0; i < 10; i++)
    {
        if (ListInsert(L1, i, i + 1) == 0) /*插入10个数据元素*/
        {
            printf("错误! \n");
            return;
        }
    }
    newhead=MergerLinklist(L0->next,L1->next);
    Print_Linklist(&newhead);
    Destroy(&newhead);
    Destroy(&L1);
    Destroy(&L0);
}
