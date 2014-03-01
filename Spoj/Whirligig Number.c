//http://www.spoj.com/problems/MZVRK/
//@ashish1294 NITK Surathkal
#include<stdio.h>
long long int solve(long long int n)
{
   if(n==1) return 1;
   else if((n%2)==0)
      return (2*solve(n/2))+(n/2);
   else
      return (2*solve(n/2))+(n/2)+1;
}
long long int num(long long int n)
{
	long long int x=1;
	while(n%2==0)
	{
		x=x<<1;
		n=n/2;
	}
	return x;
}

int main()
{
   long long int p,q;
   scanf("%lld%lld",&p,&q);
   long long int qs=solve(q),ps=solve(p),n=num(p);
   long long int ans=qs-ps+n;
   printf("%lld\n",ans);
   return 0;
}
