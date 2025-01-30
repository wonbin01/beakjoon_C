#include <stdio.h>
#include <stdbool.h>

#define MAX_POSITION 100001 // 0���� 100000���� �ʿ��ϹǷ� 100001�� ����

typedef struct {
    int position;
    int moves;
} Node;

int minMoves(int start, int target, bool visited[]);

int main(void) {
    int n, k; // n�� ���� ��ġ, k�� ���� ��ġ
    bool visited[MAX_POSITION] = { false };
    scanf("%d %d", &n, &k); // ����� ������ ��ġ�� �Է¹���
    int result = minMoves(n, k, visited);
    printf("%d\n", result);
    return 0;
}

int minMoves(int start, int target, bool visited[]) {
    if (start == target) {
        return 0; // ���� ��ġ�� ��ǥ ��ġ�� ���� ���
    }

    Node queue[100000]; // ť�� ���� �迭
    int direction[3] = {-1, 1, 2}; // -1: �ڷ� 1, 1: ������ 1, 2: *2
    int front = 0; // ť�� ��
    int tail = 0; // ť�� ��

    // ť�� ���� ��ġ �߰�
    queue[tail].position = start;
    queue[tail].moves = 0;
    tail++;
    visited[start] = true; // ���� ��ġ �湮 ó��

    while (front < tail) { // ť�� ������� ���� ���
        Node current = queue[front]; // ���� ��� ��������
        front++;

        // ������ �̵�
        for (int i = 0; i < 3; i++) {
            int new_position;
            if (direction[i] == 2) {
                new_position = current.position * 2; // *2 �̵�
            } else {
                new_position = current.position + direction[i]; // -1 �Ǵ� +1 �̵�
            }

            // ��ȿ�� ��ġ���� Ȯ��
            if (new_position >= 0 && new_position < MAX_POSITION && !visited[new_position]) {
                // �湮�� ��ġ���
                visited[new_position] = true; // �湮 ó��
                queue[tail].position = new_position; // ���ο� ��ġ ť�� �߰�
                queue[tail].moves = current.moves + 1; // �̵� Ƚ�� ������Ʈ
                tail++;
            }

            // ��ǥ�� �������� ��
            if (new_position == target) {
                return current.moves + 1; // �ּ� ������ �� ��ȯ
            }
        }
    }

    return -1; // ������ �� ���� ���
}
