#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_POSITION 100000
typedef struct 
{
    int position;
    int moves;
}Node;

int minMoves(int start, int target,bool visited[]);

int main(void)
{
    int n,k=0; //n은 수빈위치, k는 동생위치
    bool visited[MAX_POSITION]={ false };
    scanf("%d %d",&n,&k); //수빈과 동생의 위치를 입력받음
    int result=minMoves(n,k,visited);
    printf("%d\n",result);
    return 0;
}
int minMoves(int start, int target,bool visited[])
{
    if(start==target)
    {
        return 0;
    }
    Node queue[100000];
    int direction[3]={-1,1,2};
    int front=0;
    int tail=0;
    queue[front].position=start;
    queue[front].moves=0;
    visited[start]=true;
    while(front<100001)
    {
    for(int i=0;i<3;i++)
    {
        int new_position;
        if(direction[i]==2)
        {
            new_position=queue[front].position*2;
        }
        else
        {
            new_position=queue[front].position+direction[i];
        }

        if(new_position>=0&&new_position<MAX_POSITION&&visited[new_position]==false)
        {
            tail++;
            visited[new_position]=true;
            queue[tail].position=new_position;
            queue[tail].moves=queue[front].moves+1;
        }
    }
    front++;
    if(queue[front].position==target)
    {
        return queue[front].moves;
    }
    }
    return -1;
}