#include<stdio.h>
#define pr 10
int mulmod(long int a,long int b)
{
    long long int x = 0,y=a%pr;
    while(b > 0)
    {
        if(b%2 == 1)
            x =(x+y)%pr;
        y = (y*2)%pr;
        b /= 2;
    }
    return x%pr;
}
long int modulo(long int a,long int b)
{
    long long int x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
            x=(x*y)%pr;
        y = (y*y)%pr;
        b /= 2;
    }
    return x%pr;
}
int main()
{
	long int a,b;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld %ld",&a,&b);
		int ans = modulo(a,b);
		printf("%d\n",ans);
	}
	return 0;
}
