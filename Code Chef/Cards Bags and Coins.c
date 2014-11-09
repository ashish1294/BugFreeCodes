//http://www.codechef.com/APRIL14/problems/ANUCBC/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define gtc getchar_unlocked()
#define MOD 1000000009
static long long int ways[105][105],ansdp[105][105],inv[100010],res;
int arr[100010],rem[105];
inline int inp()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
int main()
{
    int t=inp(),n,q,m,i,j,k,r,sum,x;
    inv[1] = 1;
    for(i=2;i<=100000;i++) inv[i] = (-(MOD/i) * inv[MOD%i])%MOD + MOD;
    while(t--)
    {
        n=inp();q=inp();
        for(i=0;i<n;i++) arr[i]=inp();
        for(i=0;i<q;i++)
        {
            m=inp();
            for(j=0;j<=m;j++)
            {
                rem[j]=0;
                for(k=0;k<=m;k++) ways[j][k]=ansdp[j][k]=0;
            }
            for(j=0;j<n;j++)
            {
                x=arr[j]%m;
                if(x<0) x+=m;
                rem[x]++;
            }
            for(j=0;j<m;j++)
                for(k=1,sum=0,res=1,ways[j][0]=1;k<=rem[j];k++)
                {
                    res = (res*(rem[j]-k+1))%MOD;
                    res = (res*inv[k])%MOD;
                    sum = (sum+j)%m;
                    ways[j][sum] = (ways[j][sum] + res)%MOD;
                }

            for(j=0;j<m;j++) ansdp[0][j]=ways[0][j];
            for(j=1;j<m;j++)
                for(k=0;k<m;k++)
                    for(r=0;r<m;r++)
                    {
                        x = (k+r)%m;
                        ansdp[j][x] = (ansdp[j][x] + ((ansdp[j-1][k]*ways[j][r])%MOD))%MOD;
                    }
            printf("%lld\n",ansdp[m-1][0]);
        }
    }
    return 0;
}
