//A slight modification to the Dijkstra algorithm. Weight of 2 paths is not added rather product should be taken. Path tracking is not done.
//Graph is the global variable that contains the graph of intersection
//Actual problem can be found at:  http://www.spoj.com/problems/CHICAGO/
//Source is always 1st vertex


#include<stdio.h>
#define MAX 101
#define inf 1000000000
int Graph[MAX][MAX][2];
int n;
float dijkstra()
{
	int i,j,minin;
	float bestd[n+1][2];
	bestd[1][0]=0;
	bestd[1][0]=1;
	for(i=2;i<=n;i++)
	{
		if(Graph[1][i][0]==1)
			bestd[i][0]=Graph[1][i][1];
		else
			bestd[i][0]=inf;
		bestd[i][1]=0;
		 printf("i=%d %d %d\n\n",i,bestd[i][0],bestd[i][1]);
	}
	for(i=1;i<n+1;i++)
        printf("%d %d\n",bestd[i][0],bestd[i][1]);
	for(i=1;i<=n-1;i++)
	{
		minin=-1;
		for(j=1;j<=n;j++)
		{
			if(bestd[j][1]==0 && (minin==-1 || bestd[j][0]<bestd[minin][0]))
			{
				minin=j;
			}
		}
		if(minin==n)
        {
            printf("\nminin= %d bestd=%f \n",minin,bestd[minin][0]);
            return bestd[minin][0];
        }
		bestd[minin][1]=1;
		for(j=1;j<=n;j++)
		{
			if(bestd[j][1]==0 && Graph[minin][j][0]==1 && (bestd[j][0]>((bestd[minin][0]*Graph[minin][j][1])/100)))
			{
				bestd[j][0]=(bestd[minin][0]*Graph[minin][j][1])/100;
			}
		}
	}
}

int main()
{
	int m,a,b,c,i;
	float ans;
	scanf("%d",&n);
	while(n!=0)
	{
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			Graph[a][b][0]=1;
			Graph[b][a][0]=1;
			Graph[a][b][1]=c;
			Graph[b][a][1]=c;
		}
		printf("\nGraph here: 1,2=%d %d\n",Graph[1][2][0],Graph[1][2][1]);
		ans=dijkstra();
		printf("%f\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
