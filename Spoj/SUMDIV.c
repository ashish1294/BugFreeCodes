#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAXPR 1000
static bool isprime[MAXPR]={true};
static long int prlist[MAXPR];
long int numpr=0;
void initsieve()
{
	long int i,j;
	for(i=2;i<MAXPR;i++)
		isprime[i]=true;
	for(i=2;i<MAXPR;i++)
	{
		if(isprime[i]==true)
		{
			prlist[numpr++]=i;
			for(j=i*i;j<MAXPR;j=j+i)
				isprime[j]=false;
	}
		}
}
int main()
{
	initsieve();
	int t;
	long int i;
	long long int num,numc,tempsum,temppr,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&num);
		numc=num;
		ans=1;
		for(i=0;i<numpr;i++)
		{
			if(num==1 || prlist[i]>sqrt(numc))
				break;
			tempsum=1;
			temppr=1;
			while(num%prlist[i]==0)
			{
				temppr *= prlist[i];
				tempsum += temppr;
				num /= prlist[i];
			}
			ans *= tempsum;
		}
		if(num!=1)
			ans *= (1+num);
		ans = ans - numc;
		printf("%lld\n",ans);
	}
	return 0;
}
