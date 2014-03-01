//http://www.spoj.com/problems/ANARC08G/
//@ashish1294 NITK Surathkal

#include<stdio.h>
//Positive BitWIse Input
inline int inp()
{
	int noRead=0;
	register char p=getchar_unlocked();
	for(;p<33;p=getchar_unlocked());
	while(p>32)
	{
		noRead = (noRead << 3) + (noRead << 1) + (p - '0');
		p=getchar_unlocked();
	}
	return noRead;
};
int main()
{
	int n,i,j,v,co=0,c[1005];
	long long int sum;
	while(1)
	{
		n=inp();
		if(n==0)
			return 0;
		co++;
		sum=0;
		for(i=0;i<n;i++)
			c[i]=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				v=inp();
				sum += v;
				c[i] += v;
				c[j] -= v;
			}
		}
		printf("%d. %lld ",co,sum);
		sum=0;
		for(i=0;i<n;i++)
			if(c[i]>0) sum += c[i];
			else sum -= c[i];
		sum /=2;
		printf("%lld\n",sum);
	}
	return 0;
}
