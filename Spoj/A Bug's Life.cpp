//http://www.spoj.com/problems/BUGLIFE/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<queue>
#include<stdbool.h>
using namespace std;
int col[2010],vis[2010],n;
vector<vector<int> > gr(2010);
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
};
bool isok(int src)
{
	col[src]=1;
	std::queue <int> q;
	q.push(src);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=1;
		for (int v = 0; v<gr[u].size(); v++)
		{
			if(col[gr[u][v]]==col[u]) return false;
			else if(col[gr[u][v]]==-1)
			{
				col[gr[u][v]]=1-col[u];
				q.push(gr[u][v]);
			}
		}
	}
	return true;
}
int main()
{
	int t=inp(),m,i,a,b,ans,kk;
	for(kk=1;kk<=t;kk++)
	{
		n=inp();m=inp();ans=1;
		for(i=1;i<=n;i++)
		{
			col[i]=-1;vis[i]=0;
			gr[i].clear();
		}
		for(i=0;i<m;i++)
		{
			a=inp();b=inp();
			gr[a].push_back(b);
			gr[b].push_back(a);
		}
		for(i=1;i<=n && ans;i++)
			if(vis[i]==0 && isok(i)==false) ans=0;

		if(ans) printf("Scenario #%d:\nNo suspicious bugs found!\n",kk);
		else 	printf("Scenario #%d:\nSuspicious bugs found!\n",kk);
	}
	return 0;
}
