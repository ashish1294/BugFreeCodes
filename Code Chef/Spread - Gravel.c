//http://www.codechef.com/APRIL11/problems/SPREAD/
#include<stdio.h>

//Fast IO

inline long int inp()
{
	int noRead=0;
	register char p=getchar_unlocked();
	for(;p<33;p=getchar_unlocked());
	while(p>32)
	{
		noRead = (noRead << 3) + (noRead << 1) + (p - '0');
		p=getchar_unlocked();
	}
	return noRead;
};
inline long long int llinp()
{
	long long int noRead=0;
	register char p=getchar_unlocked();
	for(;p<33;p=getchar_unlocked());
	while(p>32)
	{
		noRead = (noRead << 3) + (noRead << 1) + (p - '0');
		p=getchar_unlocked();
	}
	return noRead;
};
long long int ft[10000005];
int maxVal;
// Add v to A[p]
void update(int p, long long int v)
{
    for (;p<=maxVal;p+=p&(-p))
		ft[p] += v;
}
//Add v to A[a...b]
void update_r(int a,int b,long long int v)
{
    update(a, v);
    update(b + 1, -v);
}
//Return A[b]
long long int query(int b)
{
    long long int sum = 0;
    for(; b > 0; b -= b&(-b))   sum += ft[b];
    return sum;
}
//ResetTree
void reset(int m)
{
	int i;
	for(i=0;i<=m;i++)
		ft[i]=0;
	maxVal=m;
}
int main()
{
	int n,m,c,l,r,i;
	long long int val;
	char ch;
	n=inp();
	m=inp();
	c=inp();
	reset(n);
	update_r(1,n,c);
	for(i=0;i<m;i++)
	{
		ch=getc(stdin);
		while(ch!='S' && ch!='Q')
			ch=getc(stdin);
		if(ch=='S')
		{
			l=inp();
			r=inp();
			val=llinp();
			update_r(l,r,val);
		}
		else if (ch=='Q')
		{
			l=inp();
			printf("%lld\n",query(l));
		}
	}
	return 0;
}
