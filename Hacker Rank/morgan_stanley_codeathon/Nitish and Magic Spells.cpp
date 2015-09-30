#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> gr1[10010], gr2[10010];
int cost[10010], par[10010], ccost[10010];
int visit(int src)
{
  //printf("visit %d\n", src);
  if(gr2[src].size() == 0)
  {
    par[src] = src;
    ccost[src] = cost[src];
  }
  if(ccost[src] != INT_MIN) return ccost[src];
  ccost[src] = cost[src];
  int ma = INT_MIN;
  for(int i = 0; i < gr2[src].size(); i++)
  {
    //printf("sending v = %d\n", gr2[src][i]);
    int val = visit(gr2[src][i]);
    if(val > ma)
    {
      par[src] = gr2[src][i];
      ma = val;
    }
  }
  if(ma > 0) ccost[src] += ma;
  else par[src] = src;
  //printf("visit %d ccost = %d par = %d\n", src, ccost[src], par[src]);
  return ccost[src];
}

int main()
{
  int t, n, m, k, u, v;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++)
    {
      scanf("%d", &cost[i]);
      par[i] = INT_MIN;
      ccost[i] = INT_MIN;
      gr1[i].clear();
      gr2[i].clear();
    }
    for(int i = 0; i < n - 1; i++)
    {
      scanf("%d%d", &u, &v);
      gr1[u].push_back(v);
      gr2[v].push_back(u);
    }
    for(int i = 0; i < n; i++)
    {
      //printf("gr size %d = %lu\n", i, gr1[i].size());
      if(gr1[i].size() == 0)
      {
        //printf("Leaf = %d\n", i);
        visit(i);
      }
    }
    int maxin = 0;
    for(int i = 1; i < n; i++)
    {
      if(ccost[maxin] < ccost[i]) maxin = i;
    }
    //printf("Maxin = %d ccost = %d par = %d\n", maxin, ccost[maxin], par[maxin]);
    vector<long long int> ans;
    ans.push_back(cost[maxin]);
    while(maxin != par[maxin])
    {
      maxin = par[maxin];
      ans.push_back(cost[maxin]);
    }
    sort(ans.begin(), ans.end());
    //for(int i = 0; i < ans.size(); i++) printf("ans[%d] = %d\n", i, ans[i]);
    int in = ans.size() - 1;
    long long int fans = 0;
    while(in >= 0)
    {
      if(ans[in] > 0 && k)
      {
        fans += m * ans[in];
        k--;
      }
      else fans += ans[in];
      in--;
    }
    printf("%lld\n", fans);
  }
  return 0;
}
