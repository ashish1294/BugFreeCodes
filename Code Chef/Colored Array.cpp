//http://www.codechef.com/FEB14/problems/COLARR/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<algorithm>
int A[1002],B[1002][1002],dp[1001];
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
    register int t=inp(),n,m,k,i,j,suma,pp,ma,po,x,st,en,co;
    while(t--)
    {
        n=inp();m=inp();k=inp();pp=suma=po=0;
        for(i=1;i<=n;i++) A[i]=inp();
        for(i=0;i<=1000;i++) dp[i]=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++) B[i][j]=inp();
            suma+=B[i][A[i]];
        }
        for(i=1,st=0,en=1001,pp=0;i<=n;i++)
        {
            for(j=1,x=0;j<=m;j++)
            {
                ma=inp();
                po=B[i][j]-ma;
                if(po>x) x=po;
            }
            ma=x-B[i][A[i]];
            if(ma>0)
            {
                dp[pp++]=ma;
                //if(ma>st) st=ma;
                //else if(ma<en) en=ma;
            }
        }
        if(k<pp) std::partial_sort(dp,dp+pp-k,dp+pp);
        for(i=pp-1;i>=0 && i>=(pp-k);i--) suma+=dp[i];
        /*for(co=0,po=st;co<k && po>=en;po--)
        {
            if(dp[po]+co<=k)
            {
                co+=dp[po];
                suma+=(dp[po]*po);
            }
            else
            {
                suma+=(k-co)*po;
                break;
            }
        }*/
        printf("%d\n",suma);
    }
    return 0;
}
