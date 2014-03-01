#include<stdio.h>
int main()
{
    int t;
    long long int x,y,z,a,n,d,i,term;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&x,&y,&z);
        n = (2*z)/(x+y);
        d = (y-x)/(n-5);
        a = x - (2*d);
        printf("%lld\n",n);
        for(i=0;i<n;i++)
        {
            term = a + (i*d);
            printf("%lld",term);
            if(i!=n-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
