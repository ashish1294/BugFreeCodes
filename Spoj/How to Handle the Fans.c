//http://www.spoj.com/problems/AKVQLD03/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>

int ft[1000005];
int maxVal;

inline void update(int p, int v)
{
	for(;p<=maxVal;p+=p&(-p)) ft[p] += v;
}

inline int query(int b)
{
	int sum = 0;
    for(; b > 0; b -= b&(-b)) sum += ft[b];
    return sum;
}

inline int query_r(int a,int b)
{
	return (query(b) - (a==1?0:query(a-1)));
}

inline int inp()
{
    register int noRead=0;
    register char p=getchar_unlocked();
    //register char p=getc(stdin);
    for(;p<48 || p>57;p=getchar_unlocked());
    //for(;p<48 || p>57;p=getc(stdin));
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};

int main()
{
	int n,q,a,b,i;
	char c,d;
	n=inp();q=inp();
	for(i=0;i<=n;i++) ft[i]=0; maxVal=n;
	while(q--)
	{
		c=getchar_unlocked();
		while (c!='a' && c!='f') c=getchar_unlocked();
		d=c;
		while(c!=' ') c=getchar_unlocked();
		a=inp();b=inp();
		if(d=='a') update(a,b);
		else printf("%d\n",query_r(a,b));
	}
	return 0;
}
