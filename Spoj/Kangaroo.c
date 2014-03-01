#include<stdio.h>
int main()
{
	long int n,m,i,j;
	scanf("%ld%ld",&n,&m);
	long int NL[n],ML[m],NH[n],MH[m];
	for(i=0;i<n;i++)
		scanf("%ld%ld",&NL[i],&NH[i]);
	for(i=0;i<m;i++)
	{
		scanf("%ld%ld",&ML[i],&MH[i]);
		long int count=0;
		for(j=0;j<n;j++)
		{
			if((ML[i]<=NH[j] && ML[i]>=NL[j]) || (MH[i]<=NH[j] && MH[i]>=NL[j]) || (ML[i]<=NL[j] && MH[i]>=NH[j]))
				count++;
		}
		printf("%ld\n",count);
	}
	return 0;
}
