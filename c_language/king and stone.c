#include <stdio.h>
#include <string.h>
typedef struct location
{
    char s[3];
    int r;
    int l;
}loc;
int main(void)
{
    loc p[8];
    strcpy(p[0].s,"R");
    p[0].r=1;
    p[0].l=0;
    strcpy(p[1].s,"L");

    p[1].r=-1;
    p[1].l=0;
     strcpy(p[2].s,"B");
    p[2].r=0;
    p[2].l=-1;
     strcpy(p[3].s,"T");
    p[3].r=0;
    p[3].l=1;
     strcpy(p[4].s,"RT");
    p[4].r=1;
    p[4].l=1;
     strcpy(p[5].s,"LT");
    p[5].r=-1;
    p[5].l=1;
     strcpy(p[6].s,"RB");
    p[6].r=1;
    p[6].l=-1;
     strcpy(p[7].s,"LB");
    p[7].r=-1;
    p[7].l=-1;
    
    int ch[8][8]={0,};
    int N;
    char king[4];
    char stone[4];
    scanf("%s %s %d",&king[0],&stone[0],&N);
    ch[king[0]-'A'][king[1]-'1']=1;
    ch[stone[0]-'A'][stone[1]-'1']=1;
    for(int i=0;i<N;i++)
    {
        char a[3];
        scanf("%s",a);
        int t=strlen(a);
        a[t]='\0';
        for(int j=0;j<8;j++)
        {
            if(strcmp(a,p[j].s)==0)
            {
                if(king[0]-'A'+p[j].r>=0&&king[0]-'A'+p[j].r<=7&&king[1]-'1'+p[j].l>=0&&king[1]-'1'+p[j].l<=7)
                {
                ch[king[0]-'A'][king[1]-'1']=0;
                king[0] += p[j].r;
                king[1] += p[j].l;
                ch[king[0]-'A'][king[1]-'1']=1;

                //µ¹ÀÌ¶û ¿ÕÀÌ¶û °ãÃÆÀ» ‹š//
                if(((king[0]-'A')==(stone[0]-'A'))&&((king[1]-'1')==(stone[1]-'1')))
                {
                    if((stone[0]-'A'+p[j].r)>=0&&(stone[0]-'A'+p[j].r)<=7&&(stone[1]-'1'+p[j].l)>=0&&(stone[1]-'1'+p[j].l<=7))
                    {
                        stone[0] += p[j].r;
                        stone[1] += p[j].l;
                        ch[stone[0]-'A'][stone[1]-'1']=1;
                    }
                    else
                    {
                        king[0]-=p[j].r;
                        king[1]-=p[j].l;
                        ch[king[0]-'A'][king[1]-'1']=1;
                    }
                }
                }
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(ch[i][j]==1&&(i!=stone[0]-'A'||j!=stone[1]-'1'))
            {
                int row=i+'A';
                int col=j+1;
                printf("%c%d\n",row,col);
            }
        }
    }
   for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (ch[i][j] == 1 && (i != king[0] - 'A' || j != king[1] - '1'))
            {
                int row = i + 'A';
                int col = j + 1;
                printf("%c%d\n", row, col);
            }
        }
    }

    return 0;
}