#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OVERFLOW -2

typedef struct
{

    int arrive;

    int treat; /*�ͻ�����Ϣ�ṹ*/

} QNODE;

typedef struct node
{

    QNODE data;

    struct node *next; /*�����е�Ԫ����Ϣ*/

} LNODE;

LNODE *front, *rear; /* ��ͷָ��Ͷ�βָ��*/

QNODE curr, temp;

char Fname[120];

FILE *fp;

void EnQueue(LNODE **hpt, LNODE **tpt, QNODE e)
{

    /*���н���*/

    LNODE *p = (LNODE *)malloc(sizeof(LNODE));

    if (!p)
        exit(OVERFLOW); /*�洢����ʧ��*/

    p->data = e;

    p->next = NULL;

    if (*hpt == NULL)
        *tpt = *hpt = p;

    else
        *tpt = (*tpt)->next = p;
}

int DeQueue(LNODE **hpt, LNODE **tpt, QNODE *cp)
{

    /*���Ӷ��г���*/

    LNODE *p = *hpt;

    if (*hpt == NULL)
        return 1; /*�ӿ�*/

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

    scanf("%s", Fname); /*����װ�ͻ�ģ�����ݵ��ļ����ļ���*/

    if ((fp = fopen(Fname, "r")) == NULL)
    { /*�������ļ�*/

        printf("cannot open file %s", Fname);

        return;
    }

    front = NULL;
    rear = NULL;

    have = fscanf(fp, "%d%d", &temp.arrive, &temp.treat);

    do
    { /*Լ��ÿ��ѭ��������һλ�ͻ�*/

        if (front == NULL && have == 2)
        { /*�ȴ�����Ϊ�գ������пͻ�*/

            dwait += temp.arrive - clock; /*�ۼ�ҵ��Ա�ܵȴ�ʱ��*/

            clock = temp.arrive; /*ʱ���ƽ����ݴ�����еĿͻ��ĵ���ʱ��*/

            EnQueue(&front, &rear, temp); /* �ݴ�����еĿͻ���Ϣ����*/

            have = fscanf(fp, "%d%d", &temp.arrive, &temp.treat);
        }

        count++; /*�ۼƿͻ�����*/

        DeQueue(&front, &rear, &curr); /*����һλ�ͻ���Ϣ*/

        wait += clock - curr.arrive; /*�ۼƵ��ͻ����ܵȴ�ʱ��*/

        finish = clock + curr.treat; /*�趨ҵ��������ʱ�䣻*/

        while (have == 2 && temp.arrive <= finish)
        {

            /*��һλ�ͻ��ĵ���ʱ���ڵ�ǰ�ͻ��������֮ǰ*/

            EnQueue(&front, &rear, temp); /* �ݴ�����еĿͻ���Ϣ����*/

            have = fscanf(fp, "%d%d", &temp.arrive, &temp.treat);
        }

        clock = finish; /* ʱ���ƽ�����ǰ�ͻ��������ʱ��*/

    } while (have == 2 || front != NULL);

    printf("�����ҵ��Ա����ʱ��%d\n�ͻ�ƽ���ȴ�ʱ��%.2f\n", dwait,(double)wait / count);

    printf("ģ����ʱ�䣺%d��\n�ͻ�������%d,\n�ܵȴ�ʱ�䣺%d��\n", clock,count, wait);

    getchar();
}