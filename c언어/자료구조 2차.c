#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
int rear = 0;
int front = 0;
int possible_order[MAX_QUEUE_SIZE] = { 101,102,103,104,105 };
int check_number(int order_number, int element[]);
int check_wrong(int order_number, int possible_order[]);
int main(void)
{
    int element[MAX_QUEUE_SIZE+1] = { 0 }; //0은 비어있는 상태라고 가정//
    int select1 = 0;
    int select2 = 0;
    int waiting = 0;
    int order_number;
    printf("Ajou 푸드코드에 오신 것을 환영합니다. 원하는 기능을 선택해 주세요.\n");
    printf("1. 주문 2.서빙 완료 3.종료\n");
    while (1)
    {
        scanf("%d", &select1);
        if (select1 == 1)
        {
            if (waiting != MAX_QUEUE_SIZE)
            {
                printf("현재 대기자 수는 %d명입니다. 계속 주문하시겠습니까?\n", waiting);
                printf("1. 계속 2. 취소\n");
                scanf("%d", &select2);
                if (select2 == 1) //계속을 눌렀을때//
                {
                    printf("진동벨의 번호를 입력해주세요\n");
                    scanf("%d", &order_number);
                    if (check_wrong(order_number, possible_order) != 0)
                    {
                        while (check_wrong(order_number, possible_order) != 0)
                        {
                            printf("잘못된 입력입니다. 다른 번호를 입력하시오.\n");
                            scanf("%d", &order_number);
                        }
                    } //잘못된 주문번호를 눌렀을때//
                    order_number = check_number(order_number, element);//이미 입력된 주문번호를 눌렀을때//
                    rear=(rear+1)%(MAX_QUEUE_SIZE+1);
                    element[rear]=order_number;
                    waiting++;
                    printf("주문이 완료되었습니다\n");
                }
                else if(select2==2)//취소를 눌렀을때//
                {   
                }
                else
                {
                    printf("잘못된 입력입니다.\n");
                    while(1)
                    {
                        if(select2==1)
                        {
                            break;
                        }
                        else
                        {
                            printf("나가시려면 1번을 눌러주세요...\n");
                            scanf("%d",&select2);
                        }
                    }
                }
            }
            else
            {
                printf("주문이 불가능합니다. 감사합니다\n"); //rear==front//
            }
        }
        else if (select1 == 2) //서빙 완료를 눌렀을때//
        {
            if (waiting == 0)
            {
                printf("주문내역이 없습니다.\n");
            }
            else
            {
                front=(front+1)%(MAX_QUEUE_SIZE+1);
                element[front]=0;
                if (element[(front + 1) % (MAX_QUEUE_SIZE+1)] != 0)
                {
                    printf("%d번 님의 주문을 처리 중입니다.\n", element[(front + 1) % (MAX_QUEUE_SIZE+1)]);
                    waiting--;
                }
                else
                {
                    printf("주문내역이 없습니다.\n");
                    waiting=0;//마지막 인원 서빙 완료했을 때 0으로 초기화하는 과정 필요(안하면 계속 대기인원 1로 표시되므로)//
                }
            }
        }
        else if (select1 == 3) //종료를 눌렀을때//
        {
            printf("서비스를 종료합니다\n");
            exit(0);
        }
        else
        {
            printf("잘못입력하셨습니다\n");
        }
        printf("*-*-*-*-*-*-*-*\n");
        printf("Ajou 푸드코드에 오신 것을 환영합니다. 원하는 기능을 선택해 주세요.\n");
        printf("1. 주문 2. 서빙 완료 3. 종료\n");
    }
    return 0;
}
int check_number(int order_number, int element[])
{
    int count=0;
    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        if (order_number == element[i])
        {
            printf("이미 입력된 번호입니다. 다른 번호를 입력하시오\n"); //이후에 이상한 번호를 입력했을때 오류를 출력하는 과정이 필요//
            scanf("%d", &order_number);
            while(1)
            {
            count=check_wrong(order_number,possible_order);
            if(count==1)
            {
                printf("잘못된 입력입니다. 다른 번호를 입력하시오.\n");
                scanf("%d",&order_number);
            }
            else
            {
                break;
            }
            }
            return check_number(order_number, element);
            
        }
    }
    return order_number;
}
int check_wrong(int order_number, int possible_order[])
{
    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        if (order_number == possible_order[i])
        {
            return 0;
        }
    }
    return 1;
}