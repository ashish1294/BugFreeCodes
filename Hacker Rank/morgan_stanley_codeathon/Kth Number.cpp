
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

/*
  Persistent Segment Tree !!
  Credits : Anudeep's Blog
*/
struct node
{
  int co;
  node *left, *right;

  node(int co, node *left, node *right):
    co(co), left(left), right(right) {}
  node* insert(int l, int r, int w);
};
node *null = new node(0, NULL, NULL);
node * node::insert(int l, int r, int w)
{
  if(l <= w && w < r)
  {
    if(l+1 == r) return new node(this->co+1, null, null);
    int m = (l+r)>>1;
    return new node(this->co+1, this->left->insert(l, m, w), this->right->insert(m, r, w));
  }
  return this;
}

int query(node *a, node *b, int l, int r, int k)
{
  if(l+1 == r) return l;
  int m = (l+r)>>1;
  int count = a->left->co - b->left->co;
  if(count >= k)
    return query(a->left, b->left, l, m, k);
  return query(a->right, b->right, m, r, k-count);
}

int RM[1000010];
node *root[1000010];
vector<pair<int, int> > arr;
vector<int> test, org;
int main()
{
  int n1, q1, t1;
  map <int, int> M;
  scanf("%d%d", &n1, &q1);
  for(int i = 0; i < n1; i++)
  {
    scanf("%d", &t1);
    org.push_back(t1);
    test.push_back(t1);
    arr.push_back(make_pair(t1, i));
  }
  sort(arr.begin(), arr.end());
  sort(test.begin(), test.end());
  for(int i = 0; i < n1; i++)
  {
    //printf("Ele acc = %d\n", arr[i].second);
    M[arr[i].second];
  }

  int maxi = 0;

  for(map <int, int> :: iterator it = M.begin(); it != M.end(); it++)
  {
    M[it->first] = maxi;
    //printf("%d = %d\n", it->first, maxi);
    RM[maxi] = it->first;
    maxi++;
  }

  null->left = null->right = null;
  for(int i = 0; i < n1; i++) root[i] = (i == 0 ? null : root[i-1])->insert( 0, maxi, M[arr[i].second] );
  while(q1--)
  {
    int l, k;
    scanf("%d%d", &l, &k);
    int u = (lower_bound(test.begin(), test.end(), l) - test.begin());
    int ans = query(root[n1 - 1], (u == 0 ? null:root[u - 1]), 0, maxi, k);
    //printf("Querying u = %d v = %d k = %d ans = %d aa = %d\n", u, n1 - 1, k, RM[ans], ans);
    printf("%d\n", org[RM[ans]]);
  }
  return 0;
}
