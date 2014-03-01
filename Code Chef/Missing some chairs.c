#include<stdio.h>
long long int exp(long long int a,long long int b);
int main()
{
    int t;
    long long int n,ans;
    printf("%lld",exp(2,5));
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=exp(2,n);
        if(ans==0)
            printf("1000000006\n");
        else
        {
            ans=ans-1;
            printf("%lld\n",ans);
        }
    }
    return 0;
}

long long int exp(long long int a,long long int b)
{
    long long int x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
            x=(x*y)%1000000007;
        y = (y*y)%1000000007;
        b /= 2;
    }
    return x%1000000007;
}
