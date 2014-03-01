#include<stdio.h>
static long int A[10000000000];
int main()
{
    int t,k;
    long long int n;
    long long int f(long long int, int);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%d",&n,&k);
        printf("%lld\n",(f(n,k)%1000000007));
    }
    return 0;
}
long long int f(long long int n, int k)
{
    if(n==1)
        return 1;
    if(k==1||k==n)
        return n;
    else if ()
        return (f(n-1,k)+f(n-1,k-1));
}
long long int pos(long int i , long int j)
{
    return ((i*(i-1))/2) + (j-1);
}
