//http://www.spoj.com/problems/ENIGMATH/
//Author - Ashish Kedia , NITK Surathkal
//@ashish1294
#include<stdio.h>
int gcd(int a, int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int t,a,b,x,y,gg;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		gg=gcd(a,b);
		x=b/gg;y=a/gg;
		printf("%d %d\n",x,y);
	}
	return 0;
}
