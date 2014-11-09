#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;
inline int inp()
{
    register int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int main()
{
    long long int n=inp(),x=0,y;
    for(int i=0;i<n;i++)
    {
        x+=inp();
    }
    y=(n*(n+1))/2;
    if(x==y) printf("YES\n");
    else printf("NO\n");
    return 0;
}
