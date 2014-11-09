#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
int s[1010][1010], d[1000010], a[1000010];
int main()
{
	int t, n;
	scanf("%d",&t);
    for(int tt = 1; tt <= t; tt++)
    {
        scanf("%d",&n);
        for(int i =0 ; i <= n*n; i++)
        {
            d[i] = a[i] = 0;
        }
        for(int i = 0; i < n; i++)
        {

            for(int j = 0; j < n; j++)
            {
                scanf("%d",&s[i][j]);
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if( (j < (n-1)) && (s[i][j] == s[i][j+1] + 1)) d[s[i][j+1]] = 1;
                if( (j > 0) && (s[i][j] == s[i][j-1] + 1)) d[s[i][j-1]] = 1;
                if( (i < (n-1)) && (s[i][j] == s[i+1][j] + 1)) d[s[i+1][j]] = 1;
                if( (i > 0) && (s[i][j] == s[i - 1][j] + 1)) d[s[i-1][j]] = 1;
            }
        }
        int ans = 1, ind = 1;
        a[0] = a[1] = 1;
        for(int i = 1; i < (n*n); i++ )
        {
            if(d[i]==0)
            {
                a[i+1] = 1;
            }
            else a[i + 1] = a[i] + 1;
            if(a[i + 1] > a[ans])
            {
                ans = i+1;
            }
        }
        printf("Case #%d: %d %d\n",tt, ans - a[ans] + 1, a[ans]);

    }
	return 0;
}

