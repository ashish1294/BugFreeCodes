//http://www.codechef.com/MARCH14/problems/PROSUM
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
    int t=inp(),n,x,i;
    long long int a,b,ans;
    while(t--)
    {
        n=inp();
        a=b=0;
        for(i=0;i<n;i++)
        {
            x=inp();
            if(x>=2)
            {
                a++;
                if(x==2) b++;
            }
        }
        ans = ((a*(a-1))/2) - ((b*(b-1))/2);
        printf("%lld\n",ans);
    }
    return 0;
}
