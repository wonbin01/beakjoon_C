#include <stdio.h>
#include <stdlib.h>
int direction[4][2]={ {1,0},{-1,0},{0,1},{0,-1} }; //�����¿�
void wallbfs(int ***dist,int **map,int n,int m,int k);
int main(void)
{
    int n,m,k; //n�� ��, m�� ��,k�� �μ� �� �ִ� ���� ��
    scanf("%d %d %d",&n,&m,&k);
    char **cmap=(char **)malloc(n*sizeof(char *));
    int **map=(int **)malloc(n*sizeof(int *));
    int ***dist=(int ***)malloc(n*sizeof(int **));
    for(int i=0;i<n;i++) //���� �Է¹��� �� ���������͸� ���
    {
        cmap[i]=(char *)malloc(m*sizeof(char));
        map[i]=(int *)malloc(m*sizeof(int));
        dist[i]=(int **)malloc(m*sizeof(int *));
        for(int j=0;j<m;j++)
        {
            dist[i][j]=(int *)malloc((k+1)*sizeof(int));
        }
    }
    for(int i=0;i<n;i++)
    {
        scanf("%s",cmap[i]);
    }
    for(int i=0;i<n;i++) //���� ����� ����
    {
        for(int j=0;j<m;j++)
        {
            map[i][j]=cmap[i][j]-'0';
            for(int w=0;w<=k;w++)
            {
                dist[i][j][w]=-1;
            }
        }
    }
    dist[0][0][0]=1;
    wallbfs(dist,map,n,m,k);
    int result=-1;
    for(int w=0;w<=k;w++)
    {
        if(dist[n-1][m-1][w]!=-1) //���������� ������ �� �ִ� ���
        {
            if(result==-1 || dist[n-1][m-1][w]<result)
            {
                result=dist[n-1][m-1][w];
            }
        }
    }
    printf("%d\n",result);
    return 0;
}
void wallbfs(int ***dist,int **map,int n,int m,int k)
{
    //bfs�˰��� ����
    int queue[n*m*(k+1)][3];
    int front=0; int rear=0;
    queue[rear][0]=0;
    queue[rear][1]=0;
    queue[rear][2]=0; //���� �μ��� �ʰ� ������
    rear++;
    while(rear>front)
    {
        int cx=queue[front][0];
        int cy=queue[front][1];
        int w=queue[front][2];
        front++;
        for(int i=0;i<4;i++)
        {
            int nx=cx+direction[i][0];
            int ny=cy+direction[i][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<m)
            {
                if(map[nx][ny]==0&&dist[nx][ny][w]==-1)
                {
                    queue[rear][0]=nx;
                    queue[rear][1]=ny;
                    queue[rear][2]=w;
                    dist[nx][ny][w]=dist[cx][cy][w]+1;
                    rear++;
                }
                else if(map[nx][ny]==1&&w<k&&dist[nx][ny][w+1]==-1)
                {
                    queue[rear][0]=nx;
                    queue[rear][1]=ny;
                    queue[rear][2]=w+1;
                    dist[nx][ny][w+1]=dist[cx][cy][w]+1;
                    rear++;
                }
            }
        }
    }
}