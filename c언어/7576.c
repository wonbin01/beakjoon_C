#include <stdio.h>
#include <stdlib.h>
int direction[4][2]={ {1,0},{-1,0},{0,-1},{0,1} }; //상하좌우
int bfs(int **tomato, int time, int n, int m);
int main(void)
{
    int n,m;
    int time=0;
    scanf("%d %d",&m,&n); //m은 가로, n은 세로
    int **tomato=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++) //동적 메모리 할당
    {
        tomato[i]=(int *)malloc(m*sizeof(int));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf(" %d",&tomato[i][j]); //배열에 입력받는 부분
        }
    }
    // 0은 익지 않음, 1은 익음, -1은 비어있음
    return 0;
}
int bfs(int **tomato, int time, int n, int m)
{
    int queue[n*m][2];
    int front=0,rear=0;
    for(int i=0;i<n;i++) //queue에 집어넣음
    {
        for(int j=0;j<m;j++)
        {
            if(tomato[i][j]==1)
            {
                queue[rear][0]=i;
                queue[rear][1]=j;
                rear++;
            }
        }
    }
    while(rear>front)
    {
        int size=rear-front;
        for(int s=0;s<size;s++)
        {
            int cx=queue[front][0];
            int cy=queue[front][1];
            front++;
            for(int i=0;i<4;i++)
            {
                int nx=cx+direction[i][0];
                int ny=cy+direction[i][1];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&)
            }
        }
    }
}