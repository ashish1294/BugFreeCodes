//https://www.codechef.com/OCT15/problems/SUBINC
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294

#include <cstdio>
#include <cstdlib>
#include <algorithm>
int arr[100010];
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        long long int ans = 0, curr = 1;
        scanf("%d", &arr[0]);
        for(int i = 1; i < n; i++)
        {
            scanf("%d", &arr[i]);
            if(arr[i] >= arr[i - 1]) curr++;
            else {ans += (curr * (curr + 1)) >> 1; curr = 1;}
        }
        ans += (curr * (curr + 1)) >> 1;
        printf("%lld\n", ans);
    }
    return 0;
}
