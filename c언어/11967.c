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
void initializevisied(int n,int **visited);
int main(void)
{
    int n,m;
    int count=1;
    scanf("%d %d",&n,&m); //n�� �갣�� ũ��, m�� ��� �Է¹�������
    int x,y,a,b; //(x,y�濡�� (a,b)���� ���� ų �� ����)
    Element **light=(Element **)malloc(n*sizeof(Element *)); //���� �����ִ� ���� ��Ÿ��
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
    int **visited=(int **)malloc(n*sizeof(int *)); //�湮�Ȱ� ��Ÿ���� �迭
    int **turn=(int **)malloc(n*sizeof(int *)); //�������ִ� �� ��Ÿ���� �迭
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
    visited[0][0]=1;
    for(int i=0;i<n*n;i++)
    {
        bfs(n,turn,light,&count,visited);
        int update=count;
        initializevisied(n,visited);
        bfs(n,turn,light,&count,visited);
        if(count==update)
        {
            printf("%d\n",count);
            break;
        }
    }
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
void initializevisied(int n,int **visited)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            visited[i][j]=0;
        }
    }
    visited[0][0]=1;
}