#include<stdio.h>
#define Buff 20000
static long long int f[Buff];
int main()
{
    int t;
    long long int c,p,fib1,fib2,fib3,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&c,&p);
        if (c==0)
        {
            printf("0\n");
            continue;
        }
        if (c==1)
        {
            printf("1\n");
            continue;
        }
        fib1=0;
        fib2=1;
        x=1;
        while(1)
        {
            if ((x<Buff)&&(f[x+1]>0))
                fib3 = f[x+1]%p;
            else
                fib3= (fib1+fib2)%p;
            x++;
            if (fib3==c)
            {
                printf("%lld\n",x);
                break;
            }
            if(x==p)
            {
                printf("-1\n");
                break;
            }
            fib1=fib2;
            fib2=fib3;
        }

    }
    return 0;
}
