//http://www.spoj.com/problems/SHOP/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<queue>
#include<limits.h>
using namespace std;
struct po{
    int i,j;
};
int dist[100][100],vis[100][100];
int main()
{
    int n,m,i,j;
    po s,d;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0 && m==0) return 0;
        char ar[m][n+1];
        for(i=0;i<m;i++)
        {
            scanf("%s",ar[i]);
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(ar[i][j]=='S') {s.i=i;s.j=j;}
                else if(ar[i][j]=='D') {d.i=i;d.j=j;}
                dist[i][j]=INT_MAX;
                vis[i][j]=0;
            }
        }
        queue<po> Q;
        dist[s.i][s.j]=0;
        vis[s.i][s.j]=1;
        Q.push(s);
        while(!Q.empty())
        {
            struct po aa=Q.front();
            Q.pop();
            if(aa.i==d.i && aa.j==d.j) break;
            if(vis[aa]<2)
            {
                struct po a,b,c,d;
                a.i=c.i=aa.i; b.i=aa.i-1;
                d.i=aa.i+1; a.j=aa.j-1;
                b.j=d.j=aa.j; c.j=aa.j+1;
                if(a.i>0 && a.i<m && a.j>0 && a.j<n)
                {

                }
                for(i=0;i<g[aa].size();i++)
                {
                    if(vis[g[aa][i]]==0)
                    {
                        Q.push(g[aa][i]);
                        vis[g[aa][i]]=1;
                        pp[g[aa][i]]=pp[aa]+1;
                    }
                }
            }
            vis[aa]=2;
        }
    }
    return 0;
}
