//http://www.codechef.com/KGP13ACM/problems/KGP13B
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define maxi 1000000
static int days[maxi];
int main()
{
	int t,m,k,i,noeve,j,a,b,l;
	scanf("%d",&t);
	for(l=1;l<=t;l++)
	{
		scanf("%d%d",&k,&m);
		int event[k][2];
		for(i=0;i<maxi;i++) days[i]=0;
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&event[i][0],&event[i][1]);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&noeve);
			for(j=0;j<noeve;j++)
			{
				scanf("%d%d",&a,&b);
				for(k=event[a-1][0];k<=event[a-1][1];k++)
					days[k] +=b;
			}
		}
		int maximum=days[0];
		for(i=1;i<maxi;i++) if(days[i]>maximum) maximum=days[i];
		printf("Case %d: %d\n",l,maximum);
	}
	return 0;
}
