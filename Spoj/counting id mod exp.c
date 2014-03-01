#include<stdio.h>
long int pr = 1000000007;
long long int modexp(long int a,long int b,long int mm)
{    
	long int x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
            x=(x*y)%mm;
        y = (y*y)%mm;
        b /= 2;    
     }
     return x%mm;
}
int main()
{
	long int n,l;
	while(1)
	{
		scanf("%ld%ld",&n,&l);
		if(n==0 && l==0)
			break;
		else if(l==0)
		{
			printf("0\n");
			continue;
		}
		else if(n==1)
		{
			printf("%ld\n",l);
			continue;
		}
		long long int ans,ans1;
		ans = ((((modexp(n,l,pr)-1+pr)%pr)*((n%pr)))%pr);
		ans1 = (modexp(n-1,pr-2,pr)*ans)%pr;
		printf("%lld\n",ans1);
	}
	return 0;
}
