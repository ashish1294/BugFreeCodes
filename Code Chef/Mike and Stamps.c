//http://www.codechef.com/MARCH14/problems/MIKE3
//Author - Ashish Kedia, NITK SUrathkal
//@ashish1294
#include<stdio.h>
inline int inp()
{
    int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int pre[20001][21];
int adj[21][21];
int cou[21];
int main()
{
    int n=inp(),m=inp(),i,j,ans=0,tmp,lim=1,myf,inco,k,x;
    for(i=0;i<m;i++)
    {
        tmp=inp();
        for(j=1;j<=tmp;j++)
        {
            x=inp();
            pre[x][i]=1;
            for(k=0;k<i;k++)
                if(pre[x][k] && (!adj[i][k]))
                {
                    adj[i][k]=adj[k][i]=1;
                    cou[i]++;
                    cou[k]++;
                }
        }
        lim*=2;
    }
    for(i=0;i<lim;i++)
    {
        inco=0;myf=1;
        for(j=0;j<m && myf;j++)
            if(i&(1<<j))
            {
                inco++;
                if(cou[j]==0) continue;
                for(k=0;k<j;k++)
                    if ((i&(1<<k)) && adj[j][k])
                    {
                        myf=0;
                        break;
                    }
            }
        if(myf && ans<inco) ans=inco;
    }
    printf("%d\n",ans);
    return 0;
}
