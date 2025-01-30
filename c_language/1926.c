#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int row;
    int col;
}Node;
int main(void)
{
    int n,k; //n은 세로, k는 가로
    scanf("%d %d",&n,&k); //세로와 가로의 크기를 입력받음
    int drawing[n][k];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            scanf("%d",&drawing[i][j]);
        }
    }
     Node **queue = (Node **)malloc(n * sizeof(Node *));  // 행 포인터 배열 할당
    
    for (int i = 0; i < n; i++) {
        queue[i] = (Node *)malloc(k * sizeof(Node));  // 각 행에 대한 Node 배열 할당
    }

    // 배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            queue[i][j].row = -1;
            queue[i][j].col = -1;
        }
    }
    int count=0;
    int visited[n][k];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            visited[i][j]=0;
        }
    }
    for(int i=0;i<n;i++) //방문한 곳이면 visited=1로 변경
    {
        for(int j=0;j<k;j++)
        {
            if(i==0&&j==0)
            {
                if(drawing[0][0]==1) //첫번째 줄,첫번째 열
                {
                    visited[0][0]=1;
                    queue[0][0].row=0;
                    queue[0][0].col=0;
                    count++;
                }
            }
            else if(i==0&&j!=0) //첫번째 줄, 가장 왼쪽이 아닐경우
            {
                if(drawing[i][j]==1)
                {
                    if(visited[i][j-1]==1) //왼쪽이 방문된 경우라면
                    {
                        for(int p=0;p<count;p++)
                        {
                            for(int q=0;queue[p][q].row!=-1;q++)
                            {
                                if(queue[p][q].col==j-1)
                                {
                                    int end=0;
                                    while(queue[p][end].row!=-1)
                                    {
                                        end++;
                                    }
                                    queue[p][end].row=i;
                                    queue[p][end].col=j;
                                    visited[i][j]=1;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        queue[count][0].row=i;
                        queue[count][0].col=j;
                        visited[i][j]=1;
                        count++;
                    }
                }
                //왼쪽 확인 -> 방문된 곳이 있으면 queue에 집어넣음, 없으면 새로운 행에 집어넣음 + visited 표시//
            }
            else if(i!=0&&j==0) //첫번째 열인 경우
            {
                if(drawing[i][j]==1)
                {
                    if(visited[i-1][j]==1) //위쪽이 방문된 경우
                    {
                        for(int p=0;p<count;p++)
                        {
                            for(int q=0;queue[p][q].row!=-1;q++)
                            {
                                if(queue[p][q].row==i-1&&queue[p][q].col==j)
                                {
                                    int end=0;
                                    while(queue[p][end].row!=-1)
                                    {
                                        end++;
                                    }
                                    queue[p][end].row=i;
                                    queue[p][end].col=j;
                                    visited[i][j]=1;
                                    break;
                                }
                            }
                        }
                    }
                    else if(drawing[i-1][j+1]==1&&drawing[i][j+1]==1)
                    {
                        for(int p=0;p<count;p++)
                        {
                            for(int q=0;queue[p][q].row!=-1;q++)
                            {
                                if(queue[p][q].row==i-1&&queue[p][q].col==j+1)
                                {
                                    int end=0;
                                    while(queue[p][end].row!=-1)
                                    {
                                        end++;
                                    }
                                    queue[p][end].row=i;
                                    queue[p][end].col=j;
                                    visited[i][j]=1;
                                    break;
                                }
                            }
                        }
                    }
                    
                    else
                    {
                        queue[count][0].row=i;
                        queue[count][0].col=j;
                        visited[i][j]=1;
                        count++;
                    }
                }
                //위쪽 확인 -> 방문된 곳이 있으면 queue에 집어넣음, 없으면 새로운 행에 집어넣음 + visited표시
            }
            else
            {
                if(drawing[i][j]==1)
                {
                    if(visited[i][j-1]==1) //왼쪽 먼저 확인
                    {
                        for(int p=0;p<count;p++)
                        {
                            for(int q=0;queue[p][q].row!=-1;q++)
                            {
                                if(queue[p][q].row==i&&queue[p][q].col==j-1)
                                {
                                    int end=0;
                                    while(queue[p][end].row!=-1)
                                    {
                                        end++;
                                    }
                                    queue[p][end].row=i;
                                    queue[p][end].col=j;
                                    visited[i][j]=1;
                                    break;
                                }
                            }
                        }
                    }
                    else if(visited[i-1][j]==1) //위쪽 확인
                    {
                        for(int p=0;p<count;p++)
                        {
                            for(int q=0;queue[p][q].row!=-1;q++)
                            {
                                if(queue[p][q].row==(i-1)&&queue[p][q].col==j)
                                {
                                    int end=0;
                                    while(queue[p][end].row!=-1)
                                    {
                                        end++;
                                    }
                                    queue[p][end].row=i;
                                    queue[p][end].col=j;
                                    visited[i][j]=1;
                                    break;   
                                }
                            }
                        }
                    }
                    else if(drawing[i-1][j+1]==1&&drawing[i][j+1]==1&&j!=k-1)
                    {
                        for(int p=0;p<count;p++)
                        {
                            for(int q=0;queue[p][q].row!=-1;q++)
                            {
                                if(queue[p][q].row==i-1&&queue[p][q].col==j+1)
                                {
                                    int end=0;
                                    while(queue[p][end].row!=-1)
                                    {
                                        end++;
                                    }
                                    queue[p][end].row=i;
                                    queue[p][end].col=j;
                                    visited[i][j]=1;
                                    break;
                                }
                            }
                        }
                    }
                    else //위쪽과 왼쪽 모두 만족하지 않을때
                    {
                        queue[count][0].row=i;
                        queue[count][0].col=j;
                        visited[i][j]=1;
                        count++; 
                    }
                }
                //위쪽, 왼쪽 확인
            }
        }
    }
    if(count==0)
    {
        printf("%d\n",0);
    }
    else
    {
        printf("%d\n",count);
    }
    int max=0;
    for(int i=0;i<count;i++)
    {
        int len=0;
        while(queue[i][len].row!=-1)
        {
            len++;
        }
        if(len>max)
        {
            max=len;
        }
    }
    printf("%d\n",max);
    return 0;
}