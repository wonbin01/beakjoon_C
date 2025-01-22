#include <stdio.h>
#include <stdlib.h>
int direction[4][2]={ {1,0},{-1,0},{0,-1},{0,1} }; //�����¿�
int bfs(int **tomato, int time, int n, int m);
int main(void)
{
    int n,m;
    int time=0;
    scanf("%d %d",&m,&n); //m�� ����, n�� ����
    int **tomato=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++) //���� �޸� �Ҵ�
    {
        tomato[i]=(int *)malloc(m*sizeof(int));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf(" %d",&tomato[i][j]); //�迭�� �Է¹޴� �κ�
        }
    }
    time=bfs(tomato,time,n,m);
    if(time==0||time==1) //�̹� �� ���� ��Ȳ
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
    int unripe=0; //���� ���� �丶�� ����
    for(int i=0;i<n;i++) //queue�� �������
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
            //ó������ �;��ִ� ��� -0 return
            // ��� ���� ���ϴ� ��� - -1 return

            for(int i=0;i<4;i++)
            {
                int nx=cx+direction[i][0];
                int ny=cy+direction[i][1];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&tomato[nx][ny]==0)
                {
                    tomato[nx][ny]=1; ///�丶�� ����
                    queue[rear][0]=nx;
                    queue[rear][1]=ny;
                    rear++;
                    unripe--;
                }
            }
        }
        time++; //�Ϸ������� �ð� ����
    }
    if(unripe>0)
    {
        return -1;
    }
    return time;
}