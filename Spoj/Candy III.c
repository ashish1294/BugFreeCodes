//http://www.spoj.com/problems/CANDY3/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
inline int inp()
{
    int noRead=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked());
    for(;p<48 || p>57;p=getc(stdin));
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
int main()
{
	int t,n,i;
	unsigned long long int sum,a;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a);
			sum += a;
			sum =  sum%n;
		}
		if(sum==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
