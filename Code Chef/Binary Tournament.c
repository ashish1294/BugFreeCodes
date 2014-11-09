//http://www.codechef.com/MARCH14/problems/BINTOUR
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define m 1000000009
long long int fact[1<<20 + 1];
char st[15],sp;
inline int inp()
{
    int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int modulo(int a, int b)
{
    long long int x=1,y=a;
    while(b > 0)
    {
        if(b&1) x=(x*y)%m;
        y = (y*y)%m;
        b /= 2;
    }
    return x%m;
}
int main()
{
    int k=inp(),i,ff;
    int lim=1<<k,slim=1<<(k-1);
    for(i=1;i<slim;i++)
    {
        putchar_unlocked('0');
        putchar_unlocked('\n');
    }

    //Memoization of Factorials
    fact[0]=1;
    for(i=1;i<lim;i++)
        fact[i]=(fact[i-1]*i)%m;

    long long int ans = (lim*fact[slim])%m, inans;
    for(i=slim;i<=lim;i++)
    {
        inans = (fact[i-1]*modulo(fact[i-slim],m-2))%m;
        ff = (inans*ans)%m;
        sp=0;
        while(ff>0)
        {
            st[sp++]= (ff%10) + '0';
            ff/=10;
        }
        sp--;
        while(sp>=0)
            putchar_unlocked(st[sp--]);
        putchar_unlocked('\n');
    }
    return 0;
}
