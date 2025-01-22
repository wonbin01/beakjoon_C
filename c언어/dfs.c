#include <stdio.h>
int count_cabbage_worms(int rows,int cols,int square[][cols]);
int main(void)
{
    int t,m,n,k;
    scanf("%d",&t);
    scanf("%d %d %d",&m,&n,&k);
    int square[n][m];
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
        square[i][j]=0;
    }
   }
   for(int i=0;i<k;i++)
   {
    int x,y;
    scanf("%d %d",&x,&y);
    square[y][x]=1;
   }
    int cnt=count_cabbage_worms(n,m,square);
    printf("%d\n",cnt);
    return 0;
}
int count_cabbage_worms(int n,int m,int square[][m])
{
    int count=0;
    int visited[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            visited[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(square[i][j]==1&&visited[i][j]==0)
            {
                count++;
            }
            if(i==0&&j==0)
            {
                if(square[i][j+1]==1)
                {
                    visited[i][j+1]=1;
                }
                if(square[i+1][j]==1)
                {
                    visited[i+1][j]=1;
                }
            }
            else if(i==0&&j>0&&j<m-1)
            {
                if(square[i][j+1]==1)
                {
                    visited[i][j+1]=1;
                }
                if(square[i][j-1]==1)
                {
                    visited[i][j-1]=1;
                }
                if(square[i+1][j]==1)
                {
                    visited[i+1][j]=1;
                }
            }
             else if(i==0&&j==m-1)
            {
                if(square[i][j-1]==1)
                {
                    visited[i][j-1]=1;
                }
                if(square[i+1][j]==1)
                {
                    visited[i+1][j]=1;
                }
            }
             else if(i>0&&j==0&&i<n-1)
            {
                if(square[i][1]==1)
                {
                    visited[i][1]=1;
                }
                if(square[i+1][0]==1)
                {
                    visited[i+1][0]=1;
                }
                if(square[i-1][0]==1)
                {
                    visited[i-1][0]=1;
                }
            }
            else if(j>0&&i>0&&j<m-1&&i<n-1)
            {
                if(square[i][j+1]==1)
                {
                    visited[i][j+1]=1;
                }
                if(square[i][j-1]==1)
                {
                    visited[i][j-1]=1;
                }
                if(square[i-1][j]==1)
                {
                    visited[i-1][j]=1;
                }
                if(square[i+1][j]==1)
                {
                    visited[i+1][j]=1;
                }
            }
            else if(i>0&&j==m-1&&i<n-1)
            {
                if(square[i-1][j]==1)
                {
                    visited[i-1][j]=1;
                }
                if(square[i][j-1]==1)
                {
                    visited[i][j-1]=1;
                }
                if(square[i+1][j]==1)
                {
                    visited[i+1][j]=1;
                }
            }
            else if(i==n-1&&j==0)
            {
                if(square[i][j+1]==1)
                {
                    visited[i][j+1]=1;
                }
                if(square[i-1][j]==1)
                {
                    visited[i-1][j]=1;
                }
            }
            else if(i==n-1&&j>0&&j<m-1)
            {
                if(square[i][j+1]==1)
                {
                    visited[i][j+1]=1;
                }
                if(square[i-1][j]==1)
                {
                    visited[i-1][j]=1;
                }
                if(square[i][j-1]==1)
                {
                    visited[i][j-1]=1;
                }
            }
            else if(i==n-1&&j==m-1)
            {
                if(square[i-1][j]==1)
                {
                    visited[i-1][j]=1;
                }
                if(square[i][j-1]==1)
                {
                    visited[i][j-1]=1;
                }
            }
        }
    }
    return count;
}