//http://www.codechef.com/COOK43/problems/KINGSHIP
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<limits.h>
#include<stdio.h>
#include<algorithm>
#define getchar_unlocked() getc(stdin)
using namespace std;
inline int inp()
{
    register int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int arr[100010];
int main()
{
    int t=inp(),n,i;
    long long int ans,sum,mi;
    while(t--)
    {
        n=inp();
        for(i=0,mi=1000001,sum=0;i<n;i++)
        {
            arr[i]=inp();
            if(arr[i]<mi) mi=arr[i];
            sum+=arr[i];
        }
        ans=mi*(sum-mi);
        printf("%lld\n",ans);
    }
    return 0;
}
