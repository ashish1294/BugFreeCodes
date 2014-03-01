//http://www.codechef.com/FEB14/problems/TWODOGS/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define getchar_unlocked() getc(stdin)
int h[1000010],ar[500010];
inline int inp()
{
    int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int main()
{
    int n,k,i,lim,x,nl,y,j;
    n=inp();k=inp();
    nl=n/2;
    for(i=0;i<n;i++) ar[i]=inp();
    for(i=0,j=1;i<=nl;i++,j++)
    {
        x=ar[i];y=ar[n-j];
        if((x<k) && h[x]==0 && x!=(k-x))
        {
            if(h[k-x]) break;
            h[x]=j;
        }
        if((y<k) && h[y]==0 && y!=(k-y))
        {
            if(h[k-y]) break;
            h[y]=j;
        }
    }
    if(j>nl+1) puts("-1");
    else printf("%d\n",j);
    return 0;
}
