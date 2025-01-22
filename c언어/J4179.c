#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
int direction[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

void firemoving(int r, int c, int **visited, int firequeue[][2], int *firefront, int *firerear);
int escapeTime(int r, int c, int **visited, int firequeue[][2], int *firefront, int *firerear);

int main(void)
{
    int r, c; // �̷��� row, col
    scanf("%d %d", &r, &c);

    char maze[MAX][MAX];
    int firequeue[r * c][2];
    int firefront = 0, firerear = 0;

    // ���� �޸� �Ҵ�
    int **visited = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        visited[i] = (int *)malloc(c * sizeof(int));
    }

    // �̷� �Է� �ޱ�
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf(" %c", &maze[i][j]);
            if (maze[i][j] == '#')
                visited[i][j] = 1; // ��
            else if (maze[i][j] == 'F')
            {
                visited[i][j] = 2; // ��
                firequeue[firerear][0] = i;
                firequeue[firerear][1] = j;
                firerear++;
            }
            else if (maze[i][j] == 'J')
            {
                visited[i][j] = 3; // ���
            }
            else
                visited[i][j] = 0; // �� ����
        }
    }

    int time = escapeTime(r, c, visited, firequeue, &firefront, &firerear);
    if (time != -1)
        printf("%d\n", time);
    else
        printf("IMPOSSIBLE\n");

    // ���� �޸� ����
    for (int i = 0; i < r; i++)
    {
        free(visited[i]);
    }
    free(visited);

    return 0;
}

int escapeTime(int r, int c, int **visited, int firequeue[][2], int *firefront, int *firerear)
{
    int front = 0, rear = 0;
    int queue[r * c][2];
    int time = 0;

    // �ʱ� ��ġ ť�� �ֱ�
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (visited[i][j] == 3) // ����� �ִ� ��ġ
            {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
        }
    }

    while (front < rear)
    {
        int size = rear - front;
        firemoving(r, c, visited, firequeue, firefront, firerear); // �� �̵�

        for (int s = 0; s < size; s++)
        {
            int cx = queue[front][0];
            int cy = queue[front][1];
            front++;

            if (cx == 0 || cx == r - 1 || cy == 0 || cy == c - 1)
                return time + 1;

            for (int i = 0; i < 4; i++)
            {
                int nx = cx + direction[i][0];
                int ny = cy + direction[i][1];

                if (nx >= 0 && nx < r && ny >= 0 && ny < c && visited[nx][ny] == 0)
                {
                    visited[nx][ny] = 3; // �湮 üũ
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                }
            }
        }
        time++;
    }
    return -1;
}

void firemoving(int r, int c, int **visited, int firequeue[][2], int *firefront, int *firerear)
{
    int size = *firerear - *firefront;
    for (int i = 0; i < size; i++)
    {
        int cx = firequeue[*firefront][0];
        int cy = firequeue[*firefront][1];
        (*firefront)++;

        for (int j = 0; j < 4; j++)
        {
            int nx = cx + direction[j][0];
            int ny = cy + direction[j][1];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c && visited[nx][ny] == 0)
            {
                visited[nx][ny] = 2;
                firequeue[*firerear][0] = nx;
                firequeue[*firerear][1] = ny;
                (*firerear)++;
            }
        }
    }
}
