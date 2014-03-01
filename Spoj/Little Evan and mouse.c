#include<stdio.h>

int main()
{
    int t;
    long long int n,m,r,c,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld",&n,&m,&r,&c,&t);
        if(t==0)
        {
            printf("%lld %lld\n",r,c);
        }
        else if(t==1)
        {
            if(r>1)
                printf("%lld %lld\n",r-1,c);
            else
            {
                if(c==m)
                    printf("%lld %lld\n",r+1,c);
                else
                    printf("%lld %lld\n",r,c+1);
            }
        }
        e   lse
        {
            while(1)
            {

            }
        }
    }
}
