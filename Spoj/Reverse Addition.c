#include<stdio.h>
long int rev(long int a)
{
	long int ans=0;
	while(a>0)
	{
		ans = ans*10 + (a%10);
		a /= 10;
	}
	return ans;
}
int main()
{
	int t;
	long int a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld%ld",&a,&b);
		long int ans=rev(a)+rev(b);
		ans = rev(ans);
		printf("%ld\n",ans);
	}
	return 0;
}
