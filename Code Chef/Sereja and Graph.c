//http://www.codechef.com/JAN14/problems/SEAGRP/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define MAX 105
inline int inp()
{
    register int noRead=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked());
    for(;p<48 || p>57;p=getc(stdin));
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
int gr[MAX][MAX],vis[MAX];
void init(n)
{
    int i,j;
    for(i=0;i<=n;i++) {vis[i]=0;for(j=0;j<=n;j++) gr[i][j]=0;}
}
int solve(int totalsize,int size)
{
    int i,j,k;
    if(size==0)   return 1;
    for(i=0;i<totalsize;i++)
    {
        if(!vis[i])
        {
            for(j=0;j<totalsize;j++)
            {
                if(gr[i][j] && !vis[j])
                {
                    vis[i]=1;vis[j]=1;
                    int tt=solve(totalsize,size-2);
                    if(tt) return 1;
                    else {vis[i]=0;vis[j]=0;}
                }
            }
            return 0;
        }
    }
}
int main()
{
    int t,n,m,i,a,b,ma,res,j;
    t=inp();
    //scanf("%d",&t);
    while(t--)
    {
        n=inp();m=inp();
        //scanf("%d%d",&n,&m);
        init(n); ma=-1;
        if((m<(n/2)) || (n%2!=0)) res=0;
        else res=1;
        for(i=0;i<m;i++)
        {
            a=inp();b=inp();
            //scanf("%d%d",&a,&b);
            gr[a-1][b-1]=1;
            gr[b-1][a-1]=1;
        }
        for(i=0;i<n && res;i++)
        {
            for(j=0;j<n;j++) if(gr[i][j]) gr[i][n]++;
            if(gr[i][n]==0) {res=0;break;}
            if(gr[i][n]>ma) {ma=gr[i][n];}
        }
        if(res && ma==1) {res=1;ma=0;}
        else if(res && ma) res=solve(n,n);
        if(res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
