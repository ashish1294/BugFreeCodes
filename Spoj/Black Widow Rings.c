#include<stdio.h>
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a[n],b[n];
        int maxin=-1,maxout=-1,inin,outin;
        for(i=0;i<n;i++)
            scanf("%d%d",&a[i],&b[i]);
        for(i=0;i<n;i++)
            if(a[i]>maxin)
            {
                maxin=a[i];
                inin=i;
            }
        for(i=0;i<n;i++)
            if(b[i]>maxout && i!=inin)
            {
                maxout=b[i];
                outin=i;
            }
        //printf("Maxin=%d inin=%d Maxout=%d outin=%d\n",maxin,inin,maxout,outin);
        if(maxin>maxout)
            printf("%d\n",inin+1);
        else
            printf("-1\n");
    }
    return 0;
}
