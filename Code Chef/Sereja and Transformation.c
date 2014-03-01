#include<stdio.h>
#define pr 1000000007
long int modulo(long int a,long int b)
{
    long long int x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
            x=(x*y)%pr;
        y = (y*y)%pr;
        b /= 2;
    }
    return x%pr;
}
long int mulmod(long int a,long int b){
    long long int x = 0,y=a%pr;
    while(b > 0)
    {
        if(b%2 == 1)
            x =(x+y)%pr;
        y = (y*2)%pr;
        b /= 2;
    }
    return x%pr;
}
int main()
{
    long long int n,m,q,k;
    int t;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%lld %lld %lld %lld",&n,&m,&q,&k);
        k=modulo(q+1,n)+modulo(q-1,n)-mulmod(2,modulo(q,n));
        if(k<0)
            k += pr;
        k = k%pr;
        printf("%ld\n",mulmod(k,m-q));
    }
    return 0;
}
