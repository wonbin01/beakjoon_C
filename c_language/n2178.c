#include <stdio.h>
#define MAX 100

int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상, 하, 좌, 우

// BFS 함수 정의
int bfs(int startx, int starty, int visited[][MAX], int miro[][MAX], int n, int m) {
    int queue[MAX * MAX][2];
    int front = 0, rear = 0;

    queue[rear][0] = startx;
    queue[rear][1] = starty;
    rear++;
    visited[startx][starty] = 1; // 시작 지점에서의 거리

    while (front < rear) {
        int cx = queue[front][0];
        int cy = queue[front][1];
        front++;

        // 도착 지점에 도달했을 때 거리 반환
        if (cx == n - 1 && cy == m - 1) {
            return visited[cx][cy]; // 출발점에서 도착점까지의 거리 반환
        }

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = cx + direction[i][0];
            int ny = cy + direction[i][1];

            // 미로 범위 내에 있고, 길이며, 방문하지 않은 경우
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && miro[nx][ny] == 1 && visited[nx][ny] == 0) {
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                rear++;

                // 거리 갱신 (이전 거리 + 1)
                visited[nx][ny] = visited[cx][cy] + 1;
            }
        }
    }

    return -1; // 도착 지점에 도달할 수 없는 경우
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    
    char input[m + 1];
    int miro[MAX][MAX] = {0};
    int visited[MAX][MAX] = {0}; // 방문 여부 및 거리 저장 배열 초기화

    // 미로 입력 받기
    for (int i = 0; i < n; i++) {
        scanf("%s", input);
        for (int j = 0; j < m; j++) {
            miro[i][j] = input[j] - '0';
        }
    }

    // BFS 호출 및 결과 출력
    int result = bfs(0, 0, visited, miro, n, m);
    printf("%d\n", result);

    return 0;
}
