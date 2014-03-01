//http://projecteuler.net/problem=6
//Author Ashish Kedia , NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
    long long int t;
    scanf("%lld",&t);
    long long int ans = (t*(t+1))/2;
    ans = (ans*(t-1))/3;
    ans = (ans*((3*t)+2))/2;
    printf("%lld\n",ans);
    return 0;
}
