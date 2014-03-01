#include<stdio.h>
int main()
{
    int t,n;
    long int ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=1;
        while(n)
        {
            ans*=2;
            n--;
            if(n!=0)
            {
                ans+=1;
                n--;
            }
            else
                break;
        }
        printf("%ld\n",ans);
    }
    return 0;
}
