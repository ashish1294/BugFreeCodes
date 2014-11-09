//http://www.spoj.com/problems/TRIISO/
//Author - Ashish Kedia
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
#define getchar_unlocked() getc(stdin)
#define putchar_unlocked(x) putc(x,stdout)
bool arr[1000010];
inline int inp()
{
    int noRead=0;
    register char p=getc(stdin);
    for(;p<48 || p>57;p=getc(stdin));
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
int main()
{
    int i,j,t=inp(),n,x,k;
    for(i=1;i<=1000;i++)
        for(j=i+1;j<=1000;j++)
        {
            x=(i*i)+(j*j);
            if(x<=1000000) for(k=1;k<=(1000000/x);k++) arr[x*k]=true;
            else break;
        }
    while(t--)
    {
        n=inp();
        if(arr[n])
        {
            putchar_unlocked('Y');
            putchar_unlocked('E');
            putchar_unlocked('S');
        }
        else
        {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
