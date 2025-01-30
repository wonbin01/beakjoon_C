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
    int element[MAX_QUEUE_SIZE+1] = { 0 }; //0�� ����ִ� ���¶�� ����//
    int select1 = 0;
    int select2 = 0;
    int waiting = 0;
    int order_number;
    printf("Ajou Ǫ���ڵ忡 ���� ���� ȯ���մϴ�. ���ϴ� ����� ������ �ּ���.\n");
    printf("1. �ֹ� 2.���� �Ϸ� 3.����\n");
    while (1)
    {
        scanf("%d", &select1);
        if (select1 == 1)
        {
            if (waiting != MAX_QUEUE_SIZE)
            {
                printf("���� ����� ���� %d���Դϴ�. ��� �ֹ��Ͻðڽ��ϱ�?\n", waiting);
                printf("1. ��� 2. ���\n");
                scanf("%d", &select2);
                if (select2 == 1) //����� ��������//
                {
                    printf("�������� ��ȣ�� �Է����ּ���\n");
                    scanf("%d", &order_number);
                    if (check_wrong(order_number, possible_order) != 0)
                    {
                        while (check_wrong(order_number, possible_order) != 0)
                        {
                            printf("�߸��� �Է��Դϴ�. �ٸ� ��ȣ�� �Է��Ͻÿ�.\n");
                            scanf("%d", &order_number);
                        }
                    } //�߸��� �ֹ���ȣ�� ��������//
                    order_number = check_number(order_number, element);//�̹� �Էµ� �ֹ���ȣ�� ��������//
                    rear=(rear+1)%(MAX_QUEUE_SIZE+1);
                    element[rear]=order_number;
                    waiting++;
                    printf("�ֹ��� �Ϸ�Ǿ����ϴ�\n");
                }
                else if(select2==2)//��Ҹ� ��������//
                {   
                }
                else
                {
                    printf("�߸��� �Է��Դϴ�.\n");
                    while(1)
                    {
                        if(select2==1)
                        {
                            break;
                        }
                        else
                        {
                            printf("�����÷��� 1���� �����ּ���...\n");
                            scanf("%d",&select2);
                        }
                    }
                }
            }
            else
            {
                printf("�ֹ��� �Ұ����մϴ�. �����մϴ�\n"); //rear==front//
            }
        }
        else if (select1 == 2) //���� �ϷḦ ��������//
        {
            if (waiting == 0)
            {
                printf("�ֹ������� �����ϴ�.\n");
            }
            else
            {
                front=(front+1)%(MAX_QUEUE_SIZE+1);
                element[front]=0;
                if (element[(front + 1) % (MAX_QUEUE_SIZE+1)] != 0)
                {
                    printf("%d�� ���� �ֹ��� ó�� ���Դϴ�.\n", element[(front + 1) % (MAX_QUEUE_SIZE+1)]);
                    waiting--;
                }
                else
                {
                    printf("�ֹ������� �����ϴ�.\n");
                    waiting=0;//������ �ο� ���� �Ϸ����� �� 0���� �ʱ�ȭ�ϴ� ���� �ʿ�(���ϸ� ��� ����ο� 1�� ǥ�õǹǷ�)//
                }
            }
        }
        else if (select1 == 3) //���Ḧ ��������//
        {
            printf("���񽺸� �����մϴ�\n");
            exit(0);
        }
        else
        {
            printf("�߸��Է��ϼ̽��ϴ�\n");
        }
        printf("*-*-*-*-*-*-*-*\n");
        printf("Ajou Ǫ���ڵ忡 ���� ���� ȯ���մϴ�. ���ϴ� ����� ������ �ּ���.\n");
        printf("1. �ֹ� 2. ���� �Ϸ� 3. ����\n");
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
            printf("�̹� �Էµ� ��ȣ�Դϴ�. �ٸ� ��ȣ�� �Է��Ͻÿ�\n"); //���Ŀ� �̻��� ��ȣ�� �Է������� ������ ����ϴ� ������ �ʿ�//
            scanf("%d", &order_number);
            while(1)
            {
            count=check_wrong(order_number,possible_order);
            if(count==1)
            {
                printf("�߸��� �Է��Դϴ�. �ٸ� ��ȣ�� �Է��Ͻÿ�.\n");
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