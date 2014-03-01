#include<stdio.h>
#define pr 1000007
int main()
{
    int t;
    long long int n,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n%2==0)
        {
            ans=((3*n+1)%pr)*((n/2)%pr);
            ans = ans%pr;
        }
        else
        {
            ans = (((3*n+1)/2)%pr)*(n%pr);
            ans = ans%pr;
        }
        printf("%ld\n",ans);
    }
    return 0;
}
