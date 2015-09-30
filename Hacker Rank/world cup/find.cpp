#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int dp[1000010];
int solve(int n, int a, int b, int c)
{
  //printf("SOlving for %d\n", n);
  if(dp[n] != INT_MAX) return dp[n];
  for(int i = 0; i < n; i++)
  {
    for(int j = i; j <= n; j++)
    {
      //printf("i = %d j = %d n = %d\n", i, j, n);
      int val1, val2, val3;
      if(i == 0) val1 = 0; else val1 = solve(i, a, b, c) + a;
      if(j == i) val2 = 0; else if(j - i == n) continue; else val2 = solve(j - i, a, b, c) + b;
      if(j == n) val3 = 0; else if(j == 0) continue; else val3 = solve(n - j, a, b, c) + c;
      //printf("val 1 = %d\n", val1);
      //printf("val 2 = %d\n", val2);
      //printf("val 3 = %d\n", val3);
      dp[n] = min(dp[n], max(max(val1, val2), val3));
    }
  }
  return dp[n];
}
int main()
{
  int t, a, b, c, n;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d%d%d", &n, &a, &b, &c);
    for(int l = 0; l <= n; l++)
            dp[l] = INT_MAX;
    dp[0] = dp[1] = 0;
    printf("%d\n", solve(n, a, b, c));
    for(int i = 1; i <= n; i++)
    {
      printf("i = %d = %d\n", i, dp[i]);
    }
  }
  return 0;
}
