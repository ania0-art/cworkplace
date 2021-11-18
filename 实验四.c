#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OVERFLOW -2

typedef struct
{

    int arrive;

    int treat; /*客户的信息结构*/

} QNODE;

typedef struct node
{

    QNODE data;

    struct node *next; /*队列中的元素信息*/

} LNODE;

LNODE *front, *rear; /* 队头指针和队尾指针*/

QNODE curr, temp;

char Fname[120];

FILE *fp;

void EnQueue(LNODE **hpt, LNODE **tpt, QNODE e)
{

    /*队列进队*/

    LNODE *p = (LNODE *)malloc(sizeof(LNODE));

    if (!p)
        exit(OVERFLOW); /*存储分配失败*/

    p->data = e;

    p->next = NULL;

    if (*hpt == NULL)
        *tpt = *hpt = p;

    else
        *tpt = (*tpt)->next = p;
}

int DeQueue(LNODE **hpt, LNODE **tpt, QNODE *cp)
{

    /*链接队列出队*/

    LNODE *p = *hpt;

    if (*hpt == NULL)
        return 1; /*队空*/

    *cp = (*hpt)->data;

    *hpt = (*hpt)->next;

    if (*hpt == NULL)
        *tpt = NULL;

    free(p);

    return 0;
}

void main()

{
    int dwait = 0, clock = 0, wait = 0, count = 0, have = 0, finish;

    printf("\n enter file name:");

    scanf("%s", Fname); /*输入装客户模拟数据的文件的文件名*/

    if ((fp = fopen(Fname, "r")) == NULL)
    { /*打开数据文件*/

        printf("cannot open file %s", Fname);

        return;
    }

    front = NULL;
    rear = NULL;

    have = fscanf(fp, "%d%d", &temp.arrive, &temp.treat);

    do
    { /*约定每轮循环，处理一位客户*/

        if (front == NULL && have == 2)
        { /*等待队列为空，但还有客户*/

            dwait += temp.arrive - clock; /*累计业务员总等待时间*/

            clock = temp.arrive; /*时钟推进到暂存变量中的客户的到达时间*/

            EnQueue(&front, &rear, temp); /* 暂存变量中的客户信息进队*/

            have = fscanf(fp, "%d%d", &temp.arrive, &temp.treat);
        }

        count++; /*累计客户人数*/

        DeQueue(&front, &rear, &curr); /*出队一位客户信息*/

        wait += clock - curr.arrive; /*累计到客户的总等待时间*/

        finish = clock + curr.treat; /*设定业务办理结束时间；*/

        while (have == 2 && temp.arrive <= finish)
        {

            /*下一位客户的到达时间在当前客户处理结束之前*/

            EnQueue(&front, &rear, temp); /* 暂存变量中的客户信息进队*/

            have = fscanf(fp, "%d%d", &temp.arrive, &temp.treat);
        }

        clock = finish; /* 时钟推进到当前客户办理结束时间*/

    } while (have == 2 || front != NULL);

    printf("结果：业务员空闲时间%d\n客户平均等待时间%.2f\n", dwait,(double)wait / count);

    printf("模拟总时间：%d，\n客户人数：%d,\n总等待时间：%d。\n", clock,count, wait);

    getchar();
}