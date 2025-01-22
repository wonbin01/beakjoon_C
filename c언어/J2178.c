#include <stdio.h>
#define MAX 100
int  direction[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int bfs(int startx,int starty,int visited[][MAX],int miro[][MAX],int n,int m);
int main(void)
{
    int n,m; //n,m�� �Է¹���
    scanf("%d %d" ,&n,&m);
    char input[m];
    int miro[MAX][MAX];
    for(int i=0;i<n;i++) //����ڷκ��� �Է¹޾Ƽ�, �̷� �ۼ�
    {
        scanf("%s",input);
        for(int j=0;j<m;j++)
        {
            miro[i][j]=input[j]-'0'; //string�� int�� ��ȯ
        }
    }
    int visited[MAX][MAX]; //visited���� �湮�ߴ��� ���� Ȯ��
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            visited[i][j]=0;
        }
    }
    int result=bfs(0,0,visited,miro,n,m);
    printf("%d\n",result);
    return 0;
}

int bfs(int startx,int starty,int visited[][MAX],int miro[][MAX],int n,int m)
{
    int queue[MAX*MAX][2];
    int front=0, rear=0;
    queue[rear][0]=startx;
    queue[rear][1]=starty; //queue�� �������
    rear++;
    visited[startx][starty]=1;

    while(front<rear)
    {
        int cx=queue[front][0];
        int cy=queue[front][1];
        front++;

        if(cx==n-1&&cy==m-1)
        {
            return visited[cx][cy];
        }

        for(int i=0;i<4;i++)
        {
            int nx=cx+direction[i][0];
            int ny=cy+direction[i][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&miro[nx][ny]==1&&visited[nx][ny]==0) //miro�� 1�̰� visited�� 0�϶�
            {
                queue[rear][0]=nx;
                queue[rear][1]=ny; //queue�� �������
                rear++;
                visited[nx][ny]=visited[cx][cy]+1;
            }
        }
    }
    return -1;
}