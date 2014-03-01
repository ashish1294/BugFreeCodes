#include<stdio.h>
#define MAXFLOOR 1000
#define MAXBALL 50
#include<stdio.h>
#define MAXFLOOR 1000
#define MAXBALL 50
int static dparr[MAXBALL][MAXFLOOR];
int max (int a,int b)
{
    return a>b?a:b;
}
void memoize()
{
    int i,j;
    for(i=1;i<MAXFLOOR;i++)
    {
        dparr[1][i]=i;
        dparr[0][i]=0;
    }
    for(i=1;i<MAXBALL;i++)
    {
        dparr[i][1]=1;
        dparr[i][0]=0;
    }
    for(i=2;i<MAXBALL;i++)
    {
        for(j=2;j<MAXFLOOR;j++)
        {
            int k,min=MAXFLOOR,cc;
            for(k=1;k<j;k++)
            {
                int aa=dparr[i-1][k-1];
                int bb=dparr[i][j-k];
                cc=1+max(aa,bb);
                if(cc<min)
                    min=cc;
            }
            dparr[i][j]=min;
        }
    }
}

int main()
{
    memoize();
    int t,b,m,x;
    scanf("%d",&x,&b,&m);
    while(t--)
    {
        scanf("%d%d%d",&b,&b,&m);
        int ans = dparr[b][m];
        printf("%d %d\n",x,ans);
    }
    return 0;
}

int static dparr[MAXBALL][MAXFLOOR];
void memoize()
{
    int i,j;
    for(i=1;i<MAXFLOOR;i++)
    {
        dparr[1][i]=i;
        dparr[0][i]=0;
    }
    for(i=1;i<MAXBALL;i++)
    {
        dparr[i][1]=1;
        dparr[i][0]=0;
    }
    for(i=2;i<MAXBALL;i++)
    {
        for(j=2;j<MAXFLOOR;j++)
        {
            int k,min=MAXFLOOR,cc;
            for(k=1;k<j;k++)
            {
                int aa=dparr[i-1][k-1];
                int bb=dparr[i][j-k];
                cc=1+max(aa,bb);
                if(cc<min)
                    min=cc;
            }
            dparr[i][j]=min;
        }
    }
}


int main()
{
    memoize();
    int t,b,m,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&x,&b,&m);
        int ans = dparr[b][m];
        printf("%d %d\n",x,ans);
    }
    return 0;
}
