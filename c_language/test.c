#include <stdio.h>
int main(void)
{
    prinf("Hello, world!");
    return 0;
}
int fib2(int n)
{
    int i;
    int f[n];
    f[0]=0;
    if(n>0)
    {
        f[1]=1;
        for(i=2;i<=n;i++)
        {
            f[i]=f[i-1]+f[i-2];
        }
    }
    return f[n];
}