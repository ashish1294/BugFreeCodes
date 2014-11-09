//http://www.codechef.com/JUNE14/problems/MAXPR/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define mod 1000000007
using namespace std;
int dp[105][205], occ[105];
int modulo(int a,int b)
{
    long long int x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
            x=(x*y)%mod;
        y = (y*y)%mod;
        b /= 2;
    }
    return x%mod;
}
inline int inp()
{
    int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int main()
{
    int i,j,t = inp(),n,aa;
    long long int ans;
    while(t--)
    {
        for( i = 0, n = inp(); i < n; occ[aa]++, i++)
            for( j = 1, aa = inp(); j <= 100; j++)
            {
                int d = aa - j + 100;
                dp[aa][d] = d == 100 ? ((dp[aa][d]<<1) + 1) % mod : ((dp[aa][d] + dp[j][d]) + occ[j]) % mod;
            }

        for( i = 0, ans = 0; i <= 100; occ[i] = 0, i++)
            for( j = 0; j <= 200; j++)
                ans = (ans + dp[i][j]) % mod, dp[i][j] = 0;

        ans=(((modulo(2,n)-1+mod)%mod) - ans + mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
