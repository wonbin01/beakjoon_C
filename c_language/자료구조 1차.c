#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_name 20
#define max_phone 100
#define max_subject 10
typedef  struct list
{
    char name[max_name];
    char phone_number[max_phone];
    char subject[max_subject];
    union code
    {
        float record;
        int score;
        char truth[10];
    }information;
}people;
void fastest_client_and_average(int n,people client[],int swim_count);
void minist_client_and_average(int n,people client[],int Golf_count);
void Yoga_patient(int n,people client[],int Yoga_count); 
int main(void)
{
    int n;
    scanf("%d",&n); 
    people *client=(people*)malloc(n*sizeof(people));
    if(client==NULL)
    {
        fprintf(stderr,"메모리 할당 실패\n");
        exit(-1);
    } 
    printf("고객 정보를 입력해주세요\n");
    int swim_count=0;
    int Golf_count=0;
    int Yoga_count=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s %s %s",client[i].name,client[i].phone_number,client[i].subject);

        if(strcmp(client[i].subject,"S")==0)
        {
            scanf("%f",&client[i].information.record);
            swim_count++;
        }
        else if(strcmp(client[i].subject,"G")==0)
        {
            scanf("%d",&client[i].information.score);
            Golf_count++;
        }
        else if(strcmp(client[i].subject,"Y")==0)
        {
            scanf("%s",client[i].information.truth);
            Yoga_count++;
        }
        else //과목 정보 입력시 적절한 정보가 입력되지 않으면 종료//
        {
            fprintf(stderr,"적절한 정보가 입력되지 않았습니다\n");
            exit(-1);
        }
    }
    printf("수강생 인원: 골프 %d명,수영 %d명, 요가 %d명\n",Golf_count,swim_count,Yoga_count);
    fastest_client_and_average(n,client,swim_count);
    minist_client_and_average(n,client,Golf_count);
    Yoga_patient(n,client,Yoga_count);
    free(client);
    return 0;
}
void fastest_client_and_average(int n,people client[],int swim_count) //가장 빠른 수영회원을 찾는 함수+수영 기록의 평균// 
{
     if(swim_count==0)
    {
        printf("수영 수강생 인원:%d\n",swim_count);
    }
    else{
    float min=client[0].information.record;
    int mini=0;
    float total=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(client[i].subject,"S")==0)
        {
            total+=client[i].information.record;
            if(min>client[i].information.record)
            {
                mini=i;
                min=client[i].information.record;
            }
        }
    }
    printf("최고 수영 실력자:%s %.1f초\n",client[mini].name,min);
    printf("수영 평균 기록:%.1f초\n",total/swim_count);
    }
}
//골프 고객중 최저 타수 기록을 가진 고객의 이름과 기록+평균타수//
void minist_client_and_average(int n,people client[],int Golf_count)
{
    if(Golf_count==0)
    {
        printf("골프 수강생 인원:%d\n",Golf_count);
    }
    else{
    int min=client[0].information.score;
    int mini=0;
    int total=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(client[i].subject,"G")==0)
        {
            total+=client[i].information.score;
            if(min>client[i].information.score)
            {
                min=client[i].information.score;
                mini=i;
            }
        }
    }
    printf("골프 최저타 기록: %s %d타\n",client[mini].name,min);
    printf("골프 평균 타수:%d타\n",total/Golf_count);
    }
}
void Yoga_patient(int n,people client[],int Yoga_count)
{
     if(Yoga_count==0)
    {
        printf("요가 수강생 인원:%d\n",Yoga_count);
    }
    else{
    int patient=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(client[i].subject,"Y")==0)
        {
            if(strcmp(client[i].information.truth,"TRUE")==0)
            {
                patient++;
            }
        }
    }
    printf("요가 척추질환 보유자:%d명\n",patient);
    }
}