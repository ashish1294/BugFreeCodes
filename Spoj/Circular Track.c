//http://www.spoj.com/problems/SPEED/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int gcd(int a,int b)
{ return (b==0?a:gcd(b,a%b));}
int main()
{
	int a,b,ans,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		ans = a-b;
		if(ans<0) ans=-ans;
		if(a<0) a=-a;
		if(b<0) b=-b;
		ans/=gcd(a,b);
		printf("%d\n",ans);
	}
	return 0;
}
