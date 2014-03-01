//http://www.codechef.com/FEB14/problems/LMATRIX2
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define getchar_unlocked() getc(stdin)
struct rect{
    int uli,ulj,dri,drj;
    int area;
};
int n,m,A[105][105],P[105][105],res[10010][5],ldp[105][105],udp[105][105],kdp[105][105],CO[11];
void ppr(int AA[105][105])
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) printf("%d ",AA[i][j]);
        printf("\n");
    }
}
inline int inp()
{
    register int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int main()
{
    int i,j,co=0,kval,ll,up,left,maxco,maxin,maxf,maxfi,maxfj,lsiz,kpo,fl,a,b,gg= 1;
    n=inp();m=inp();
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            P[i][j]=inp();
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            A[i][j]=inp();
            ldp[i][j]=udp[i][j]=0;
            kdp[i][j]=(P[i][j]-(A[i][j]%P[i][j]));
            if(j!=1 && kdp[i][j]==kdp[i][j-1]) ldp[i][j]=ldp[i][j-1]+1; else ldp[i][j]=1;
            if(i!=1 && kdp[i][j]==kdp[i-1][j]) udp[i][j]=udp[i-1][j]+1; else udp[i][j]=1;

        }
    for(i=n;i>=1;i--)
    {
        for(j=m;j>=1;j--)
        {
            if(A[i][j])
            {
                kval=(P[i][j]-(A[i][j]%P[i][j]));
                lsiz=ldp[i][j];
                maxf=ldp[i][j];
                maxfi=i;
                maxfj=j-ldp[i][j]+1;
                for(kpo=2;kpo<=udp[i][j] && kpo<i+1;kpo++)
                {
                    if(ldp[i-kpo+1][j]<lsiz) lsiz=ldp[i-kpo+1][j];
                    if((lsiz*kpo)>maxf)
                    {
                        maxfi=i-kpo+1;
                        maxfj=j-lsiz+1;
                        maxf=lsiz*kpo;
                    }
                }
                 for(fl=0,a=maxfi;a<=i && fl==0;a++)
                    for(b=maxfj;b<=j && fl==0;b++)
                        if(kval<0 || kdp[a][b]<kval || (kdp[a][b]==0 && (udp[a][b]!=0 || ldp[a][b]!=0))) {fl=1;gg=0;break;}
                if(fl==0)
                {
                    res[co][0]=maxfi;
                    res[co][1]=maxfj;
                    res[co][2]=i;
                    res[co][3]=j;
                    res[co][4]=kval;
                    co++;
                    for(a=maxfi;a<=i;a++)
                        for(b=maxfj;b<=j;b++)
                        {
                            kdp[a][b]-=kval;
                            A[a][b]=(A[a][b]+kval)%P[a][b];
                        }
                }
            }
        }
    }
    for(i=n;i>=1;i--)
    {
        for(j=m;j>=1;j--)
        {
            if(A[i][j] && i==n && j==m)
            {
                kval=(P[i][j]-(A[i][j]%P[i][j]));
                lsiz=ldp[i][j];
                maxf=ldp[i][j];
                maxfi=i;
                maxfj=j-ldp[i][j]+1;
                for(kpo=2;kpo<=udp[i][j] && kpo<i+1;kpo++)
                {
                    if(ldp[i-kpo+1][j]<lsiz) lsiz=ldp[i-kpo+1][j];
                    if((lsiz*kpo)>maxf)
                    {
                        maxfi=i-kpo+1;
                        maxfj=j-lsiz+1;
                        maxf=lsiz*kpo;
                    }
                }
                res[co][0]=maxfi;
                res[co][1]=maxfj;
                res[co][2]=i;
                res[co][3]=j;
                res[co][4]=kval;
                co++;
                for(a=maxfi;a<=i;a++)
                    for(b=maxfj;b<=j;b++)
                    {
                        kdp[a][b]-=kval;
                        A[a][b]=(A[a][b]+kval)%P[a][b];
                    }
            }
            else if(A[i][j])
            {
                kval=(P[i][j]-(A[i][j]%P[i][j]));
                ll=i;
                while(ll && (((A[ll][j]+kval)%P[ll][j])==0)) ll--;
                up=i-ll;
                ll=j;
                while(ll && (((A[i][ll]+kval)%P[i][ll])==0)) ll--;
                left=j-ll;
                if(up>left)
                {
                    ll=i;
                    while(ll && (((A[ll][j]+kval)%P[ll][j])==0)) {A[ll][j]=(kval+A[ll][j])%P[ll][j];ll--;}
                    res[co][0]=ll+1;
                    res[co][2]=i;
                    res[co][1]=res[co][3]=j;
                    res[co][4]=kval;
                    co++;
                }
                else
                {
                    ll=j;
                    while(ll && (((A[i][ll]+kval)%P[i][ll])==0)) {A[i][ll]=(kval+A[i][ll])%P[i][ll];ll--;}
                    res[co][0]=res[co][2]=i;
                    res[co][1]=ll+1;
                    res[co][3]=j;
                    res[co][4]=kval;
                    co++;
                }
            }
        }
    }
    printf("%d\n",co);
    for(i=0;i<co;i++)
        printf("%d %d %d %d %d\n",res[i][0],res[i][1],res[i][2],res[i][3],res[i][4]);
    return 0;
}
