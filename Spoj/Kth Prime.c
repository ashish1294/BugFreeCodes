//http://www.spoj.com/problems/TDKPRIME/
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
#define getchar_unlocked() getc(stdin)
#define putchar_unlocked(x) putc(x,stdout)
#define MAX 86028200
#define LMT 9280
#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))
int flag[MAX>>6],sp=0;
char stk[30];
static long long int primes[5000001];
void sieve()
{
    register int i, j, k,np=0;
    primes[np++]=2;
    for(i = 3; i < LMT; i+=2)
        if(!ifc(i))
        {
            for(j=i*i,k=i<<1;j<MAX;j+=k)
            isc(j);
            primes[np++]=i;
        }
    for(;i<MAX;i=i+2)
        if(!ifc(i)) primes[np++]=i;
}
inline int inp()
{ int noRead=0;
  register char p=getchar_unlocked();
  for(;p<33;p=getchar_unlocked());
  while(p>32){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');
  p=getchar_unlocked();}return noRead;
};
inline ppr(long long int xx)
{
    sp=0;
    while(xx>0)
    {
        stk[sp++]=(xx%10)+'0';
        xx/=10;
    }
    sp--;
    while(sp>=0) {putchar_unlocked(stk[sp]);sp--;}
    putchar_unlocked('\n');
}
int main()
{
    sieve();
    int q=inp(),n;
    while(q--)
    {
        n=inp();
        ppr(primes[n-1]);
    }
    return 0;
}
