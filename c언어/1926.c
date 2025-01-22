#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int row;
    int col;
}Node;
int main(void)
{
    int n,k; //n�� ����, k�� ����
    scanf("%d %d",&n,&k); //���ο� ������ ũ�⸦ �Է¹���
    int drawing[n][k];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            scanf("%d",&drawing[i][j]);
        }
    }
     Node **queue = (Node **)malloc(n * sizeof(Node *));  // �� ������ �迭 �Ҵ�
    
    for (int i = 0; i < n; i++) {
        queue[i] = (Node *)malloc(k * sizeof(Node));  // �� �࿡ ���� Node �迭 �Ҵ�
    }

    // �迭 �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            queue[i][j].row = -1;
            queue[i][j].col = -1;
        }
    }
    int count=0;
    int visited[n][k];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            visited[i][j]=0;
        }
    }
    for(int i=0;i<n;i++) //�湮�� ���̸� visited=1�� ����
    {
        for(int j=0;j<k;j++)
        {
            if(i==0&&j==0)
            {
                if(drawing[0][0]==1) //ù��° ��,ù��° ��
                {
                    visited[0][0]=1;
                    queue[0][0].row=0;
                    queue[0][0].col=0;
                    count++;
                }
            }
            else if(i==0&&j!=0) //ù��° ��, ���� ������ �ƴҰ��
            {
                if(drawing[i][j]==1)
                {
                    if(visited[i][j-1]==1) //������ �湮�� �����
                    {
                        for(int p=0;p<count;p++)
                        {
                            for(int q=0;queue[p][q].row!=-1;q++)
                            {
                                if(queue[p][q].col==j-1)
                                {
                                    int end=0;
                                    while(queue[p][end].row!=-1)
                                    {
                                        end++;
                                    }
                                    queue[p][end].row=i;
                                    queue[p][end].col=j;
                                    visited[i][j]=1;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        queue[count][0].row=i;
                        queue[count][0].col=j;
                        visited[i][j]=1;
                        count++;
                    }
                }
                //���� Ȯ�� -> �湮�� ���� ������ queue�� �������, ������ ���ο� �࿡ ������� + visited ǥ��//
            }
            else if(i!=0&&j==0) //ù��° ���� ���
            {
                if(drawing[i][j]==1)
                {
                    if(visited[i-1][j]==1) //������ �湮�� ���
                    {
                        for(int p=0;p<count;p++)
                        {
                            for(int q=0;queue[p][q].row!=-1;q++)
                            {
                                if(queue[p][q].row==i-1&&queue[p][q].col==j)
                                {
                                    int end=0;
                                    while(queue[p][end].row!=-1)
                                    {
                                        end++;
                                    }
                                    queue[p][end].row=i;
                                    queue[p][end].col=j;
                                    visited[i][j]=1;
                                    break;
                                }
                            }
                        }
                    }
                    else if(drawing[i-1][j+1]==1&&drawing[i][j+1]==1)
                    {
                        for(int p=0;p<count;p++)
                        {
                            for(int q=0;queue[p][q].row!=-1;q++)
                            {
                                if(queue[p][q].row==i-1&&queue[p][q].col==j+1)
                                {
                                    int end=0;
                                    while(queue[p][end].row!=-1)
                                    {
                                        end++;
                                    }
                                    queue[p][end].row=i;
                                    queue[p][end].col=j;
                                    visited[i][j]=1;
                                    break;
                                }
                            }
                        }
                    }
                    
                    else
                    {
                        queue[count][0].row=i;
                        queue[count][0].col=j;
                        visited[i][j]=1;
                        count++;
                    }
                }
                //���� Ȯ�� -> �湮�� ���� ������ queue�� �������, ������ ���ο� �࿡ ������� + visitedǥ��
            }
            else
            {
                if(drawing[i][j]==1)
                {
                    if(visited[i][j-1]==1) //���� ���� Ȯ��
                    {
                        for(int p=0;p<count;p++)
                        {
                            for(int q=0;queue[p][q].row!=-1;q++)
                            {
                                if(queue[p][q].row==i&&queue[p][q].col==j-1)
                                {
                                    int end=0;
                                    while(queue[p][end].row!=-1)
                                    {
                                        end++;
                                    }
                                    queue[p][end].row=i;
                                    queue[p][end].col=j;
                                    visited[i][j]=1;
                                    break;
                                }
                            }
                        }
                    }
                    else if(visited[i-1][j]==1) //���� Ȯ��
                    {
                        for(int p=0;p<count;p++)
                        {
                            for(int q=0;queue[p][q].row!=-1;q++)
                            {
                                if(queue[p][q].row==(i-1)&&queue[p][q].col==j)
                                {
                                    int end=0;
                                    while(queue[p][end].row!=-1)
                                    {
                                        end++;
                                    }
                                    queue[p][end].row=i;
                                    queue[p][end].col=j;
                                    visited[i][j]=1;
                                    break;   
                                }
                            }
                        }
                    }
                    else if(drawing[i-1][j+1]==1&&drawing[i][j+1]==1&&j!=k-1)
                    {
                        for(int p=0;p<count;p++)
                        {
                            for(int q=0;queue[p][q].row!=-1;q++)
                            {
                                if(queue[p][q].row==i-1&&queue[p][q].col==j+1)
                                {
                                    int end=0;
                                    while(queue[p][end].row!=-1)
                                    {
                                        end++;
                                    }
                                    queue[p][end].row=i;
                                    queue[p][end].col=j;
                                    visited[i][j]=1;
                                    break;
                                }
                            }
                        }
                    }
                    else //���ʰ� ���� ��� �������� ������
                    {
                        queue[count][0].row=i;
                        queue[count][0].col=j;
                        visited[i][j]=1;
                        count++; 
                    }
                }
                //����, ���� Ȯ��
            }
        }
    }
    if(count==0)
    {
        printf("%d\n",0);
    }
    else
    {
        printf("%d\n",count);
    }
    int max=0;
    for(int i=0;i<count;i++)
    {
        int len=0;
        while(queue[i][len].row!=-1)
        {
            len++;
        }
        if(len>max)
        {
            max=len;
        }
    }
    printf("%d\n",max);
    return 0;
}