#include <stdio.h>
#include <stdbool.h>
#define MAX 100000
int direction[3]={-1,1,2};
typedef struct location
{
    int loc;
    int time;
}location;
int minimizetime(location subin,int k);
int main(void)
{
    int n,k; //n�� ������ġ, k�� ������ġ
    scanf("%d %d",&n,&k); //�ȴ´ٸ� x-1||x+1(1��), �����̵��Ѵٸ� 2x��ġ�� �̵�(�����̵��� 0��)
    location subin;
    subin.loc=n; subin.time=0; //������ ��ġ�� �ɸ� �ð��� ����
    int time;
    if(n>=k)
    {
        time=n-k;
    }
    else
    {
        time=minimizetime(subin,k);
    }
    printf("%d\n",time);
    return 0;
}
int minimizetime(location subin,int k)
{
    int queue[100001][2];
    int visited[100001]; //�� ��ġ�� ������ �ּ� �ð��� ����
    for(int i=0;i<100001;i++)
    {
        visited[i]=MAX;
    }
    int rear=0; int front=0;
    queue[rear][0]=subin.loc;
    queue[rear][1]=subin.time; //queue�� subin�� ���� ����
    visited[subin.loc]=0;
    rear++;
    while(rear>front)
    {
        int loc=queue[front][0];
        int time=visited[loc];
        front++;
        if(loc==k)
        {
            return time;
        }
        for(int i=0;i<3;i++)
        {
            int nx;
            int new_time;
            if(i<2)
            {
                nx=loc+direction[i];
                new_time=time+1;
            }
            else
            {
                nx=loc*2;
                new_time=time;
            }
            if(nx>=0&&nx<=100000&&new_time<visited[nx])
            {
                visited[nx]=new_time;
                queue[rear][0]=nx;
                queue[rear][1]=new_time;
                rear++;
            }
        }
    }
        return -1;
}