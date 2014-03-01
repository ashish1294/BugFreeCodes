//http://www.spoj.com/problems/ASCDFIB/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int fib[1100001];
int arr[100001];
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
    int i,t,j,a,b,si,k,l,lim;
    t=inp();
    fib[1]=0;fib[2]=1;
    for(i=3;i<=1100000;i++) fib[i]=(fib[i-1]+fib[i-2])%100000;
    for(i=1;i<=t;i++)
    {
        a=inp();b=inp();
        //for(j=0;j<100000;j++) arr[j]=0;
        for(j=a;j<=a+b;j++) arr[fib[j]]++;
        lim=100;j=0;k=0;
        if(b+1<100) lim=b+1;
        printf("Case %d:",i);
        while(j<lim)
        {
            while(arr[k]==0) k++;
            for(l=0;l<arr[k] && j<lim;l++,j++) printf(" %d",k);
            k++;
        }
        printf("\n");
    }
    return 0;
}
