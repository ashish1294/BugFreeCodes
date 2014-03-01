//http://www.codechef.com/JAN14/problems/PLZLYKME
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
    int t=inp(),l,d,s,c,i,fl;
    long long int a;
    while(t--)
    {
        l=inp();d=inp();s=inp();c=inp();
        c++;
        a=s;fl=0;
        if(d>1 && c>=l) {fl=1;}
        for(i=1;i<d && fl==0;i++)
        {
            if(a>=l){break;fl=1;}
            a*=c;
        }
        if(a>=l){fl=1;}
        if(fl) printf("ALIVE AND KICKING\n");
        else printf("DEAD AND ROTTING\n");
    }
    return 0;
}
