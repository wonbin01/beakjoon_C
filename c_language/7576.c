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
    time=bfs(tomato,time,n,m);
    if(time==0||time==1) //이미 다 익은 상황
    {
        printf("%d\n",time);
    }
    else if(time>1)
    {
        printf("%d\n",time-1);
    }
    else if(time==-1)
    {
        printf("%d\n",time);
    }
    return 0;
}
int bfs(int **tomato, int time, int n, int m)
{
    int queue[n*m][2];
    int front=0,rear=0;
    int unripe=0; //익지 않은 토마토 개수
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
            else if(tomato[i][j]==0)
            {
                unripe++;
            }
        }
    }
    if(unripe==0)
    {
        return 0;
    }
    while(rear>front)
    {
        int size=rear-front;
        for(int s=0;s<size;s++)
        {
            int cx=queue[front][0];
            int cy=queue[front][1];
            front++;
            //처음부터 익어있는 경우 -0 return
            // 모두 익지 못하는 경우 - -1 return

            for(int i=0;i<4;i++)
            {
                int nx=cx+direction[i][0];
                int ny=cy+direction[i][1];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&tomato[nx][ny]==0)
                {
                    tomato[nx][ny]=1; ///토마토 익음
                    queue[rear][0]=nx;
                    queue[rear][1]=ny;
                    rear++;
                    unripe--;
                }
            }
        }
        time++; //하루지나면 시간 증가
    }
    if(unripe>0)
    {
        return -1;
    }
    return time;
}