//http://www.spoj.com/problems/CUTCAKE/
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int g,ans;
        scanf("%lld",&g);
        ans = ceil((sqrt(g+g+g+g+g+g+g+g-7)-1)/2.0);
        printf("%lld\n",ans);
    }
    return 0;
}
