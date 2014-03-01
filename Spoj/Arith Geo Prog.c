#include<stdio.h>
/*long int modsum(long int n, long int l)
{
	long int a = 1;
	long int b = 0;
	for (int i = 1; i < l + 1; i++)
	{
		a=(n *a)% m;
		b=(b+a) % m;
	}
	return b;
}*/
long long int mysum(long int r,long int limit, long int mod,int start)
{
	long long int i,ssum=1,cc=1;
	if(start==1)
	{
		cc=r;
		ssum=0;
	}
	for(i=0;i<limit;i++)
	{
		cc = (cc*r)%mod;
		ssum=(ssum+cc)%mod;
	}
	return ssum;
}
long long int modexp(long long int a,long long int b,long long int mm)
{
	long long int x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
            x=(x*y)%mm;
        y = (y*y)%mm;
        b /= 2;
	}
	return x%mm;
}

int main()
{
	long long int t,a,d,r,n,mod;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld",&a,&d,&r,&n,&mod);
		a = a%mod;
		r = r%mod;
		d = d%mod;
		if(n==1)
		{
			printf("%lld\n",a);
			continue;
		}
		else if(n==2)
		{
			printf("%lld\n",(a+d)%mod);
			continue;
		}
		long long int limit = n-1;
		limit /=2;
		limit = floor(limit);
		long long int sum;
		if(d!=0)
		{
			if(n%2==0)
				sum = mysum(r,limit,mod,0);
			else
				sum = mysum(r,limit,mod,1);
			sum=sum%mod;
			sum = (sum*d)%mod;
		}
		else
			sum=0;
		long long int first = modexp(r,limit,mod)%mod;
		first = first*(a%mod);
		first = first%mod;
		sum = (sum + first)%mod;
		printf("%lld\n",sum);
	}
	return 0;
}
