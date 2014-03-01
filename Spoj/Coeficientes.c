//http://www.spoj.com/problems/COEF/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
    int n,k,i,p;
    long long int ans,ar[14];
    ar[0]=1;
    for(i=1;i<=13;i++) ar[i]=ar[i-1]*i;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        ans=ar[n];
        for(i=0;i<k;i++)
        {
            scanf("%d",&p);
            ans /= ar[p];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
