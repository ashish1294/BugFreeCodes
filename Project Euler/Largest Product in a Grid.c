//http://projecteuler.net/problem=11
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
    long long int g[20][20],i,j;
    long long int p,p1;
    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
            scanf("%lld",&g[i][j]);
    p=0;
    for(i=0;i<20;i++)
    {
        for(j=0;j<=16;j++)
        {
            p1=g[i][j]*g[i][j+1]*g[i][j+2]*g[i][j+3];
            if(p1>p)
                p=p1;
        }
    }
    for(i=0;i<=16;i++)
    {
        for(j=0;j<20;j++)
        {
            p1=g[i][j]*g[i+1][j]*g[i+2][j]*g[i+3][j];
            if(p1>p)
                p=p1;
        }
    }
    for(i=0;i<=16;i++)
    {
        for(j=0;j<=16;j++)
        {
            p1=g[i][j]*g[i+1][j+1]*g[i+2][j+2]*g[i+3][j+3];
            if(p1>p)
                p=p1;
        }
    }
    for(i=0;i<=16;i++)
    {
        for(j=3;j<=19;j++)
        {
            p1=g[i][j]*g[i+1][j-1]*g[i+2][j-2]*g[i+3][j-3];
            if(p1>p)
                p=p1;
        }
    }
    printf("%lld\n",p);
    return 0;
}
