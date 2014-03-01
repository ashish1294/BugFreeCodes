#include<stdio.h>
long int max(long int a,long int b)
{
    return a>b?a:b;
}
long int min(long int a,long int b)
{
    return a<b?a:b;
}
long long int DiophantineSol(long long int noofele,long long int sumval,long int Max[],long int mod)
{
    long long int p,r,n=noofele,k=sumval;
    long int i,j;
    int S[n+1][k+1];
    for(p=0;p<=min(Max[1],n);p++) S[1][p]=1;
    for(;p<=n;p++) S[1][p]=0;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            long long int s=0;
            for(r=max(0,j-Max[i]);r<=j;r++)
            {
                s+=S[i-1][r];
                s = s%mod;
            }
            S[i][j]=s;
        }
    }
    return S[n][k];
}
int main()
{
    int n;
    long int a,b;
    scanf("%d%ld%ld",&n,&a,&b);
    long int jar[n+1],i;
    for(i=1;i<=n;i++)
    {
        scanf("%ld",&jar[i]);
    }
    long long int ans=0;
    for(i=a;i<=b;i++)
    {
        ans += DiophantineSol(n,i,jar,2004);
        ans = ans%2004;
    }
    printf("%lld\n",ans);
    return 0;
}
