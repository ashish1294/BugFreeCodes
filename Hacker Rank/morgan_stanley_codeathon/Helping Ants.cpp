#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define modp 1000000007
long long int modulo(long long int x, long long int y)
{
    long long int ans;
    if (y==0) return 1;
    if(y==1) return x;
    ans = modulo(x, y / 2);
    ans = ans * ans % modp;
    if (y % 2) ans = ans * x % modp;
    return ans % modp;
}

int main()
{
    int t;
    long long int tinv = modulo(2, modp - 2);
    scanf("%d", &t);
    while(t--)
    {
        long long int n;
        scanf("%lld", &n);
        long long int ans = (13 * modulo(3, n - 2) ) % modp;
        ans = (ans - 1 + modp) % modp;
        ans = (ans * tinv) % modp;
        ans = (ans - modulo(2, n - 1) + modp) % modp;
        printf("%lld\n", ans);
    }
    return 0;
}
