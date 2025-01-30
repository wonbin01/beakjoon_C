#include <stdio.h>
#include <stdbool.h>

#define MAX_POSITION 100001 // 0부터 100000까지 필요하므로 100001로 설정

typedef struct {
    int position;
    int moves;
} Node;

int minMoves(int start, int target, bool visited[]);

int main(void) {
    int n, k; // n은 수빈 위치, k는 동생 위치
    bool visited[MAX_POSITION] = { false };
    scanf("%d %d", &n, &k); // 수빈과 동생의 위치를 입력받음
    int result = minMoves(n, k, visited);
    printf("%d\n", result);
    return 0;
}

int minMoves(int start, int target, bool visited[]) {
    if (start == target) {
        return 0; // 시작 위치가 목표 위치와 같을 경우
    }

    Node queue[100000]; // 큐를 위한 배열
    int direction[3] = {-1, 1, 2}; // -1: 뒤로 1, 1: 앞으로 1, 2: *2
    int front = 0; // 큐의 앞
    int tail = 0; // 큐의 뒤

    // 큐에 시작 위치 추가
    queue[tail].position = start;
    queue[tail].moves = 0;
    tail++;
    visited[start] = true; // 시작 위치 방문 처리

    while (front < tail) { // 큐가 비어있지 않은 경우
        Node current = queue[front]; // 현재 노드 가져오기
        front++;

        // 가능한 이동
        for (int i = 0; i < 3; i++) {
            int new_position;
            if (direction[i] == 2) {
                new_position = current.position * 2; // *2 이동
            } else {
                new_position = current.position + direction[i]; // -1 또는 +1 이동
            }

            // 유효한 위치인지 확인
            if (new_position >= 0 && new_position < MAX_POSITION && !visited[new_position]) {
                // 방문한 위치라면
                visited[new_position] = true; // 방문 처리
                queue[tail].position = new_position; // 새로운 위치 큐에 추가
                queue[tail].moves = current.moves + 1; // 이동 횟수 업데이트
                tail++;
            }

            // 목표에 도달했을 때
            if (new_position == target) {
                return current.moves + 1; // 최소 움직임 수 반환
            }
        }
    }

    return -1; // 도달할 수 없는 경우
}
