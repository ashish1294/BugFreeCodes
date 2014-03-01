//http://www.spoj.com/problems/KNAPSACK/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294

#include<stdio.h>
#define max(a,b) (a>b?a:b)
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
    int bug,n,i,j;
    //scanf("%d%d",&bug,&n);
    bug=inp();n=inp();
    int fee[n],fun[n],dparr[n+1][bug+1];
    for(i=0;i<n;i++)
    {
        //scanf("%d%d",&fee[i],&fun[i]);
        fee[i]=inp();fun[i]=inp();
        for(j=0;j<=bug;j++) dparr[i][j]=0;
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=bug;j++)
        {
            if(i==0 || j==0) {dparr[i][j]=0;dparr[i][j]=0;}
            else if(fee[i-1]<=j) dparr[i][j]=max(fun[i-1]+dparr[i-1][j-fee[i-1]],dparr[i-1][j]);
            else dparr[i][j]=dparr[i-1][j];
        }
    }
    printf("%d\n",dparr[n][bug]);
    return 0;
}
