#include<stdio.h>
static int arr[1000001];
static long int sum[1000001];
stat
int main()
{
    long int n,q,i,from,to;
    long long int sumans;
    char op;
    scanf("%ld%ld",&n,&q);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sum[0]=arr[0];
    for(i=1;i<n;i++)
        sum[i]=arr[i]+sum[i-1];
    while(q--)
    {
        scanf("%c",&op);
        while(op!='S' && op!='G' && op!='T')
        {
            scanf("%c",&op);
        }
        scanf("%ld%ld",&from,&to);
        switch(op)
        {
            case 'S':   if(from==0)
                            sumans=sum[to];
                        else
                            sumans=sum[to]-sum[from-1];
                        printf("%ld\n",sumans);
                        break;
            case 'G':   for(i=from;i<n;i++)
                            sum[i]=sum[i]+to;
                        break;
            case 'T':   for(i=from;i<n;i++)
                            sum[i]=sum[i]-to;
                        break;
        }
    }
    return 0;
}
