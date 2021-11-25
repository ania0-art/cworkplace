/*
 * @Author: your name
 * @Date: 2021-11-25 10:05:30
 * @LastEditTime: 2021-11-25 10:37:23
 * @LastEditors: Please set LastEditors
 * @Description: ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cworkplace\ʵ����.c
 */
#include <stdlib.h>
#include <stdio.h>
#define MAX 100

typedef char DataType;

typedef struct Node
{
    DataType data;           /*������*/
    struct Node *leftChild;  /*������ָ��*/
    struct Node *rightChild; /*������ָ��*/
} BiTreeNode;                /*���Ľṹ�嶨��*/

/*��ʼ��������������ͷ���*/
void Initiate(BiTreeNode **root)
{
    *root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    (*root)->leftChild = NULL;
    (*root)->rightChild = NULL;
}

void Destroy(BiTreeNode **root)
{
    if ((*root) != NULL && (*root)->leftChild != NULL)
        Destroy(&(*root)->leftChild);

    if ((*root) != NULL && (*root)->rightChild != NULL)
        Destroy(&(*root)->rightChild);

    free(*root);
}

/*����ǰ���curr�ǿգ���curr������������Ԫ��ֵΪx���½��*/
/*ԭcurr��ָ������������Ϊ�²������������*/
/*������ɹ������²������ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *InsertLeftNode(BiTreeNode *curr, DataType x)
{
    BiTreeNode *s, *t;
    if (curr == NULL)
        return NULL;

    t = curr->leftChild; /*����ԭcurr��ָ����������ָ��*/
    s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    s->data = x;
    s->leftChild = t; /*�²������������Ϊԭcurr��������*/
    s->rightChild = NULL;

    curr->leftChild = s;    /*�½���Ϊcurr��������*/
    return curr->leftChild; /*�����²������ָ��*/
}

/*����ǰ���curr�ǿգ���curr������������Ԫ��ֵΪx���½��*/
/*ԭcurr��ָ������������Ϊ�²������������*/
/*������ɹ������²������ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *InsertRightNode(BiTreeNode *curr, DataType x)
{
    BiTreeNode *s, *t;

    if (curr == NULL)
        return NULL;

    t = curr->rightChild; /*����ԭcurr��ָ����������ָ��*/
    s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    s->data = x;
    s->rightChild = t; /*�²������������Ϊԭcurr��������*/
    s->leftChild = NULL;

    curr->rightChild = s;    /*�½���Ϊcurr��������*/
    return curr->rightChild; /*�����²������ָ��*/
}

void PreOrder(BiTreeNode *t, void visit(DataType item))
//ʹ��visit(item)����ǰ�����������t
{
    if (t != NULL)
    { //��С����һ������
        /*visit(t->data);
        PreOrder(t->rightChild, visit);
        PreOrder(t->leftChild, visit);*/
        //����
        visit(t->data);
        PreOrder(t->leftChild, visit);
        PreOrder(t->rightChild, visit);
    }
}

//ǰ������ǵݹ��㷨
void Prev(BiTreeNode *root)
{
    BiTreeNode *p,*node[MAX];
    int top=0;
    p=root;
    do
    {
        while(p!=NULL)
        {
            printf("%c",p->data);
            node[top]=p;
            top++;
            p=p->leftChild;
        }
        if(top>0)
        {
            top--;
            p=node[top];
            p=p->rightChild;
        }
    }
    while(top>0||p!=NULL);
}

void InOrder(BiTreeNode *t, void visit(DataType item))
//ʹ��visit(item)�����������������t
{
    if (t != NULL)
    { //��С����һ������
        /*InOrder(t->leftChild, visit);
        InOrder(t->rightChild, visit);
        visit(t->data);*/
        //����
        InOrder(t->leftChild, visit);
        visit(t->data);
        InOrder(t->rightChild, visit);
    }
}

void PostOrder(BiTreeNode *t, void visit(DataType item))
//ʹ��visit(item)�����������������t
{
    if (t != NULL)
    { //��С����һ������
        /*visit(t->data);
        PostOrder(t->leftChild, visit);
        PostOrder(t->rightChild, visit);*/
        //����
        PostOrder(t->leftChild, visit);
        PostOrder(t->rightChild, visit);
        visit(t->data);
    }
}

void Visit(DataType item)
{
    printf("%c ", item);
}

BiTreeNode *Search(BiTreeNode *root, DataType x) //����Ԫ��x�Ƿ��ڶ�������
{
    BiTreeNode *find = NULL;
    if (root != NULL)
    {
        if (root->data == x)
            find = root;
        else
        {
            find = Search(root->leftChild, x);
            if (find == NULL)
                find = Search(root->rightChild, x);
        }
    }
    return find;
}

void main(void)
{
    BiTreeNode *root, *p, *pp, *find;
    char x = 'E';

    Initiate(&root);
    p = InsertLeftNode(root, 'A');
    p = InsertLeftNode(p, 'B');
    p = InsertLeftNode(p, 'D');
    p = InsertRightNode(p, 'G');
    p = InsertRightNode(root->leftChild, 'C');
    pp = p;
    InsertLeftNode(p, 'E');
    InsertRightNode(pp, 'F');

    printf("ǰ�������");
    PreOrder(root->leftChild, Visit);
    printf("\n���������");
    InOrder(root->leftChild, Visit);
    printf("\n���������");
    PostOrder(root->leftChild, Visit);
    printf("\n2020212373_������_ǰ������ǵݹ��㷨��");
    Prev(root->leftChild);

    find = Search(root, x);
    if (find != NULL)
        printf("\n����Ԫ��%c�ڶ������� \n", x);
    else
        printf("\n����Ԫ��%c���ڶ������� \n", x);

    Destroy(&root);
}
