//http://www.spoj.com/problems/CRNVALEN/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdlib.h>
int arr[10010];
int main()
{
    int t,n,i,x,y,flag;
    long long int sum,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0,sum=0,x=-1,flag=1,y=-1;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]>=n || arr[i]<0) flag=0;
            if(flag && x==-1) x=arr[i];
            else if(flag && y==-1)
            {
                y=arr[i];
                if((x!=(y+1)) && (x!=(y-1))) flag=0;
            }
            else if(flag && arr[i]!=x && arr[i]!=y) flag=0;
            if(flag) sum+=arr[i];
        }
        if(flag)
        {
            if((sum%(n-1))==0)
            {
                ans=sum/(n-1);
                if(ans>n) ans=-1;
            }
            else ans=-1;
        }
        else ans=-1;
        printf("%lld\n",ans);
    }
    return 0;
}
