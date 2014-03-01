//http://www.spoj.com/problems/CIRCLE_E/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<math.h>
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
    int t=inp(),a,b,c;
    double r1,r2,r3,r;
    while(t--)
    {
        a=inp();b=inp();c=inp();
        r1=a;r2=b;r3=c;
        r = 1/((1/r1)+(1/r2)+(1/r3)+(2*sqrt( (1/(r1*r2)) + (1/(r1*r3)) + (1/(r2*r3)))));
        printf("%.6lf\n",r);
    }
    return 0;
}
