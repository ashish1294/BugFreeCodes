//http://www.spoj.com/problems/MAXINARR/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
inline int inp()
{
    register int noRead=0;
    register bool neg=false;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked()){if(p=='-')neg=1;};
    for(;p<48 || p>57;p=getc(stdin)){if(p=='-')neg=1;};
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    if(neg) return (-noRead);
    else return noRead;
};
int main()
{
    while(1)
    {
        int n=inp(),t;
        if(n==0) return 0;
        int max=inp();n--;
        while(n--)
        {
            t=inp();
            if(t>max) max=t;
        }
        printf("%d\n",max);
    }
    return 0;
}
