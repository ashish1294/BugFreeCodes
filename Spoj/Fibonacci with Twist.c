#include<stdio.h>
void multiply(long long int F[2][2], long long int M[2][2],long long int mod);
void power(long long int F[2][2],long int n,long long int mod);
long long int fib(long int n,long long int mod)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1,mod);
  return (F[0][0]%mod);
}
void power(long long int F[2][2], long int n,long long int mod)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{1,1},{1,0}};
  power(F, n/2,mod);
  multiply(F, F,mod);
  if (n%2 != 0)
     multiply(F, M,mod);
}

void multiply(long long int F[2][2],long long int M[2][2],long long int mod)
{
  long long int x =  ((F[0][0]*M[0][0])%mod) + ((F[0][1]*M[1][0])%mod);
  long long int y =  ((F[0][0]*M[0][1])%mod) + ((F[0][1]*M[1][1])%mod);
  long long int z =  ((F[1][0]*M[0][0])%mod) + ((F[1][1]*M[1][0])%mod);
  long long int w =  ((F[1][0]*M[0][1])%mod) + ((F[1][1]*M[1][1])%mod);

  F[0][0] = x%mod;
  F[0][1] = y%mod;
  F[1][0] = z%mod;
  F[1][1] = w%mod;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long int n;
        long long int m,ans;
        scanf("%ld%lld",&n,&m);
        ans = fib(n+2,m);
        ans = ((ans - 1)+m)%m;
        ans = (ans*2)%m;
        ans = ((ans - (n%m))+m)%m;
        printf("%lld\n",ans);
    }
    return 0;
}
