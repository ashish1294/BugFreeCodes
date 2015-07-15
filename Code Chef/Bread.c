#include <stdio.h>
int main()
{
    long long int t, n, k, i, x, d;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld", &n, &k);
        long long int p = 0, curr = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%lld", &x);
            p += (x / k);
            x %= k;
            if (x <= curr)
            {
                curr -= x;
            }
            else
            {
                p++;
                curr = k - x + curr;
            }
            if (curr) curr--;
        }
        printf("%lld\n", p);
    }
    return 0;
}