//http://www.codechef.com/MARCH14/problems/WALK
//Author - Ashish Kedia, NITK SUrathkal
//@ashish1294
#include<stdio.h>
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
    int t=inp(),n,i,ans,x;
    while(t--)
    {
        n=inp();
        ans=inp();
        for(i=1;i<n;i++)
        {
            x=inp()+i;
            if(ans<x) ans=x;
        }
        printf("%d\n",ans);
    }
    return 0;
}
