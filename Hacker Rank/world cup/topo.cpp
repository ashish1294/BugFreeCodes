#include<bits/stdc++.h>
#define MAX 100010
using namespace std;
bool visited[MAX], visit[MAX], imp[MAX], visi[MAX], print[MAX], stm[MAX];
int low[MAX],num[MAX],comp[MAX],p[MAX],req[MAX],c,cur;
vector<int> v[MAX],node[MAX],vec[MAX], fin, filter;
stack<int> st;
map< pair<int,int> , bool > mp;
inline int inp()
{
    register int noRead=0;
    register char p=getchar_unlocked();
    //register char p=getc(stdin);
    for(;p<48 || p>57;p=getchar_unlocked());
    //for(;p<48 || p>57;p=getc(stdin));
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
}
void SCC(int x)
{
    //visited[x]=true;
    st.push(x);
    low[x]=num[x]=++c;
    stm[x] = true;
    int i,s;
    for(i=0;i<v[x].size();i++)
    {
        s=v[x][i];
        if(num[s] == -1)
        {
            //p[s]=x;
            SCC(s);
            low[x]=min(low[x],low[s]);
        }
        else if(stm[s]==true)
        low[x]=min(low[x],num[s]);
    }
    if(num[x]==low[x])
    {
        int temp;
        do
        {
            temp=st.top();
            st.pop();
            stm[temp] = false;
            comp[temp]=cur;
            vec[cur].push_back(temp);
        }while(temp!=x);
        cur++;
    }
}
void Fuse(int n)
{
    int i,j,s,r;
    for(i=1;i<=n;i++)
    {
        s=comp[i];
        for(j=0;j<v[i].size();j++)
        {
            r=comp[v[i][j]];
            if(s != r && !mp[make_pair(s,r)])
            {
                node[s].push_back(r);
                mp[make_pair(s,r)] = true;
            }
        }
    }
}

void dfs(int v, stack<int> &Stack)
{
    visit[v] = true;
    vector<int>::iterator it;
    for (it = node[v].begin(); it != node[v].end(); ++it)
        if (!visit[*it])
            dfs(*it, Stack);
    Stack.push(v);
}

void topologicalSort()
{
    stack<int> Stack;
    for (int i = 1; i < cur; i++)
      if (!visit[i])
        dfs(i, Stack);
    while (!Stack.empty())
    {
        fin.push_back(Stack.top());
        Stack.pop();
    }
}
bool DFS(int x, int y)
{
    if(x == y)
        return true;
    visi[x] = true;
    int i, vx;
    bool rs = false;
    for(i = 0; i < node[x].size(); i++)
    {
        vx = node[x][i];
        if(!visi[vx])
            rs |= DFS(vx, y);
    }
    return rs;
}

int main()
{
    int i,j,t,n,x,y,root,m,k;
    t=inp();
    while(t--)
    {
        memset(print,false,sizeof(print));
        n=inp();
        m = inp();
        k = inp();
        for(i = 0; i < k ; i++)
        {
            req[i] = inp();
            print[req[i]] = true;
        }
        memset(visited,false,sizeof(visited));
        memset(visit,false,sizeof(visit));
        memset(stm,false,sizeof(stm));
        memset(imp,false,sizeof(imp));
        memset(p,0,sizeof(p));
        mp.clear();
        fin.clear();
        filter.clear();
        for(i=1;i<=n;i++)
        {
            v[i].clear();
            vec[i].clear();
            node[i].clear();
        }
        for(i = 1; i <= n; i++)
            num[i] = low[i] = -1;
        cur=1;
        for(i=1;i<=m;i++)
        {
            x=inp();
            y=inp();
            v[x].push_back(y);
        }
        c = 0;
        for(i = 1; i <= n; i++)
        {
            if(num[i] == -1)
            {
                //p[i]=i;
                SCC(i);
            }
        }
        Fuse(n);
        /*for(i = 1; i < cur; i++)
        {
            for(j = 0; j < vec[i].size(); j++)
                printf("%d ", vec[i][j]);
            printf("\n");
        }*/
        topologicalSort();
        /*for(i = 0; i < fin.size(); i++)
        {
            printf("%d\n", fin[i]);
        }*/
        for(i = 0; i < k; i++)
        {
            imp[comp[req[i]]] = true;
        }
        for(i = 0; i < fin.size(); i++)
        {
            if(imp[fin[i]])
                filter.push_back(fin[i]);
        }
        for(i = 1; i < filter.size(); i++)
        {
            memset(visi, false, cur + 1);
            if(!DFS(filter[i - 1], filter[i]))
                break;
        }
        if(i != filter.size())
        {
            printf("-1\n");
            continue;
        }
        for(i = 0; i < filter.size(); i++)
        {
            x = filter[i];
            sort(vec[x].begin(), vec[x].end());
            for(j = 0; j < vec[x].size(); j++)
                if(print[vec[x][j]])
                    printf("%d ", vec[x][j]);

        }
        printf("\n");
    }
    return 0;
}
