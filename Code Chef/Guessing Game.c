#include<stdio.h>
long long int gcd(long long int a, long long int b)
{
    return (b == 0 ? a: gcd(b, a%b));
}
int main()
{
    int t;
    long long int n, m, om, em, on, en, ans, total, g;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%lld%lld", &n, &m);

        om = ((m + 1) >> 1);
        em = m - om;

        on = ((n + 1) >> 1);
        en = n - on;

        ans = (om * en) + (on * em);
        total = m * n;

        g = gcd(ans, total);

        ans /= g;
        total /= g;

        printf("%lld/%lld\n", ans, total);
    }
    return 0;
}
