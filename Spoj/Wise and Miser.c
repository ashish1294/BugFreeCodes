//http://www.spoj.com/problems/MISERMAN/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
int ar[101][101];
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
int main()
{
    int n,m,i,j,ans;
    n=inp();m=inp();
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            ar[i][j]=inp();
    for(i=1;i<n;i++)
    {
        ar[i][0]+=min(ar[i-1][0],ar[i-1][1]);
        ar[i][m-1]+=min(ar[i-1][m-1],ar[i-1][m-2]);
        for(j=1;j<m-1;j++)
            ar[i][j]+=min(min(ar[i-1][j-1],ar[i-1][j+1]),ar[i-1][j]);
    }
    ans=ar[n-1][0];
    for(i=1;i<m;i++) ans=min(ans,ar[n-1][i]);
    printf("%d\n",ans);
    return 0;
}
