#include<stdio.h>

static char str[1111111];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,i,ans;
        scanf("%lld",&n);
        getchar();
        for(i=0;i<n;i++)
            scanf("%[^\n\r]");
        if(n%2==0)
            ans = (n-1)*(n/2);
        else
            ans = ((n-1)/2)*n;
        printf("%lld\n",ans);
    }
    return 0;
}
