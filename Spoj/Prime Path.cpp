//http://www.spoj.com/problems/PPATH/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
bool arr[10000];
int prindex[10000];
int pr[1100];
vector<vector<int> > g(1100);
int gr[1100][1100];
int np;
int bfs(int a, int b)
{
    int vis[1100],i,aa,path=0,pp[1100],pri=0;
    for(i=0;i<np;i++) {vis[i]=0;pp[i]=-1;}
    queue<int> Q;
    pp[a]=0;
    Q.push(a);
    while(!Q.empty())
    {
        aa=Q.front();
        Q.pop();
        if(aa==b) return pp[b];
        if(vis[aa]<2)
        {
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
    return -1;
}
int main()
{
    int i,j;
    np=0;arr[2]=true;
    for(i=3;i<10000;i++)
    {
        arr[i]=true;
        arr[i+1]=false;
    }
    for(i=3;i<10000;i+=2)
    {
        if(arr[i]==true)
        {
            for(j=i*i;j<10000;j+=i) arr[j]=false;
            if(i>1000)
            {
                pr[np]=i;
                prindex[pr[np]]=np;
                np++;
            }
        }
    }
    int ppp=0;
    for(i=0;i<np;i++)
    {
        gr[i][i]=0;
        for(j=i+1;j<np;j++)
        {
            int a=pr[i],b=pr[j],dif=0;
            while(a>0)
            {
                int dig1=a%10,dig2=b%10;
                a/=10;b/=10;
                if(dig1!=dig2) dif++;
                if(dif>1) break;
            }
            if(dif==1)
            {
                gr[i][j]=gr[j][i]=1;
                g[i].push_back(j);
                g[j].push_back(i);
                ppp++;
            }
        }
    }
    int t,a,b,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        ans = bfs(prindex[a],prindex[b]);
        printf("%d\n",ans);
    }
    return 0;
}
