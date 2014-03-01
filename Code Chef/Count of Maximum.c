#include<stdio.h>

int main()
{
    int t,n,temp,i,ma;
    scanf("%d",&t);
    while(t--)
    {
        int a[10001]={0};
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            a[temp] += 1;
        }
        ma = 0;
        for(i=0;i<=10000;i++)
            if (a[i]>a[ma])
                ma=i;

        printf("%d %d\n",ma,a[ma]);
    }
    return 0;
}
