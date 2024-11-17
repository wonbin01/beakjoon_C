#include <stdio.h>
#define MAX 51
int direction[4][2]={ {1,0},{-1,0},{0,-1},{0,1}};
void carbbage(int m,int n,int k);
void dfs(int n,int m, int visited[][MAX],int bound[][MAX],int startx,int starty);
int main(void)
{
    int t; //테스트 케이스
    int m, n, k; //배추밭의 가로,세로, 위치의 개수
    scanf("%d",&t); //테스트 케이스가 주어짐
    for(int i=0;i<t;i++)
    {
        scanf("%d %d %d",&m,&n,&k);
        carbbage(m,n,k);
    }
    
    return 0;
}
void carbbage(int m,int n,int k)
{
    int visited[MAX][MAX]={0};
    int bound[MAX][MAX]={0};
    int c,r;
    int number=0;
    for(int i=0;i<k;i++) //배추의 위치 입력받음
    {
        scanf(" %d %d",&c,&r);
        bound[r][c]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(bound[i][j]==1&&visited[i][j]==0)
            {
                dfs(n,m,visited,bound,i,j);
                number++;
            }
        }
    }
    printf("%d\n",number);
}
void dfs(int n,int m, int visited[][MAX],int bound[][MAX],int startx,int starty)
{
    int stack[n*m][2];
    int top=0;
    stack[top][0]=startx;
    stack[top][1]=starty;
    visited[startx][starty]=1;
    while(top>-1)
    {
        int cx=stack[top][0];
        int cy=stack[top][1];
        top--;
        for(int i=0;i<4;i++)
        {
            int nx=cx+direction[i][0];
            int ny=cy+direction[i][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&visited[nx][ny]==0&&bound[nx][ny]==1)
            {
                top++;
                stack[top][0]=nx;
                stack[top][1]=ny;
                visited[nx][ny]=1;
            }
        }
    }
}