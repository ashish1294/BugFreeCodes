//https://www.codechef.com/OCT15/problems/WDTBAM
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
char a[1010], b[1010];
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%s%s", &n, a, b);
        int corr = 0, ans = INT_MIN, x;
        for(int i = 0; i < n; i++) if(a[i] == b[i]) corr++;
        for(int i = 0; i <= n; i++)
        {
            scanf("%d", &x);
            if(i <= corr && x > ans) ans = x;
        }
        if(corr == n) ans = x;
        printf("%d\n", ans);
    }
    return 0;
}
