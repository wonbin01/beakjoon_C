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
    temp=head; temp->data='A'; temp->rlink=NULL; temp->llink=lnext; temp=lnext; //A노드 생성//
    lnext=(tree*)malloc(sizeof(tree));
    rnext=(tree*)malloc(sizeof(tree));
    temp->data='B'; temp->llink=lnext; temp->rlink=rnext; temp=lnext; node=rnext; //B노드 생성//
    lnext=(tree*)malloc(sizeof(tree));
    rnext=(tree*)malloc(sizeof(tree));
    temp->data='F'; temp->llink=lnext; temp->rlink=rnext; temp=lnext; //F노드 생성//
    temp->data='K'; temp->llink=NULL; temp->rlink=NULL; temp=rnext; //K노드 생성//
    temp->data='G'; temp->llink=NULL; temp->rlink=NULL; //G노드 생성//
    rnext=(tree*)malloc(sizeof(tree));
    node->data='C'; node->llink=NULL; node->rlink=rnext; node=rnext; //C노드 생성//
    rnext=(tree*)malloc(sizeof(tree));
    node->data='D'; node->llink=NULL; node->rlink=rnext; node=rnext; //D노드 생성//
    lnext=(tree*)malloc(sizeof(tree));
    node->data='E'; node->llink=lnext; node->rlink=NULL; node=lnext; //E노드 생성//
    rnext=(tree*)malloc(sizeof(tree));
    node->data='H'; node->llink=NULL; node->rlink=rnext; node=rnext; //H노드 생성//
    rnext=(tree*)malloc(sizeof(tree));
    node->data='I'; node->llink=NULL; node->rlink=rnext; node=rnext; //I노드 생성//
    node->data='J'; node->llink=NULL; node->rlink=NULL; //J노드 생성//
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
        printf("함수 시작, Node: %c\n", ptr->data);
        postorder(ptr->llink);
        postorder(ptr->rlink);
        printf("함수 끝, Node: %c\n", ptr->data);
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
            stack[++top]=node;  //stack에 집어넣음//
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
            else //아직 오른쪽 이동안했음 이동//
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