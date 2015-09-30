//https://www.hackerrank.com/contests/morgan-stanley-2015/challenges/min-con-com
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
int weight[500010];
map<int, int> comp;
struct subset{ int parent,rank;};

inline int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
    subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int main()
{
  int n, q, temp, u, v;
  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i ++)
  {
    scanf("%d", &weight[i]);
    comp[weight[i]] += 1;
  }
  struct subset *subsets = (struct subset*) malloc(n * sizeof(struct subset));
  for (int i = 0; i < n; i++)
  {
      subsets[i].parent = i;
      subsets[v].rank = 0;
  }
  while(q--)
  {
    scanf("%d%d", &u, &v);
    u--; v--;
    if(u > v)
    {
      int temp = u;
      u = v;
      v = temp;
    }
    int x = find(subsets, u), y = find(subsets, v);
    if(x != y)
    {
      int sum = weight[x] + weight[y];
      comp[weight[x]] -= 1;
      if(comp[weight[x]] == 0) comp.erase(weight[x]);
      comp[weight[y]] -= 1;
      if(comp[weight[y]] == 0) comp.erase(weight[y]);
      Union(subsets, x, y);
      x = find(subsets, u);
      weight[x] = sum;
      comp[sum] += 1;
    }
    printf("%d\n", comp.begin()->first);
  }
  return 0;
}
