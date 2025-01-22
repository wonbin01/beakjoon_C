#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* pre;
};
void push_front(int *size,int x,struct Node **front, struct Node **back);
void push_back(int *size,int x, struct Node **front, struct Node **back);
int main(void)
{
    struct Node* front=NULL;
    struct Node* back=NULL;
    int n; //����� ��
    int x; //�Է¹޴� ������ �ش�
    int size=0;
    scanf("%d",&n); //����� ���� �Է¹���
    char command[100];
    for(int i=0;i<n;i++)
    {
        scanf("%s",command);
        if(strcmp(command,"push_front")==0) //����� push_front�� ���
        {
            scanf("%d",&x); //x�� �Է¹���
            push_front(&size,x,&front,&back);
        }
        else if(strcmp(command,"push_back")==0) //����� push_back�� ���
        {
            scanf("%d",&x); //x�� �Է¹���
            push_back(&size,x,&front,&back);
        }
        else if(strcmp(command,"pop_front")==0) //����� pop_front�� ���
        {
            if(size==1) //������� ���� ���
            {
                printf("%d\n",front->data);
                front=NULL;
                back=NULL;
                size=0;
            }
            else if(size!=1 && size!=0)
            {
                printf("%d\n",front->data);
                front=front->next;
                front->pre=NULL;
                size--;
            }
            else if(size==0)
            {
                printf("%d\n",-1);
            }
        }
        else if(strcmp(command,"pop_back")==0) //����� pop_back�� ���
        {
            if(size==1) 
            {
                printf("%d\n",back->data);
                front=NULL;
                back=NULL;
                size=0;
            }
            else if(size!=0 && size!=1)
            {
                printf("%d\n",back->data);
                back=back->pre;
                back->next=NULL;
                size--;
            }
            else if(size==0)
            {
                printf("%d\n",-1);
            }
        }
        else if(strcmp(command,"size")==0)
        {
            printf("%d\n",size);
        }
        else if(strcmp(command,"empty")==0)
        {
            if(size==0)
            {
                printf("%d\n",1);
            }
            else
            {
                printf("%d\n",0);
            }
        }
        else if(strcmp(command,"front")==0)
        {
            if(size!=0)
            {
                printf("%d\n",front->data);
            }
            else
            {
                printf("%d\n",-1);
            }
        }
        else if(strcmp(command,"back")==0)
        {
            if(size!=0)
            {
                printf("%d\n",back->data);
            }
            else
            {
                printf("%d\n",-1);
            }
        }
    }

    return 0;
}
void push_front(int *size,int x,struct Node **front, struct Node **back) //���� �տ� ������ �Է��ϴ� �Լ�
{
    if(*size==0) //�ƹ��͵� �ȵ�� ���� ��
    {
        struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
        new_node->data=x;
        new_node->next=NULL;
        new_node->pre=NULL;
        *front=new_node;
        *back=new_node;
        (*size)++;
    }
    else if(*size!=0) //size�� 0�� �ƴҶ�
    {
        struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
        {
            new_node->data=x;
            new_node->next=*front;
            (*front)->pre=new_node;
            new_node->pre=NULL;
            *front=new_node;
            (*size)++;
        };
    }
}
void push_back(int *size,int x, struct Node **front, struct Node **back)
{
    if(*size==0) //����ִ� ���
    {
        struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
        new_node->data=x;
        new_node->next=NULL;
        new_node->pre=NULL;
        *front=new_node;
        *back=new_node;
        (*size)++;
    }
    else if(*size!=0) //������� ���� ���
    {
        struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
        (*back)->next=new_node;
        new_node->data=x;
        new_node->next=NULL;
        new_node->pre=(*back);
        (*back)=new_node;
        (*size)++;
    }
}