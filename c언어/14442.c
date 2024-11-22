#include <stdio.h>
int direction[4][2]={ {1,0},{-1,0},{0,1},{0,-1} }; //상하좌우
int main(void)
{
    int n,m,k; //n은 행, m은 열,k는 부술 수 있는 벽의 수
    scanf("%d %d %d",&n,&m,&k);
    char **cmap=(char **)malloc(n*sizeof(char *));
    int **map=(int **)malloc(n*sizeof(int *));
    int wall[n*m][2]; //벽의 위치를 저장하는 배열
    int wallcount=0;
    for(int i=0;i<n;i++) //맵을 입력받을 떄 이중포인터를 사용
    {
        cmap[i]=(char *)malloc(m*sizeof(char));
        map[i]=(int *)malloc(m*sizeof(int));
    }
    for(int i=0;i<n;i++)
    {
        scanf("%s",cmap[i]);
    }
    for(int i=0;i<n;i++) //맵을 만드는 과정
    {
        for(int j=0;j<m;j++)
        {
            map[i][j]=cmap[i][j]-'0';
            if(map[i][j]==1)
            {
                wall[wallcount][0]=i; //벽의 위치를 저장함
                wall[wallcount][1]=j;
                wallcount++;   
            }
        }
    }
    
//k개의 벽을 먼저 부숨-> bfs실행 -> 이동횟수 배열에 저장 -> map원상복구 -> 다른 벽 부수기 실행

    //0은 이동가능, 1은 이동불가능 k개의 벽을 부술 수 있음-> 1,1에서 n,m까지 이동
    int count=1; //시작하는 칸 생각(1,1)
    return 0;
}