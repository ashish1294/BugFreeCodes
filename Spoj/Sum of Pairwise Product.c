//http://www.spoj.com/problems/PAIRSUM/
//@ashish1294 - NITK Surathkal

#include<stdio.h>
inline int input()
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
	int n,i;
	n=input();
	int arr[n];
	unsigned long long int sum[n],sumsq[n];
	for(i=0;i<n;i++)
		arr[i]=input();
	sum[0]=arr[0];
	sumsq[0]=arr[0]*arr[0];
	for(i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+arr[i];
		sumsq[i]=sumsq[i-1]+(arr[i]*arr[i]);
	}
	int m=input();
	for(i=0;i<m;i++)
	{
		int u=input();
		int v=input();
		unsigned long long int s = sum[v]-sum[u]+arr[u];
		unsigned long long int sq = sumsq[v]-sumsq[u]+(arr[u]*arr[u]);
		unsigned long long int ans= ((s*s)+sq)/2;
		printf("%llu\n",ans);
	}
	return 0;
}
