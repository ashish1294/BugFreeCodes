//http://www.spoj.com/problems/AE00/

#include<stdio.h>
static long int arr[10001];
int main()
{
    int i;
    arr[0]=0;
    arr[1]=1;
    arr[2]=1;
    for(i=3;i<=10000;i++)
    {
        if(i%2==0)
            arr[i]=arr[i/2]+1;
        else
            arr[i]=1;
    }
    for(i=2;i<=10;i++)
    {
        arr[i]=arr[i-1]+arr[i];
        //printf("i=%d arr[i]=%ld\n",i,arr[i]);
    }
    int n;
    scanf("%d",&n);
    printf("%ld\n",arr[n]);
    return 0;
}
