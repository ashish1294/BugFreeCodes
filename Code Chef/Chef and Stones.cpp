/*
    Problem : Chef and Stones
    Link : http://www.codechef.com/JAN15/problems/CHEFSTON
    User : ashish1294
*/
#include<bits/stdc++.h>
using namespace std;
long long int a[100010], b[100010];
int main()
{
    int t,n,k,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n, &k);
        for(i = 0; i < n; i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i = 0; i < n; i++)
        {
            scanf("%lld",&b[i]);
        }
        long long int ans = 0, temp;
        for(i = 0; i < n; i++)
        {
            temp = (k/a[i]) * b[i];
            //printf("temp = %d\n", temp);
            if(temp > ans) ans = temp;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
