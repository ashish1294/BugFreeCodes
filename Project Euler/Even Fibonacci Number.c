#include<stdio.h>
static int arr[1000000],i;
int main()
{
    arr[0]=0;
    arr[1]=1;
    long long int sum=0;
    for(i=2;;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
        if(arr[i]>=4000000)
            break;
        if(arr[i]%2==0)
            sum += arr[i];
    }
    printf("%lld",sum);
    return 0;
}
