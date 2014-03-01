#include<stdio.h>
long D(long a);
long sumd(long a, long b);

int main()
{
    int t;
    long a,b;
    long long ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld %ld",&a,&b);
        ans = ((b/10-a/10)*45) + D(a) + sumd(b-(b%10),b) - sumd((a-(a%10)),a);
        printf("%lld\n",ans);
    }
    return 0;
}
long D(long a)
{
    int arr[]={0,1,4,3,8,5,2,7,6,9};
    long sum=0,i;
    for(i=a;i;i /= 10)
        sum += arr[i%10];
    return sum%10;
}
long sumd(long a,long b)
{
    long i,s=0;
    for(i=a;i<=b;i++)
        s += D(i);
    return s;
}
