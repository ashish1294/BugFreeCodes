//http://www.spoj.com/problems/C1LJUTNJ/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<algorithm>
using namespace std;
#define LL long long int
LL dem[100010];
bool comp(LL a, LL b)
{
    return (a>b);
}
inline int linp()
{
    register LL noRead=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked());
    for(;p<48 || p>57;p=getc(stdin));
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
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
    LL m,diff,ans;
    int n,i,j;
    m=linp();n=inp();
    for(i=0;i<n;i++) dem[i]=linp();
    sort(dem,dem+n,comp);
    dem[n]=0;ans=0;
    for(i=1;i<=n;i++)
    {
        diff= (dem[i-1]-dem[i])*i;
        if(diff<=m)
        {
            m-=diff;
            continue;
        }
        else
        {
            for(j=i;j<n;j++) ans+=(dem[j]*dem[j]);
            dem[i-1] -= (m/i);
            ans += (m%i)*(dem[i-1]-1)*(dem[i-1]-1);
            ans += (i-(m%i))*(dem[i-1]*dem[i-1]);
            break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
