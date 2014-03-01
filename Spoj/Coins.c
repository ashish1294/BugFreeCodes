#include<stdio.h>
static long long int dparr[1000000];
long long int coindp(long int n)
{
    if(n<1000000)
        return dparr[n];
    long long int t=coindp(n/2)+coindp(n/3)+coindp(n/4);
    if (t>n)
        return t;
    else
        return n;
}
void memoize()
{
    dparr[0]=0;
    dparr[1]=1;
    dparr[2]=2;
    dparr[3]=3;
    dparr[4]=4;
    long int i;
    long long int t;
    for(i=5;i<1000000;i++)
    {
        t=dparr[i/2]+dparr[i/3]+dparr[i/4];
        if(t>i)
            dparr[i]=t;
        else
            dparr[i]=i;
    }
}
int main()
{
    long int n;
    memoize();
    while(scanf("%ld",&n)!=EOF)
    {
        long long int ans = coindp(n);
        printf("%lld\n",ans);
    }
    return 0;
}
