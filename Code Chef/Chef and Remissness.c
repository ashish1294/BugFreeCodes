//http://www.codechef.com/COOK43/problems/REMISS
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define getchar_unlocked() getc(stdin)
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
    int t=inp(),a,b,ma;
    while(t--)
    {
        a=inp();b=inp();
        if(a>b) ma=a; else ma=b;
        printf("%d %d\n",ma,a+b);
    }
    return 0;
}
