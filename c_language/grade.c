#include <stdio.h>
int main(void)
{
   int i;
   int total=0;
   for(i=1; i<=10;i++)
   {
    if(i%2==0)
    {
        total=total+i;
    }
   }
   printf("%d",total);

    return 0;
}