//http://projecteuler.net/problem=38
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int ispandig(int a,int b)
{
    int ar[10]={0},i;
    for(i=0;i<10;i++) ar[i]=0;
    while(a>0)
    {
        if(ar[a%10]!=0) return 0;
        ar[a%10]=1;
        a/=10;
    }
    while(b>0)
    {
        if(ar[b%10]!=0) return 0;
        ar[b%10]=1;
        b/=10;
    }
    for(i=1;i<10;i++) if(ar[i]==0) return 0;
    return 1;
}
int main()
{
    int max,i;
    char arr[20];
    for(i=9000;i<10000;i++)
    {
        if(ispandig(i,i+i)) max=i;
    }
    printf("The Maximum Pan-Digital Number=%d%d\n",max,max+max);
    return 0;
}
