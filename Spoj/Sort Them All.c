//http://www.spoj.com/problems/KIDZEE1E/
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
    int a,b,c,t,tt,i;
    t=inp();
    for(i=1;i<=t;i++)
    {
        a=inp();b=inp();c=inp();
        if(b<a) {tt=b;b=a;a=tt;}
        if(c<a) {tt=c;c=a;a=tt;}
        if(c<b) {tt=c;c=b;b=tt;};
        printf("Case %d: %d %d %d\n",i,a,b,c);
    }
    return 0;
}
