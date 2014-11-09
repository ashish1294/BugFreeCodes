//http://www.codechef.com/APRIL14/problems/BINTREE
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
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
    int i,j,t=inp(),k,co,sp,stk[20];
    while(t--)
    {
        i=inp(),j=inp();
        co=0;
        while(i!=j)
        {
            while(j>i)
            {
                j/=2;
                co++;
            }
            while(i>j)
            {
                i/=2;
                co++;
            }
        }
        if(co==0) putchar_unlocked('0');
        else
        {
            sp=0;
            while(co)
            {
                stk[sp++]=co%10+ '0';
                co/=10;
            }
            sp--;
            while(sp>=0) putchar_unlocked(stk[sp--]);
        }
        putchar_unlocked('\n');
    }
    return 0;
}
