#include<stdio.h>
int main()
{
    int t,n;
    long long int te,i;
    long int b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%ld",&n,&b);
        te=0;
        for(i=1;i<=n;i++)
        {
            if (((i*(i+1))/2)==b)
            {
                te=1;
                break;
            }
        }
        printf("%lld\n",(((n*(n+1))/2)-te));
    }
    return 0;
}
