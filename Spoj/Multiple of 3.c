//http://www.spoj.com/problems/KIDZEE1C/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
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
    int a[1006],i,t,n;
    for(i=0;i<=1000;i+=3)
    {
        a[i]=1;a[i+1]=0;a[i+2]=0;
    }
    t=inp();
    while(t--)
    {
        n=inp();
        if(a[n]) printf("%d is a multiple of 3\n",n);
        else printf("%d is not a multiple of 3\n",n);
    }
    return 0;
}
