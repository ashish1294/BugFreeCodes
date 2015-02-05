/*
	Problem Name = Tower of Babylon
	Problem Link = http://www.spoj.com/problems/BABTWR
	User = ashish1294
*/
#include<bits/stdc++.h>

using namespace std;
struct cube{
    int x, y, z;
    cube(){}
    cube(int a, int b, int c) { x = a; y = b; z = c;}
};
bool func(cube c, cube d)
{
    if(c.x != d.x) return c.x > d.x;
    if(c.y != d.y) return c.y > d.y;
    return c.z > d.z;
}
vector<cube> v;
int dp[100010];
int main()
{
    int n, i, a, b, c, s, j, ans = 0;
    while(1)
    {
        scanf("%d", &n);
        v.clear();
        ans = 0;
        s = 6 * n;
        if(n == 0) break;
        for(i = 0 ;i < n; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            v.push_back(cube(a, b, c));
            v.push_back(cube(a, c, b));
            v.push_back(cube(b, a, c));
            v.push_back(cube(b, c, a));
            v.push_back(cube(c, b, a));
            v.push_back(cube(c, a, b));
        }
        sort(v.begin(), v.end(), func);
        for(i = 0; i < s; i++)
        {
            dp[i] = v[i].z;
            for(j = 0; j < i; j++)
            {
                if((v[i].x < v[j].x && v[i].y < v[j].y) || (v[i].x < v[j].y && v[i].y < v[i].x) )
                {
                    dp[i] = max(dp[i], dp[j] + v[i].z);
                }
            }
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
