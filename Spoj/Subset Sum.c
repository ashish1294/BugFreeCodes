//http://www.spoj.com/problems/MAIN72/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
int arr[100];
bool dp[100001];
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
    int t,n,i,lim,sum,j;
    t=inp();
    dp[0]=true;
    while(t--)
    {
        //scanf("%d",&n);
        n=inp();
        lim=0;sum=0;
        for(i=0;i<n;i++)
        {
            //scanf("%d",&arr[i]);
            arr[i]=inp();
            lim+=arr[i];
        }
        for(i=1;i<=lim;i++) dp[i]=0;
        for(i=0;i<n;i++)
        {
            for(j=lim;j>=arr[i];j--)
            {
                dp[j] |=dp[j-arr[i]];
            }
        }
        sum=0;
        for(i=1;i<=lim;i++) if(dp[i]) sum+=i;
        printf("%d\n",sum);
    }
    return 0;
}
