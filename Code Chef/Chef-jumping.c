//http://www.codechef.com/MAY14/problems/OJUMPS
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
    long long int x;
    scanf("%lld",&x);
    if((x%3==0) || ((x%3==1) && ((x/3)%2==0))) puts("yes");
    else puts("no");
    return 0;
}
