#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
long long int pow1(long long int a,long long int b,long long int n)
{
    long long int res=1;
    while (b)
    {
        if (b % 2) { res = (res * a) % n; }
        a = (a * a) % n;
        b /= 2;
    }
    return res;
}

long long int  comb(long long int k, long long int r)
{
    long long int p,i;p=1;
    for(i=r+1;i<=r+k-1;i++) p=p*i%1000000007;
    return(p);
}

int main()
{
    long long int n,r,i,s,ntc,j,k,p1;
    scanf("%lld",&ntc);
    long long int a[50001];
    for(i=0;i<ntc;i++)
    {
        p1=1;
        scanf("%lld %lld",&n,&k);
        for(j=1;j<k;j++) p1=p1*j%1000000007;
        p1=pow1(p1,1000000005,1000000007);
        for(j=0;j<n;j++)
            scanf("%lld",&a[j]);
        sort(a,a+n);
        s=0;
        for(r=0;r<=n-k;r++)
        s=(s+(a[r+k-1]%1000000007)*((comb(k,r)*p1)%1000000007))%1000000007;
        printf("Case #%lld: %lld\n",i+1,s);
    }
    return 0;
}
