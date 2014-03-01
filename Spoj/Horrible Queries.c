#include<stdio.h>
static long long int B1[1000005];
static long long int B2[1000005];
int maxVal;

void update(long long int ft[],int p,long long int v)
{
    for (;p<=maxVal;p+=p&(-p))
		ft[p] += v;
}

void update_r(int a,int b,long long int v)
{
    update(B1, a, v);
    update(B1, b+1, -v);
    update(B2, a, v*(a-1));
    update(B2, b+1,-v*b);
}

long long int query(long long int ft[], int b)
{
    long long int sum = 0;
    for(;b>0;b-=b&(-b)) sum+=ft[b];
    return sum;
}

//Return sum A[1...b]
long long int query_st(int b)
{return (query(B1,b)*b-query(B2,b));}

// Return sum A[a...b]
long long int query_r(int a,int b)
{return query_st(b)-query_st(a-1);}

//ResetTree
void reset(int m)
{
	int i;
	for(i=0;i<=m+1;i++)
	{
		B1[i]=0;
		B2[i]=0;
	}
	maxVal=m+1;
}
int main()
{
	int n,k,i,type,p,q,t;
	scanf("%d",&t);
	while(t--)
	{
	long long int v,sum;
	scanf("%d%d",&n,&k);
	reset(n);
	for(i=0;i<k;i++)
	{
		scanf("%d",&type);
		if(type==0)
		{
			scanf("%d%d%lld",&p,&q,&v);
			update_r(p,q,v);
		}
		else
		{
			scanf("%d%d",&p,&q);
			printf("%lld\n",query_r(p,q));
		}
	}
	}
	return 0;
}
