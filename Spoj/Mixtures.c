//http://www.spoj.com/problems/MIXTURES/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define min(a,b) (a<b?a:b)
int mix[101];
int dp[101][101];
int col[101][101];

//Fast input Method
inline int inp()
{
    register int noRead=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked());
    for(;p<48 || p>57;p=getc(stdin));
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
int main()
{
    int n,i,j,k,min,val,s;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            //scanf("%d",&mix[i]);
            mix[i]=inp();
            col[i][i]=mix[i];
        }
        dp[0][0]=0;

        //Sieving the final color in range [i....j] for fast access while making dparr
        for(i=0;i<n;i++)
        {
            val=col[i][i];
            for(j=i+1;j<n;j++)
            {
                val+=mix[j];
                col[i][j]=val%100;
            }
        }

        //Main Bottom-up Dp
        for(i=1;i<n;i++)
        {
            for(j=0;j<n-i;j++)
            {
                s=i+j;dp[j][s]=10000000;
                for(k=j;k<s;k++)
                {
                    val=dp[j][k]+dp[k+1][s]+col[j][k]*col[k+1][s];
                    dp[j][s]=min(dp[j][s],val);
                }
            }
        }
        printf("%d\n",dp[0][n-1]);
    }
}
