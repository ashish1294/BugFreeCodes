#include<stdio.h>
#include<stdbool.h>
static bool prime[1000000];
int main()
{
    long int i,j;
    for (i=2; i<1000000; i++)
            prime[i]=true;
        for (i=2;i<=1000;i++)
            if (prime[i]==true)
                for (j=2*i; j<=1000000; j+=i)
                    prime[j]=false;
    int t;
    long int a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld %ld",&a,&b);
        if (a==1)
            a++;
        bool result[b-a+1];
        if (b-a+1>2)
        result[2]=false;
        if(b-a+1>3)
        result[3]=false;
        for(i=4;i<b-a+1;i++)
            result[i]=false;
        for (i=2; i<=1000000; i++)
        {
            if (prime[i])
            {
                long int p = a-a%i;
                if (p<a)
                    p += i;
                if (p==i)
                    p += i;
                while (p<=b)
                {
                    result[p-a]=true;
                    p += i;
                }
            }
        }
        for(i=a;i<=b;i++)
        {
            if(!result[i-a])
                printf("%ld\n",i);
        }
    }
    return 0;
}
