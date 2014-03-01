#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long int n,i;
        scanf("%ld",&n);
        long int arr[n];
        long long int sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&arr[i]);
            sum += arr[i];
        }
        if(sum%n==0)
            printf("%ld\n",n);
        else
            printf("%ld\n",n-1);
    }
    return 0;
}
