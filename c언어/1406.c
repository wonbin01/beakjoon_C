#include <stdio.h>
#include <string.h>
char sentence[600001];
int nex[600001]={-3};
int pre[600001]={-3};
void insert(int *cursor,char new,int *m);
void erase(int *cursor,int *m);
int main(void)
{
       int cursor;
       scanf("%s",&sentence[0]); //¹®ÀÚ¿­À» ÀÔ·Â¹Þ´Â °úÁ¤
       int m=strlen(sentence);
       int len=m; 
       cursor=m;
       pre[0]=-1;
       for(int i=0;i<m-1;i++) //nex¿Í pre¹è¿­À» Á¤¸®ÇÏ´Â °úÁ¤//
       {
        nex[i]=i+1;
        pre[i+1]=i;
       }
       nex[m-1]=-1;
       int n;
       scanf("%d",&n); //¸î¹ø ¹Ýº¹ÇÒ Áö ÀÔ·Â¹Þ´Â ºÎºÐ//
       for(int i=0;i<n;i++)
       {
        char change,new;
        scanf(" %c",&change);
        if(change=='P') //¿ÞÂÊ¿¡ ¹®ÀÚ Ãß°¡
        {
            scanf(" %c",&new);
            insert(&cursor,new,&m);
            len++;
        }
        else if(change=='L') //Ä¿¼­¸¦ ¿ÞÂÊÀ¸·Î ¿Å±è
        {
            int current;
            for(int i=0;i<m;i++)
            {
                if(nex[cursor]==-1)
                {
                    current=i;
                    break;
                }
            }
            if(nex[cursor]==-3)
            {
                cursor=current;
            }
            else if(pre[cursor]!=-1)
            {
                cursor=pre[cursor];
            }
        }
        else if(change=='B') //Ä¿¼­ÀÇ ¿ÞÂÊºÎºÐÀ» »èÁ¦
        {
            erase(&cursor,&m);
            len--;
        }
        else if(change=='D') //Ä¿¼­¸¦ ¿À¸¥ÂÊÀ¸·Î ¿Å±è
        {
            if(nex[cursor]!=-1)
            {
                cursor=nex[cursor];
            }
        }
       }
       int start;
       for(int i=0;i<m;i++)
       {
        if(pre[i]==-1)
        {
            start=i;
        }
       }
       for(int i=0;i<len;i++)
       {
        printf("%c",sentence[start]);
        start=nex[start];
       }
    return 0;
}
void insert(int *cursor, char new, int *m)
{
    //Á¦ÀÏ ¸¶Áö¸·¿¡ ¹®ÀÚ Ãß°¡ÇÏ´Â °æ¿ì//
    if(nex[*cursor]==-3)
    {
        int current;
        for(int i=0;i<*m;i++)
        {
            if(nex[i]==-1)
            {
                current=i;
                break;
            }
        }
        sentence[*cursor]=new;
        nex[*cursor]=-1;
        pre[*cursor]=current;
        nex[current]=*cursor;
        (*m)++;
        for(int i=0;;i++)
        {
            if(nex[i]==-3)
            {
                *cursor=i;
                break;
            }
        }
    }
    else if(nex[*cursor]!=-1&&pre[*cursor]!=-1) //Áß°£¿¡ Ãß°¡ÇÏ´Â °æ¿ì
    {
        int current;
        for(int i=0;i<*m;i++)
        {
            if(nex[i]==*cursor)
            {
                current=i;
                break;
            }
        }
        sentence[*m]=new;
        nex[*m]=nex[current];
        nex[current]=*m;
        pre[*m]=current;
        *cursor=nex[*m];
        (*m)++;
    }
    //Ã³À½¿¡ Ãß°¡ÇÏ´Â °æ¿ì
    else if(pre[*cursor]==-1)
    {
        sentence[*m]=new;
        nex[*m]=*cursor;
        pre[*cursor]=*m;
        pre[*m]=-1;
        *cursor=nex[*m];
    }
}
void erase(int *cursor, int *m) 
{
    //Ä¿¼­°¡ Á¦ÀÏ µÚ¿¡ ÀÖÀ» ¶§//
    if(*cursor==*m)
    {
        int current;
        for(int i=0;i<*m;i++)
        {
            if(nex[i]==-1)
            {
                current=i;
                nex[i]=-2;
                break;
            }
        }
        nex[pre[current]]=-1;
        *cursor=current;
    }
    //Ä¿¼­°¡ Áß°£¿¡ ÀÖÀ» ‹š//
    else if(pre[pre[*cursor]]!=-1&&nex[*cursor]!=-1)
    {
        nex[pre[pre[*cursor]]]=*cursor;
        pre[*cursor]=pre[pre[*cursor]];
        *cursor=pre[*cursor];
    }
    //
    else if(pre[pre[*cursor]]==-1)
    {
        nex[pre[*cursor]]=-2;
        pre[pre[*cursor]]=-2;
        pre[*cursor]=-1;
    }
}