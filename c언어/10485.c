#include <stdio.h>
#include <string.h>

void push(int queue[], int *tail, int number,int *front);
void pop(int queue[], int *front, int *tail,int *size);
int main(void)
{
    int n=0;
    int front=-1; //큐의 가장 앞부분을 나타내는 부분
    int tail=-1; //큐의 가장 뒷부분을 나타내는 부분
    int queue[10001];
    char str1[100000]; // 사용자로부터 입력받는 명령어
    int number=0; //사용자로부터 입력받는 숫자
    int size=0;
    scanf("%d",&n); //사용자로부터 n을 입력받음(몇번 반복할 건지)
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
    if(*tail==-1) //처음에 front, tail ++
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
    else //queue에 정수가 존재할때
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