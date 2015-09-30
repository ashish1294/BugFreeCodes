#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <stack>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 101000;
int const M = 2001000;
int n, m, k;
struct edges{ int u, next; } e[M];
int p[N], idx;
void addedge(int u, int v) {
  e[idx].u = v, e[idx].next = p[u], p[u] = idx++;
}
void init() { idx = 0; clr(p, 0xff); }
struct SCC
{
  int top, cnt, cc, t;
  int st[N], dfn[N], low[N], col[N]; bool vis[N];
  void tarjan(int u)
  {
    dfn[u] = low[u] = ++cnt;
    st[++top] = u, vis[u] = 1;
    for (int i = p[u]; ~i; i = e[i].next)
    {
      int v = e[i].u;
      if (!dfn[v])
      {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      }
      else if (vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
      do
      {
        t = st[top--];
        col[t] = cc;
        vis[t] = 0;
      } while (t != u);
      ++cc;
    }
  }
  void solve()
  {
    top = cnt = cc = 0;
    clr(vis, 0), clr(col, 0), clr(dfn, 0);
    Rep(i, n) if (!dfn[i]) tarjan(i);
  }
} scc;

bool deg[N];
bool vis[N];
int ans[N];
void dfs(int u)
{
  vis[u] = 1;
  for (int i = p[u]; ~i; i = e[i].next)
  {
    int v = e[i].u;
    if (!vis[v]) dfs(v);
  }
}

class Graph
{
  public:
    int V;    // No. of vertices'

    // Pointer to an array containing adjacency vectorsvector
    vector<int> *adj;

    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

    void init(int V);

     // function to add an edge to graph
    void addEdge(int v, int w);

    // prints a Topological Sort of the complete graph
    void topologicalSort();
};

void Graph::init(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s vector.
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    vector<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    // Push current vertex to stack which stores result
    Stack.push(v);
}

// The function to do Topological Sort. It uses recursive topologicalSortUtil()
vector<int> sorted_nodes, compressed;
vector<vector<int> > scc_nodes;
vector<int> is_req, is_scc_req, ste, ene;
void Graph::topologicalSort()
{
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false)
    {
        if(is_scc_req[Stack.top()])
          sorted_nodes.push_back(Stack.top());
        Stack.pop();
    }
}

Graph gr;

void compress_edges(int par)
{
  //printf("Compressing %d\n", par);
  vector<int> temp;
  for (vector<int>::iterator it = gr.adj[par].begin(); it != gr.adj[par].end(); ++it)
  {
    if(is_scc_req[*it] == 0)
    {
      //printf("found non req edge -> %d\n", *it);
      if(!compressed[*it]) compress_edges(*it);
      for (vector<int>::iterator iit = gr.adj[*it].begin(); iit != gr.adj[*it].end(); ++iit)
      {
        temp.push_back(*iit);
      }
       // gr.addEdge(par, *iit);
      //printf("Parent Now = \n");
    }
  }
  for(int i = 0; i< temp.size(); i++) gr.addEdge(par, temp[i]);
  compressed[par] = 1;
}

int main() {
  int a, b, tc;
  scanf("%d", &tc);
  while (tc--)
  {
    scanf("%d%d%d", &n, &m, &k);
    init();
    is_req.clear();
    is_req.resize(n + 1, 0);
    ste.clear();
    ene.clear();
    rep(i, k) {scanf("%d", &a); is_req[a] = 1;}
    rep(i, m)
    {
      scanf("%d%d", &a, &b);
      ste.push_back(a);
      ene.push_back(b);
      addedge(a, b);
    }
    scc.solve();
    int cc = scc.cc;
    //Rep(i, n) cout << i << " = " << scc.col[i] << endl;
    int max = -1;
    Rep(i, n) { if(scc.col[i] > max) max = scc.col[i];}
    gr.init(max + 1);
    is_scc_req.clear();
    is_scc_req.resize(max + 1, 0);
    scc_nodes.clear();
    scc_nodes.resize(max + 1);
    sorted_nodes.clear();
    Rep(i, n) if(is_req[i]){ is_scc_req[scc.col[i]] = 1; scc_nodes[scc.col[i]].push_back(i);}
    rep(i, ste.size())
    {
        if (scc.col[ste[i]] != scc.col[ene[i]])
        {
          //printf("Adding Edge %d %d\n", scc.col[ste[i]], scc.col[ene[i]]);
          gr.addEdge(scc.col[ste[i]], scc.col[ene[i]]);
          //deg[scc.col[v]] = 1;
        }
    }
    for(int i = 0; i <= max; i++)
    {
      sort( gr.adj[i].begin(), gr.adj[i].end() );
      gr.adj[i].erase( unique( gr.adj[i].begin(), gr.adj[i].end() ), gr.adj[i].end() );
    }
    /*printf("Before Sorting = \n");
    for(int i = 0; i <= max; i++)
    {
      printf("%d -> ", i); for(vector<int>::iterator it = gr.adj[i].begin(); it != gr.adj[i].end(); ++it) printf("%d ", *it); printf("\n");
    }*/
    gr.topologicalSort();
    /*int co;
    clr(vis, 0);
    Rep(u, n) if (!deg[scc.col[u]]) {
      co = scc.col[u];
      dfs(u);
      break;
    }
    bool flag = 1;
    Rep(u, n) if (!vis[u]) {
      flag = 0;
      break;
    }
    if (!flag) puts("-1");
    else {
      int ret = 0;
      Rep(u, n) if (scc.col[u] == co) ans[ret++] = u;
      printf("%d\n", ret);
      rep(i, ret) {
        if (i == ret - 1) printf("%d\n", ans[i]);
        else printf("%d ", ans[i]);
      }
    }*/

    //printf("Sorted Nodes = "); for(int i = 0; i < sorted_nodes.size(); i++) printf("%d ", sorted_nodes[i]); printf("\n");
    int flag_p = 1;
    compressed.clear();
    compressed.resize(max + 1);
    /*printf("Before Compression = \n");
    for(int i = 0; i < sorted_nodes.size(); i++)
    {
      printf("%d -> ", sorted_nodes[i]); for(vector<int>::iterator it = gr.adj[sorted_nodes[i]].begin(); it != gr.adj[sorted_nodes[i]].end(); ++it) printf("%d ", *it); printf("\n");
    }*/
    for(int i = 0; i < sorted_nodes.size(); i++) compress_edges(sorted_nodes[i]);
    /*printf("After Compression\n");
    for(int i = 0; i < sorted_nodes.size(); i++)
    {
      printf("%d -> ", sorted_nodes[i]); for(vector<int>::iterator it = gr.adj[sorted_nodes[i]].begin(); it != gr.adj[sorted_nodes[i]].end(); ++it) printf("%d ", *it); printf("\n");
    }*/
    for(int i = 0; i < sorted_nodes.size() - 1; i++)
    {
      int flag_found = 0;
      for (vector<int>::iterator it = gr.adj[sorted_nodes[i]].begin(); it != gr.adj[sorted_nodes[i]].end(); ++it)
      {
        if((*it) == sorted_nodes[i + 1])
        {
          flag_found = 1;
          break;
        }
      }
      if (flag_found == 0)
      {
        flag_p = 0;
        break;
      }
    }
    if(flag_p)
    {
      for(int i = 0; i < sorted_nodes.size(); i++)
      {
        for(int j = 0; j < scc_nodes[sorted_nodes[i]].size(); j++)
        {
          printf("%d ", scc_nodes[sorted_nodes[i]][j]);
        }
      }
      printf("\n");
    }
    else
    {
      printf("-1\n");
    }
  }
  return 0;
}
