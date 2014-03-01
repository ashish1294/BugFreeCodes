#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define modp 1000000007
long modulo2(unsigned long long int b);
int main()
{
    long int t;
    unsigned long int a;
    unsigned long long int ans,f,i;
    scanf("%ld",&t);
    while(t--)
    {
        ans=0;f=1;
        scanf("%ld",&a);
        for(i=0;i<=31;i++,f*=10)
            if(a&(1<<i))
                ans+=f;
        ans=modulo2(ans);
        ans=(ans*ans)%modp;
        printf("%ld\n",(long int)ans);
    }
    return 0;
}
long modulo2(unsigned long long int b)
{
    unsigned long long int y=2;
    long x=1;
    while(b > 0)
    {
        if(b%2==1)
            x=(x*y)%modp;
        y = (y*y)%modp;
        b /= 2;
    }
    return x%modp;
}
