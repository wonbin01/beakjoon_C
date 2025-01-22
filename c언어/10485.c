#include <stdio.h>
#include <string.h>

void push(int queue[], int *tail, int number,int *front);
void pop(int queue[], int *front, int *tail,int *size);
int main(void)
{
    int n=0;
    int front=-1; //ť�� ���� �պκ��� ��Ÿ���� �κ�
    int tail=-1; //ť�� ���� �޺κ��� ��Ÿ���� �κ�
    int queue[10001];
    char str1[100000]; // ����ڷκ��� �Է¹޴� ��ɾ�
    int number=0; //����ڷκ��� �Է¹޴� ����
    int size=0;
    scanf("%d",&n); //����ڷκ��� n�� �Է¹���(��� �ݺ��� ����)
    for(int i=0;i<n;i++)
    {
        scanf("%s", str1);

        if(strcmp(str1, "push")==0) //push
        {
            scanf("%d",&number);
            push(queue,&tail,number,&front);
            size++;

        }
        else if(strcmp(str1,"pop")==0) //pop
        {
            pop(queue,&front,&tail,&size);
        }
        else if(strcmp(str1,"size")==0) //size
        {
            printf("%d\n",size);
        }
        else if(strcmp(str1,"empty")==0) //empty
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
        else if(strcmp(str1,"front")==0) //front
        {
            if(size!=0)
            {
                printf("%d\n",queue[front]);
            }
            else
            {
                printf("%d\n",-1);
            }
        }
        else if(strcmp(str1,"back")==0) //back
        {
            if(size!=0)
            {
                printf("%d\n",queue[tail]);
            }
            else
            {
                printf("%d\n",-1);
            }
        }

    }
    return 0;
}
void push(int queue[], int *tail, int number,int *front)
{
    if(*tail==-1) //ó���� front, tail ++
    {
        (*tail)++;
        (*front)++;
        queue[*tail]=number;
    }
    else
    {
        (*tail)++;
        queue[*tail]=number;
    }
}
void pop(int queue[], int *front, int *tail,int *size)
{
    if(*size==0)
    {
        printf("%d\n",-1);
    }
    else //queue�� ������ �����Ҷ�
    {
        printf("%d\n",queue[*front]); 
        (*front)++;
        if(*front>*tail)
        {
            *front=*tail=-1;
        }
        (*size)--;
    }
}