//http://www.codechef.com/JUNE14/problems/FUNC
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<climits>
#include<cassert>
#include <bits/stdc++.h>
#define mod 1000000007
long long int a[10010],c[10010];
inline int inp()
{
    int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
inline long long int linp()
{
    register long long int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
inline int ninp()
{
    register int noRead=0, isneg=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked()) if(p=='-') isneg=1;
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    if(isneg) return -noRead;
    else return noRead;
};
int main()
{
    int t = inp(),n,q,i,j;
    //printf("%lld\n",f(1,pow(10,18),16,pow(2,32)));
    long long int ans,temp,x,prev;
    int tc=0;
    while(t--)
    {
        tc++;
        //assert(tc!=10);
        n=inp();q=inp();
        c[0]=0;
        for(i=1;i<=n;i++)
        {
            a[i]=ninp()%mod;
            c[i]=(c[i-1] + a[i])%mod;
        }
        assert(q<=15000);
        int qc= 0;
        while(q--)
        {
            qc++;
            x = linp();
            for(i=1,ans=0;i<=n;i++)
            {
                if(i==1) temp = x;
                else if(i==2) temp = sqrt(x);
                else
                {
                    long double div = 1;
                    div /= ((long double)(i));
                    temp = floor(pow(x,div));
                    if(floor(pow(temp+1,i))<=x)
                    {
                        while(floor(pow(temp+1,i))<=x)
                            temp++;
                    }
                }
                ans += ((temp%mod)*a[i])%mod;
                if(temp==1) break;
            }
            if(i<n) ans += (c[n]-c[i] + mod)%mod;
            ans = ans%mod;
            if(ans<0) ans+=mod;
            printf("%lld ",ans);
        }
        printf("\n");
    }
    return 0;
}
