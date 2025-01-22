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
        fprintf(stderr,"�޸� �Ҵ� ����\n");
        exit(-1);
    } 
    printf("�� ������ �Է����ּ���\n");
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
        else //���� ���� �Է½� ������ ������ �Էµ��� ������ ����//
        {
            fprintf(stderr,"������ ������ �Էµ��� �ʾҽ��ϴ�\n");
            exit(-1);
        }
    }
    printf("������ �ο�: ���� %d��,���� %d��, �䰡 %d��\n",Golf_count,swim_count,Yoga_count);
    fastest_client_and_average(n,client,swim_count);
    minist_client_and_average(n,client,Golf_count);
    Yoga_patient(n,client,Yoga_count);
    free(client);
    return 0;
}
void fastest_client_and_average(int n,people client[],int swim_count) //���� ���� ����ȸ���� ã�� �Լ�+���� ����� ���// 
{
     if(swim_count==0)
    {
        printf("���� ������ �ο�:%d\n",swim_count);
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
    printf("�ְ� ���� �Ƿ���:%s %.1f��\n",client[mini].name,min);
    printf("���� ��� ���:%.1f��\n",total/swim_count);
    }
}
//���� ���� ���� Ÿ�� ����� ���� ���� �̸��� ���+���Ÿ��//
void minist_client_and_average(int n,people client[],int Golf_count)
{
    if(Golf_count==0)
    {
        printf("���� ������ �ο�:%d\n",Golf_count);
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
    printf("���� ����Ÿ ���: %s %dŸ\n",client[mini].name,min);
    printf("���� ��� Ÿ��:%dŸ\n",total/Golf_count);
    }
}
void Yoga_patient(int n,people client[],int Yoga_count)
{
     if(Yoga_count==0)
    {
        printf("�䰡 ������ �ο�:%d\n",Yoga_count);
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
    printf("�䰡 ô����ȯ ������:%d��\n",patient);
    }
}