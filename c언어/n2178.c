#include <stdio.h>
#define MAX 100

int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // ��, ��, ��, ��

// BFS �Լ� ����
int bfs(int startx, int starty, int visited[][MAX], int miro[][MAX], int n, int m) {
    int queue[MAX * MAX][2];
    int front = 0, rear = 0;

    queue[rear][0] = startx;
    queue[rear][1] = starty;
    rear++;
    visited[startx][starty] = 1; // ���� ���������� �Ÿ�

    while (front < rear) {
        int cx = queue[front][0];
        int cy = queue[front][1];
        front++;

        // ���� ������ �������� �� �Ÿ� ��ȯ
        if (cx == n - 1 && cy == m - 1) {
            return visited[cx][cy]; // ��������� ������������ �Ÿ� ��ȯ
        }

        // 4���� Ž��
        for (int i = 0; i < 4; i++) {
            int nx = cx + direction[i][0];
            int ny = cy + direction[i][1];

            // �̷� ���� ���� �ְ�, ���̸�, �湮���� ���� ���
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && miro[nx][ny] == 1 && visited[nx][ny] == 0) {
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                rear++;

                // �Ÿ� ���� (���� �Ÿ� + 1)
                visited[nx][ny] = visited[cx][cy] + 1;
            }
        }
    }

    return -1; // ���� ������ ������ �� ���� ���
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    
    char input[m + 1];
    int miro[MAX][MAX] = {0};
    int visited[MAX][MAX] = {0}; // �湮 ���� �� �Ÿ� ���� �迭 �ʱ�ȭ

    // �̷� �Է� �ޱ�
    for (int i = 0; i < n; i++) {
        scanf("%s", input);
        for (int j = 0; j < m; j++) {
            miro[i][j] = input[j] - '0';
        }
    }

    // BFS ȣ�� �� ��� ���
    int result = bfs(0, 0, visited, miro, n, m);
    printf("%d\n", result);

    return 0;
}
