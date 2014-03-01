
#include<stdio.h>
int main()
{
	int t;
	long long int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		long long int ans=0;
		int div = 5;
		while(1)
		{
			int dig = n/div;
			if(dig==0)
				break;
			ans += dig;
			div *=5;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
