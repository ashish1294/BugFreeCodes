#include<stdio.h>

int main()
{
	long long int n;
	while(scanf("%lld",&n)!=EOF)
	{
		long long int nn = n/9;
		long long int ans = (nn*81);
		nn = n%9;
		ans += nn*nn;
		printf("%lld\n",ans);
	}
	return 0;
}
