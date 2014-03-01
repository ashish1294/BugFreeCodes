//http://www.spoj.com/problems/APS/
//Author Ashish Kedia NITK Surathkal
//@ashish1294
#include<stdio.h>
static long long int arr[10000001];
int main()
{
    long long int i,j;
    for(i=4;i<=10000000;i+=2)
    {
        arr[i]=2;
        arr[i-1]=1;
    }
    arr[2]=2;
    for(i=3;i<=10000000;i=i+2)
    {
        if(arr[i]==1)
        {
            for(j=i*i;j<=10000000;j=j+i)
                if(arr[j]==1)  arr[j]=i;
            arr[i]=i;
        }
    }
    arr[0]=0;arr[1]=0;
    for(i=3;i<=10000000;i++)  arr[i] += arr[i-1];
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",arr[n]);
    }
    return 0;
}
