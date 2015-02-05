/*
	Problem Name = Non-Decreasing Digits
	Problem Link = http://www.spoj.com/problems/NY10E
	User = No User
*/
#include<bits/stdc++.h>

using namespace std;
/*
dp[i][j] represents number of valid nums whose least dig >= j and has i digits
so Ans for i = di[i][0]. Table fill up by iterative method
*/
long long int dp[65][10];
int main()
{
    int t, n, x, i, j;
    for(i = 0 ; i < 10; i++) dp[0][i] = 1;
    for(i = 1; i < 65; i++)
    {
        dp[i][9] = dp[i - 1][9];
        for(j = 8; j >= 0; j--)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
        }
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &x, &n);
        printf("%d %lld\n", x, dp[n][0]);
    }
    return 0;
}
