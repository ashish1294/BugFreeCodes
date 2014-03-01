#include<stdio.h>
int main()
{
    long int n;
    long long int i,sum=0;
    scanf("%ld",&n);
    long int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%ld",&arr[i]);
        sum += arr[i];
    }
    long long int temp=0;
    while(sum)
    {
        printf("%lld\n",sum);
        if ((sum&1)==0)
            temp++;
        sum = sum>>1;
    }
    printf("%ld\n",temp);
    return 0;
}
