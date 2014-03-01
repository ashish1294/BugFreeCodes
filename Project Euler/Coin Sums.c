//http://projecteuler.net/problem=31
//Author Ashish Kedia NITK Surathkal
//@ashish1294
#include<stdio.h>
#define SUM 200
int main()
{
    int coeff[]={1,2,5,10,20,50,100,200},colen=8,i,j;
    int dp[201];
    dp[0]=1;
    for(i=1;i<=SUM;i++) dp[i]=0;
    for(i=0;i<colen;i++)
    {
        for(j=coeff[i];j<=SUM;j++)
        {
            dp[j] += dp[j-coeff[i]];
        }
    }
    printf("The Number of Ways are:%d",dp[200]);
    return 0;
}
