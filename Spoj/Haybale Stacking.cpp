#include<stdio.h>
#include<algorithm>
void Quick_Sort(long int Arr[],long int l,long int u);
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
	int n,k,i,a,b;
	scanf("%d%d",&n,&k);
	reset(n+1);
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&a,&b);
		update_r(a,b,1);
	}
	long int arr[n];
	for(i=0;i<n;i++)
	{
		arr[i]=query(i+1);
	}
	std::sort(arr,arr+n);
	printf("%ld\n",arr[n/2]);
	return 0;
}
