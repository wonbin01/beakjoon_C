#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

int rear = -1;
int front = -1;
int possible_order[MAX_QUEUE_SIZE] = {101, 102, 103, 104, 105};

int check_number(int order_number, int element[]);
int check_wrong(int order_number, int possible_order[]);

int main(void) {
    int element[MAX_QUEUE_SIZE] = {0};
    int select1 = 0;
    int select2 = 0;
    int waiting = 0;
    int order_number;

    printf("Ajou ????? ?? ?? ?????. ??? ??? ??? ???.\n");
    printf("1. ?? 2. ?? ?? 3. ??\n");

    while (1) {
        scanf("%d", &select1);

        if (select1 == 1) {
            printf("?? ??? ?? %d????. ?? ?????????\n", waiting);
            printf("1. ?? 2. ??\n");
            scanf("%d", &select2);

            if (select2 == 1) {
                if (waiting <= 4) {
                    printf("???? ??? ??????\n");
                    scanf("%d", &order_number);

                    if (check_wrong(order_number, possible_order) != 0) {
                        continue;
                    }

                    order_number = check_number(order_number, element);

                    if (rear == -1) {
                        front = rear = 0;
                    } else {
                        rear = (rear + 1) % MAX_QUEUE_SIZE;
                    }
                    
                    element[rear] = order_number;
                    waiting++;
                    printf("??? ???????\n");
                } else {
                    printf("??? ??????.\n");
                }
            }
        } else if (select1 == 2) {
            if (waiting == 0) {
                printf("????? ????.\n");
            } else {
                printf("%d? ?? ??? ?? ????.\n", element[front]);
                element[front] = 0;
                front = (front + 1) % MAX_QUEUE_SIZE;
                waiting--;
            }
        } else if (select1 == 3) {
            printf("???? ?????\n");
            exit(0);
        } else {
            printf("?????????\n");
        }

        printf("Ajou ????? ?? ?? ?????. ??? ??? ??? ???.\n");
        printf("1. ?? 2. ?? ?? 3. ??\n");
    }

    return 0;
}

int check_number(int order_number, int element[]) {
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        if (order_number == element[i]) {
            printf("?? ??? ?????. ?? ??? ?????\n");
            scanf("%d", &order_number);
            return check_number(order_number, element);
        }
    }
    return order_number;
}

int check_wrong(int order_number, int possible_order[]) {
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        if (order_number == possible_order[i]) {
            return 0; // Valid order number
        }
    }
    printf("??? ?????. ?? ??? ?????.\n");
    return 1; // Invalid order number
}
