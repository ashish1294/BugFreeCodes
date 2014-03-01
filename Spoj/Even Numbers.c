#include<stdio.h>
#include<math.h>
unsigned int convert(unsigned int n)
{
	if(n==0)
		return 1;
	int nn=0;
	while(n>0)
	{
		if(n&1==1)
			nn=nn|1;
		nn=nn<<1;
	}
}
int main()
{
	unsigned int t,n,d1,d2;
	scanf("%u",&t);
	while(t--)
	{
		scanf("%u",&n);
		if(n%2==0)
		{
			int bits=sizeof(n)*8;
			int arr[bits];
			int j=0,k;
			while(n)
			{
				arr[j]=n&1;
				arr[j] ^= 1;
				j++;
				n=n>>1;
			}
			for(k=0;k<j;k++)
			{
					n = n|arr[k];
					n=n<<1;
			}
			if(n==0)
				n=1;
		}
		printf("%u\n",n);
	}
	return 0;
}
