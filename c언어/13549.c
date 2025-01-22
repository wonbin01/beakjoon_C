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
    int n,k; //n은 수빈위치, k는 동생위치
    scanf("%d %d",&n,&k); //걷는다면 x-1||x+1(1초), 순간이동한다면 2x위치로 이동(순간이동은 0초)
    location subin;
    subin.loc=n; subin.time=0; //수빈의 위치와 걸린 시간을 저장
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
    int visited[100001]; //각 위치에 도달한 최소 시간을 저장
    for(int i=0;i<100001;i++)
    {
        visited[i]=MAX;
    }
    int rear=0; int front=0;
    queue[rear][0]=subin.loc;
    queue[rear][1]=subin.time; //queue에 subin의 정보 넣음
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