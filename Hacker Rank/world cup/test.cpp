#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
vector<int> a;
vector<map<int, int> > dp;
map<int, int> dmap;

long long int ts[50][50];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        a.push_back(t);
        dp.push_back(dmap);
    }
    for(int i = 0; i < a.size(); i++)
    {
        ts[i][i] = a[i];
        for(int j = i + 1; j < a.size(); j++)
        {
            ts[i][j] = ts[i][j - 1] + a[j];
        }
    }

    //New Solution
    dp.push_back(dmap);
    for(int i = a.size() - 1; i >= 0; i--)
    {
        for(int j = i; j < a.size() - 1; j++)
        {
            for(map<int, int>::iterator it = dp[j + 1].begin(); it != dp[j + 1].end(); it++)
            {
                int ele = ts[i][j] ^ it->first;
                dp[i][ele] += it->second;
            }
        }
        dp[i][ts[i][a.size() - 1]] += 1;
    }
    printf("%d\n", dp[0][0]);
    return 0;
}
