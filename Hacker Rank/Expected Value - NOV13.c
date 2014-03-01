#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    long int temp;
    long long int sum=0;
    double ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&temp);
        ans = ans + (temp/2);
        if(temp%2!=0)
            ans+=0.5;
    }
    printf("%.1lf\n",ans);
    return 0;
}
