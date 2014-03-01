//http://www.spoj.com/problems/NITK06/

#include<stdio.h>
int main()
{
    int t,n,i,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        long int arr[n];
        for(i=0;i<n;i++)
            scanf("%ld",&arr[i]);
        flag=0;
        for(i=0;i<n-1;i++)
        {
            arr[i+1]=arr[i+1]-arr[i];
            arr[i]=arr[i]-arr[i];
            if(arr[i+1]<0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1 || arr[n-1]!=0 )
            printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
