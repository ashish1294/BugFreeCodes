//http://www.codechef.com/FEB14/problems/COLARR/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
//#define gtc getchar_unlocked()
//#define ptc(xx) putchar_unlocked(xx)
#define gtc getc(stdin)
#define ptc(xx) putc(xx,stdout)
int A[1002],B[1002][1002],dp[1001];
char stk[50];
inline int inp()
{
    register int noRead=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc);
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    return noRead;
};
int main()
{
    int t=inp(),n,m,k,i,j,suma,ma,po,x,co,sp,pp,mi;
    while(t--)
    {
        n=inp();m=inp();k=inp();suma=po=pp=0;
        for(i=1;i<=n;i++) A[i]=inp();
        for(i=1;i<=n;i++)
        {
            dp[i]=0;
            for(j=1;j<=m;j++) B[i][j]=inp();
            suma=suma+B[i][A[i]];
        }
        for(;i<=1000;i++) dp[i]=0;
        for(i=1;i<=n;i++)
        {
            for(j=1,x=0;j<=m;j++)
            {
                ma=inp();
                po=B[i][j]-ma;
                if(po>x) x=po;
            }
            ma=x-B[i][A[i]];
            if(pp<k || ma>mi)
            {
                dp[ma]=dp[ma]+1;
                if(ma<mi) mi=ma;
                pp=pp+1;
            }
        }
        for(co=0,po=1000;co<k && po>=1;po--)
        {
            co=co+dp[po];
            suma=suma+(dp[po]*po);
        }
        if(co>k) suma=suma-((co-k)*(po+1));
        sp=0;
        while(suma)
        {
            stk[sp++]= (suma%10)+'0';
            suma/=10;
        }
        while(sp>0) ptc(stk[--sp]);
        ptc('\n');
    }
    return 0;
}
