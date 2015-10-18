// https://www.codechef.com/OCT15/problems/KSPHERES
// Author - Ashish Kedia
// @ashish1294
#include <cstdio>
#include <cstdlib>
#define mod 1000000007
long long int seq[1010][1010], up[1010], low[1010];
int main()
{
    int n, m, c, t;
    scanf("%d%d%d", &n, &m, &c);
    for(int i = 0; i <= 1000; i++) low[i] = up[i] = 0;
    //printf("n = %d, m = %d, c = %d\n", n, m, c);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        up[t]++;
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &t);
        low[t]++;
    }
    //printf("input done\n"); fflush(stdout);
    for(int i = 0; i <= c + 1; i++) up[i] = (up[i] * low[i]) % mod;
    for(int i = 0; i <= c + 1; i++) seq[0][i] = 1;
    for(int i = 1; i <= c + 1; i++) seq[i][0] = 0;
    for(int i = 1; i <= c + 1; i++)
    {
        for(int j = 1; j <= c + 1; j++)
        {
            seq[i][j] = (seq[i - 1][j - 1] * up[j])%mod + seq[i][j - 1];
            seq[i][j] %= mod;
            //printf("i = %d j = %d seq = %lld tl = %lld up = %d\n", i, j, seq[i][j], seq[i-1][j-1], up[j]);
        }
    }
    // for(int i = 0; i <= c; i++)
    // {
    //     printf("%d = ", i);
    //     for(int j = 0; j <= c; j++)
    //         printf("%lld ", seq[i][j]);
    //     printf("\n");
    // }
    for(int i = 2; i <= c + 1; i++)
    {
        printf("%lld ", seq[i][c]);
    }
    printf("\n");
    return 0;
}
