#include <stdio.h>
#include <stdlib.h>
int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y,int n,char **picture,int **visited);
void dfs_rg(int x,int y,int n,int **rgvisited,int **visited);
int main(void)
{
    int n;
    scanf("%d",&n); //n�� �Է¹���
    char **picture=(char **)malloc(n*sizeof(char *)); //�׸��� �����Ҵ�
    int **visited=(int **)malloc(n*sizeof(int *));
    int **rgvisited=(int **)malloc(n*sizeof(int *));
    int number=0;
    int rgnumber=0;
    for(int i=0;i<n;i++) //�׸��� �����Ҵ��ϴ� �κ�
    {
        picture[i]=(char *)malloc(n*sizeof(char));
        visited[i]=(int *)malloc(n*sizeof(int));
        rgvisited[i]=(int *)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf(" %c",&picture[i][j]); //�Է¹���
            visited[i][j]=0;
            if(picture[i][j]=='R'||picture[i][j]=='G')
            {
                rgvisited[i][j]=1; //�׸��� r�Ǵ� g�϶� 
            }
            else
            {
                rgvisited[i][j]=2;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==0) //���� �湮����  �ʾҰ�, ���ο� ���ã����
            {
                dfs(i,j,n,picture,visited);
                number++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            visited[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==0)
            {
                dfs_rg(i,j,n,rgvisited,visited);
                rgnumber++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        free(visited[i]);
        free(picture[i]);
    }
    free(visited);
    free(picture);
    printf("%d %d\n",number,rgnumber);
    return 0;
}
void dfs(int x,int y,int n,char **picture,int **visited) //�Ϲݻ���� ���� �׸�
{
    int stack[n*n][2];
    int top=-1;
    top++;
    stack[top][0]=x;
    stack[top][1]=y;
    visited[x][y]=1;
    while(top>-1)
    {
        int cx=stack[top][0];
        int cy=stack[top][1];
        top--;
        for(int i=0;i<4;i++)
        {
            int nx=cx+direction[i][0];
            int ny=cy+direction[i][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&visited[nx][ny]==0&&picture[x][y]==picture[nx][ny])
            {
                top++;
                stack[top][0]=nx;
                stack[top][1]=ny;
                visited[nx][ny]=1;
            }
        }
    }
}
void dfs_rg(int x,int y,int n,int **rgvisited,int **visited) //������ ���� �׸�
{
    int stack[n*n][2];
    int top=-1;
    top++;
    stack[top][0]=x;
    stack[top][1]=y;
    visited[x][y]=1;
    while(top>-1)
    {
        int cx=stack[top][0];
        int cy=stack[top][1];
        top--;
        for(int i=0;i<4;i++)
        {
            int nx=cx+direction[i][0];
            int ny=cy+direction[i][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&visited[nx][ny]==0&&rgvisited[nx][ny]==rgvisited[x][y])
            {
                top++;
                stack[top][0]=nx;
                stack[top][1]=ny;
                visited[nx][ny]=1;
            }
        }
    }
}