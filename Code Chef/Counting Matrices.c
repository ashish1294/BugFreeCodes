#include<stdio.h>
#define MAX 1562501
int arr[1562510];
int main()
{
    int t;
    long long int n,i,j,k,co,lim;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        co=0;
        for(i=1,j=n-1;i<n;i++,j--)
        {
            lim=i*j;
            //printf("lim=%lld\n",lim);
            for(k=1;k<lim;k++)
            {
                co += (lim/k) ;
                if(lim%k==0) co--;
            }
        }
        printf("%lld\n",co);
    }
    return 0;
}
