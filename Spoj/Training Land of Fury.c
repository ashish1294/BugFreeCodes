//http://www.spoj.com/problems/NFURY/
#include<stdio.h>
#include<math.h>
int min(int a,int b)
{return a>b?b:a;}
int main()
{
	int i,k;
	int dparr[2000];
	dparr[0]=0;
	dparr[1]=1;
	dparr[2]=2;
	dparr[3]=3;
	for(i=4;i<=1000;i++)
	{
		int j = sqrt(i);
		dparr[i]=i;
		if(j*j==i)
			dparr[i]=1;
		else
		for(k=1;k<=j;k++)
			dparr[i]=min(dparr[i],dparr[k*k]+dparr[i-(k*k)]);
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&i);
		printf("%d\n",dparr[i]);
	}
	return 0;
}
