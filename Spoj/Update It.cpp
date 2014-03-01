#include<cstdio>

int ft[10000005];
int maxVal;
// Add v to A[p]
void update(int p, int v)
{
    for (;p<=maxVal;p+=p&(-p))
		ft[p] += v;
}
//Add v to A[a...b]
void update_r(int a,int b,int v)
{
    update(a, v);
    update(b + 1, -v);
}
//Return A[b]
int query(int b)
{
    int sum = 0;
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int u,q,i,j,a,n;
		scanf("%d%d",&n,&u);
		reset(n);
		int l,r,val;
		for(i=0;i<u;i++)
		{
			scanf("%d%d%d",&l,&r,&val);
			update_r(l+1,r+1,val);
		}
		scanf("%d",&q);
		for(i=0;i<q;i++)
		{
			scanf("%d",&a);
			printf("%d\n",query(a+1));

		}
	}
	return 0;
}
