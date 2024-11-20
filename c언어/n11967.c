#include <stdio.h>
#include <stdlib.h>

int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};  // 상, 하, 좌, 우

typedef struct Element {
    int r;
    int c;
    struct Element *next;
} Element;

void bfs(int n, int **turn, Element **light, int *count, int **visited);

int main(void) {
    int n, m;
    int count = 1;  // (0, 0)에서 이미 불이 켜져 있음
    scanf("%d %d", &n, &m);  // n은 헛간의 크기, m은 몇 번 입력받을 건지
    int x, y, a, b;  // (x, y) 방에서 (a, b) 방의 불을 킬 수 있음

    Element **light = (Element **)malloc(n * sizeof(Element *));  // 불이 켜져 있는 방을 나타냄
    for (int i = 0; i < n; i++) {
        light[i] = (Element *)malloc(n * sizeof(Element));
        for (int j = 0; j < n; j++) {
            light[i][j].r = i;
            light[i][j].c = j;
            light[i][j].next = NULL;
        }
    }

    // 입력받아서 불을 켤 수 있는 방 연결
    for (int t = 0; t < m; t++) {
        scanf(" %d %d %d %d", &x, &y, &a, &b);
        x = x - 1;
        y = y - 1;
        a = a - 1;
        b = b - 1;

        Element *newedge = (Element *)malloc(sizeof(Element));
        newedge->r = a;
        newedge->c = b;
        newedge->next = NULL;

        // 연결 리스트에 방 추가
        if (light[x][y].next == NULL) {
            light[x][y].next = newedge;
        } else {
            Element *current = light[x][y].next;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newedge;
        }
    }

    // 방문 처리와 불이 켜져 있는 방 초기화
    int **visited = (int **)malloc(n * sizeof(int *));  // 방문된 곳 나타내는 배열
    int **turn = (int **)malloc(n * sizeof(int *));  // 불 켜져 있는 곳 나타내는 배열
    for (int i = 0; i < n; i++) {
        visited[i] = (int *)malloc(n * sizeof(int));
        turn[i] = (int *)malloc(n * sizeof(int));
    }

    // 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            turn[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    turn[0][0] = 1;  // (0, 0)에서 불이 켜져 있음
    visited[0][0] = 1;  // (0, 0) 방문 처리
    count = 1;  // (0, 0)도 카운트에 포함

    // 한 번 BFS 실행
    bfs(n, turn, light, &count, visited);

    // 불이 켜져 있는 방이 더 있다면 BFS를 다시 실행
    int moreLights = 1;
    while (moreLights) {
        moreLights = 0;
        // 불이 켜져있는 방이 있을 때 다시 BFS를 시도
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (turn[i][j] == 1 && visited[i][j] == 0) {
                    // 불이 켜져 있고 방문되지 않았다면 BFS 실행
                    moreLights = 1;
                    bfs(n, turn, light, &count, visited);
                    break;
                }
            }
            if (moreLights) break;
        }
    }

    printf("%d\n", count);  // 불을 킬 수 있는 방의 개수 출력

    return 0;
}

void bfs(int n, int **turn, Element **light, int *count, int **visited) {
    int queue[n * n][2];  // 큐를 위한 배열
    int front = 0;
    int rear = 0;

    queue[rear][0] = 0;  // 시작 지점 (0, 0)
    queue[rear][1] = 0;
    rear++;

    // BFS 탐색 시작
    while (rear > front) {
        int cx = queue[front][0];
        int cy = queue[front][1];
        front++;

        // 현재 방에서 불을 킬 수 있는 방 탐색
        Element *current = light[cx][cy].next;
        while (current != NULL) {
            if (turn[current->r][current->c] == 0) {  // 아직 불이 켜지지 않은 방
                turn[current->r][current->c] = 1;  // 불을 킴
                (*count)++;  // 불을 켠 방의 수 증가
            }
            current = current->next;
        }

        // 연결된 방으로 이동
        for (int i = 0; i < 4; i++) {
            int nx = cx + direction[i][0];
            int ny = cy + direction[i][1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && turn[nx][ny] == 1 && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;  // 방문 처리
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                rear++;
            }
        }
    }
}
