//http://projecteuler.net/problem=40
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int dig(int a)
{
    if(a<10) return 1;
    if(a<100) return 2;
    if(a<1000) return 3;
    if(a<10000) return 4;
    if(a<100000) return 5;
    if(a<1000000) return 6;
    return 7;
}
int arr[1000000];
int main()
{
    int i,j=0,k;
    for(i=1;;i++)
    {
        int d=i;
        k=j+dig(i)-1;
        while(d>0)
        {
            arr[k--]=d%10;
            d/=10;
        }
        j+=dig(i);
        if(j>1000000) break;
    }
    long long int ans = arr[0]*arr[9]*arr[99]*arr[999]*arr[9999]*arr[99999]*arr[999999];
    printf("%lld\n",ans);
    return 0;
}
