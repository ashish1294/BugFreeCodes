//http://www.spoj.com/problems/SAMER08F/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
	int n;
	long long int ans;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) return 0;
		ans = 1LL*n*(n+1)*(2*n+1);
		ans/=6;
		printf("%lld\n",ans);
	}
	return 0;
}
