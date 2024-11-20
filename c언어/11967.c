#include <stdio.h>
#include <stdlib.h>
int direction[4][2]={ {1,0},{-1,0},{0,1},{0,-1} };
typedef struct Element 
{
    int r;
    int c;
    struct Element *next;
}Element;
void bfs(int n,int **turn,Element **light,int *count,int **visited);
int main(void)
{
    int n,m;
    int count=1;
    scanf("%d %d",&n,&m); //n은 헛간의 크기, m은 몇번 입력받을건지
    int x,y,a,b; //(x,y방에서 (a,b)방의 불을 킬 수 있음)
    Element **light=(Element **)malloc(n*sizeof(Element *)); //불이 켜져있는 방을 나타냄
    for(int i=0;i<n;i++)
    {
        light[i]=(Element *)malloc(n*sizeof(Element));
        for(int j=0;j<n;j++)
        {
            light[i][j].r=i;
            light[i][j].c=j;
            light[i][j].next=NULL;
        }
    }
    for(int t=0;t<m;t++)
    {
        scanf(" %d %d %d %d", &x,&y,&a,&b);
        x=x-1;y=y-1;a=a-1;b=b-1;
        Element *newedge=(Element *)malloc(sizeof(Element));
        newedge->r=a;
        newedge->c=b;
        newedge->next=NULL;
        if(light[x][y].next==NULL)
        {
            light[x][y].next=newedge;
        }
        else
        {
            Element *current=light[x][y].next;
            while(current->next!=NULL)
            {
                current=current->next;
            }
            current->next=newedge;
        }
    }
    int **visited=(int **)malloc(n*sizeof(int *)); //방문된곳 나타내는 배열
    int **turn=(int **)malloc(n*sizeof(int *)); //불켜져있는 곳 나타내는 배열
    for(int i=0;i<n;i++)
    {
        visited[i]=(int *)malloc(n*sizeof(int));
        turn[i]=(int *)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            turn[i][j]=0;
            visited[i][j]=0;
        }
    }
    turn[0][0]=1;
    bfs(n,turn,light,&count,visited); // 첫번째, bfs 실행
    int second=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(turn[i][j]==1&&visited[i][j]==0) //켜져있는데 ,방문되지 않은경우
            {
                
            }
        }
    }
    bfs(n,turn,light,&second,visited);
    printf("%d\n",count+second);
    return 0;
}
void bfs(int n,int **turn,Element **light,int *count,int **visited)
{
    int queue[n*n][2];
    int front=0;
    int rear=0;
    queue[rear][0]=0;
    queue[rear][1]=0;
    rear++;
    while(rear>front)
    {
        int cx=queue[front][0];
        int cy=queue[front][1];
        front++;
        Element *current=light[cx][cy].next;
        while(current!=NULL)
        {
            if(turn[current->r][current->c]==0)
            {
                turn[current->r][current->c]=1;
                (*count)++;
            }
            current=current->next;
        }
        for(int i=0;i<4;i++)
        {
            int nx=cx+direction[i][0];
            int ny=cy+direction[i][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&turn[nx][ny]==1&&visited[nx][ny]==0)
            {
                visited[nx][ny]=1;
                queue[rear][0]=nx;
                queue[rear][1]=ny;
                rear++;
            }
        }
    }
}