#include<stdio.h>
static double arr[1000001];
int main()
{
    int i;
    arr[1]=1.0;
    for(i=2;i<=1000000;i++)
        arr[i]=arr[i-1]+((double)1/i);
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lf\n",arr[n]);
    }
    return 0;
}
