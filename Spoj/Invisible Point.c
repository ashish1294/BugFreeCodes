#include<stdio.h>
static long int arr[1000001]={0};
int main()
{
	int t;
	long int n,i;
	arr[3]=3;
	arr[4]=3;
	arr[5]=4;
	arr[6]=4;
	for(i=7;i<=1000000;i++)
	{
		arr[i]=arr[((i/2) + 2)]+1;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		printf("%ld\n",arr[n]);
	}
	return 0;
}
