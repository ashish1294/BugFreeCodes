//http://www.codechef.com/CODX2014/problems/REN2013K
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<math.h>
int main()
{
    int t,a,b;
    long long int ans,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        n=b-a;
        ans = 1LL*(n)*(n+1);
        ans /=2;
        printf("%lld\n",ans);
    }
    return 0;
}
