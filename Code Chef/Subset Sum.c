//http://www.codechef.com/problems/TF01/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
bool dp[1001];
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
    int t,n,k,i,j,fl,tt;
    //scanf("%d",&t);
    t=inp();
    dp[0]=true;
    while(t--)
    {
        //scanf("%d%d",&n,&k);
        n=inp();k=inp();
        for(i=1;i<=k;i++) dp[i]=0;
        fl=1;
        for(i=0;i<n;i++)
        {
            //scanf("%d",&arr[i]);
            tt=inp();
            for(j=k-tt;tt<=k && j>=0 && dp[k]==0;j--)
                dp[j+tt] |= dp[j];
        }
        if(dp[k]) printf("1\n"); else printf("0\n");
    }
    return 0;
}
