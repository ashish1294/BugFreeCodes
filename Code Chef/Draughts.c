//http://www.codechef.com/FEB14/problems/DRGHTS
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct edge{
    int v;
    struct edge* next;
};
bool iswin[50010],iscon[50010],vis[50010];
struct edge* gr[50010];
struct edge *head,*newn;
int n,m,dr=0,path=0,par[50010],Q[50010],qin,qout,u,pp;
inline int inp()
{
    int noRead=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked());
    for(;p<48 || p>57;p=getc(stdin));
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
long long int BFS(int src)
{
    qin=-1;qout=0;
    long long int drau=0;
    Q[++qin]=src;
    vis[src]=1;
    par[src]=src;
    drau++;
    while(qin>=qout)
    {
        u=Q[qout++];
        if(iswin[u] && u!=src)
        {
            drau++;
            pp=u;
            while(iscon[pp]==0)
            {
                path++;
                iscon[pp]=1;
                pp=par[pp];
            }
        }
        if(vis[u])
        {
            head = gr[u];
            while(head!=NULL)
            {
                if(vis[head->v]==0)
                {
                    Q[++qin]=head->v;
                    vis[head->v]=1;
                    par[head->v]=u;
                }
                head=head->next;
            }
        }
    }
    return ((drau*(drau-1))/2);
}
int main()
{
    int i,u,v;
    long long int ans=0;
    n=inp();m=inp();
    for(i=1;i<=n;i++) iswin[i]=inp();
    for(i=0;i<m;i++)
    {
        u=inp();v=inp();
        newn=(struct edge*)malloc(sizeof(struct edge));
        newn->v=v;
        newn->next=gr[u];
        gr[u]=newn;
        newn=(struct edge*)malloc(sizeof(struct edge));
        newn->v=u;
        newn->next=gr[v];
        gr[v]=newn;
    }
    for(i=1;i<=n;i++)
        if(vis[i]==0 && iswin[i]==1)
            ans+=BFS(i);

    printf("%lld %d\n",ans,path);
    return 0;
}
