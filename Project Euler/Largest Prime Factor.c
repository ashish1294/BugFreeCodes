#include<stdio.h>
int main()
{
    long long int t,i;
    scanf("%lld",&t);
    for(i=2;i<=t;i++)
    {
        if(t%i==0)
        {
            printf("%lld\n",i);
            t /= i;
        }
    }
    return 0;
}
