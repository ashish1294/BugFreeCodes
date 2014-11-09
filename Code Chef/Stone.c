//http://www.codechef.com/MAY14/problems/RRSTONE
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<limits.h>
#define gtc getc(stdin)
//#define gtc getchar_unlocked()
inline int inp()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
int arr[100010];
int main()
{
    int n=inp(),k=inp(),i;
    int ma = INT_MIN, mi = INT_MAX, m=0;
    for(i=0;i<n;i++)
    {
        arr[i] = inp();
        if(arr[i]>ma) ma = arr[i];
        if(arr[i]<mi) mi = arr[i];
    }
    if(k>0 && (k%2==0))
        for(i=0;i<n;i++)
            printf("%lld ",((long long int)arr[i]) - mi);

    else if(k>0)
        for(i=0;i<n;i++)
            printf("%lld ",((long long int)ma) - arr[i]);

    else
        for(i=0;i<n;i++)
            printf("%d ",arr[i]);
    return 0;
}
