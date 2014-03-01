//http://www.codechef.com/DEC13/problems/SMPAINT
//Author - Ashish Kedia
//@ashish1294 NITK Surathkal
#include<stdio.h>
#include<stdbool.h>
//For Windows Platform
//Comment it out in Linux
char getchar_unlocked(){return getc(stdin);}
//Fast Input Function
inline void fast_int(int *x)
{
    int c = getchar_unlocked(); *x = 0;
    while(c<48 || c>57) c = getchar_unlocked();
    for(; c>47 && c<58 ; c = getchar_unlocked())
    { *x = ((*x)<<1) + ((*x)<<3) + c - 48;}
};
static int arr[1001][1001];//Will hold the Actual Array
static bool isp[1001][1001];//True if already painted with right color else false
static int res[1000001][5];//Holds the final result i.e, the calls to be made
static int dp[1001][1001][2];//Oth index holds the similar color element on right. 1st holds towards up
int main()
{
	int i,j,k,l;int n;
	scanf("%d",&n);
	int co=0;
	for(i=0;i<=n;i++){ arr[i][0]=-1;arr[0][i]=-1;}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==0) isp[i][j]=1;
            else
            {
                isp[i][j]=0;
                if(arr[i][j]==arr[i][j-1]) dp[i][j][0]=dp[i][j-1][0]+1; else dp[i][j][0]=1;
                if(arr[i][j]==arr[i-1][j]) dp[i][j][1]=dp[i-1][j][1]+1; else dp[i][j][1]=1;
            }
		}
    for(i=n;i>=1;i--)
        for(j=n;j>=1;j--)
            if(isp[i][j]==0)
            {
                if(dp[i][j][0]>dp[i][j][1])
                {

                }
                res[co][0]=arr[i][j];
                res[co][1]=i-dp[i][j][1]+1;
                res[co][2]=i;
                res[co][3]=j-dp[i][j][0]+1;
                res[co][4]=j;
                co++;
            }
	printf("%d\n",co);
	for(i=0;i<co;i++) printf("%d %d %d %d %d\n",res[i][0],res[i][1],res[i][2],res[i][3],res[i][4]);
	return 0;
}
