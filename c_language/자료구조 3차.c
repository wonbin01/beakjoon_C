#include <stdio.h>
#include <stdlib.h>
typedef struct listnode *pointer;
typedef struct listnode
{
    pointer llink;
    char data;
    pointer rlink;
}tree;
void postorder(pointer ptr);
void printresult(pointer ptr);
void iterativeversion(pointer node);
int main(void)
{
    pointer head,temp,node,lnext,rnext;
    head=(tree*)malloc(sizeof(tree));
    lnext=(tree*)malloc(sizeof(tree));
    temp=head; temp->data='A'; temp->rlink=NULL; temp->llink=lnext; temp=lnext; //A��� ����//
    lnext=(tree*)malloc(sizeof(tree));
    rnext=(tree*)malloc(sizeof(tree));
    temp->data='B'; temp->llink=lnext; temp->rlink=rnext; temp=lnext; node=rnext; //B��� ����//
    lnext=(tree*)malloc(sizeof(tree));
    rnext=(tree*)malloc(sizeof(tree));
    temp->data='F'; temp->llink=lnext; temp->rlink=rnext; temp=lnext; //F��� ����//
    temp->data='K'; temp->llink=NULL; temp->rlink=NULL; temp=rnext; //K��� ����//
    temp->data='G'; temp->llink=NULL; temp->rlink=NULL; //G��� ����//
    rnext=(tree*)malloc(sizeof(tree));
    node->data='C'; node->llink=NULL; node->rlink=rnext; node=rnext; //C��� ����//
    rnext=(tree*)malloc(sizeof(tree));
    node->data='D'; node->llink=NULL; node->rlink=rnext; node=rnext; //D��� ����//
    lnext=(tree*)malloc(sizeof(tree));
    node->data='E'; node->llink=lnext; node->rlink=NULL; node=lnext; //E��� ����//
    rnext=(tree*)malloc(sizeof(tree));
    node->data='H'; node->llink=NULL; node->rlink=rnext; node=rnext; //H��� ����//
    rnext=(tree*)malloc(sizeof(tree));
    node->data='I'; node->llink=NULL; node->rlink=rnext; node=rnext; //I��� ����//
    node->data='J'; node->llink=NULL; node->rlink=NULL; //J��� ����//
    postorder(head);
    printresult(head);
    printf("\n");
    iterativeversion(head);
    free(head);
    free(lnext);
    free(rnext);
    return 0;
}
void postorder(pointer ptr)
{
     if (ptr)
    {
        printf("�Լ� ����, Node: %c\n", ptr->data);
        postorder(ptr->llink);
        postorder(ptr->rlink);
        printf("�Լ� ��, Node: %c\n", ptr->data);
    }
}
void printresult(pointer ptr)
{
    if (ptr)
    {
        printresult(ptr->llink);
        printresult(ptr->rlink);
        printf("%c", ptr->data);
    }
}
void iterativeversion(pointer node) //postorder version//
{
    int top=-1;
    pointer temp;
    pointer stack[100];
    pointer lastvisitnode=NULL;
    while(1)
    {
        for(;node;node=node->llink)
        {
            stack[++top]=node;  //stack�� �������//
        }
        while(node==NULL && top!=-1)
        {
            temp=stack[top];
            if(temp->rlink==NULL || temp->rlink==lastvisitnode)
            {
                printf("%c",temp->data);
                lastvisitnode=temp;
                top--;
            }
            else //���� ������ �̵������� �̵�//
            {
                node=temp->rlink;
            }
        }
        if(top==-1)
        {
            break;
        }
    }
}