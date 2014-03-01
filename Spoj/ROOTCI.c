#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		long long int ans = (a*a)-(2*b);
		printf("%lld\n",ans);
	}
	return 0;
}
