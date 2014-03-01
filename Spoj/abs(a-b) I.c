//http://www.spoj.com/problems/ABSP1/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
inline int inp()
{
    register int noRead=0;
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
	int t=inp(),n,i,n1,n2;
	long long int ans=0;
	while(t--)
	{
		n=inp();ans=0;
		n1=inp();
		for(i=1;i<n;i++)
		{
			n2=inp();
			ans += 1LL*(n2-n1)*i*(n-i);
			n1=n2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
