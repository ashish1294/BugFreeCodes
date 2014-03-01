#include<stdio.h>
int main()
{
    int n,m,i,j,l,k,x,y;
    scanf("%d%d",&n,&m);
    int arr[n][m];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) scanf("%d",&arr[i][j]);
    scanf("%d",&l);
    long long int e1=0,e2=0;
    int flag1=1,flag2=1;
    for(k=0;k<l;k++)
    {
        scanf("%d%d",&x,&y);
        if(x<=n && y<=m && flag1) e1 += arr[x-1][y-1];
        else {flag1=0; e1=-1;}
        if (x<=m && y<=n && flag2) e2 += arr[y-1][x-1];
        else {flag2=0;e2=-1;}
        //printf ("e1=%lld e2=%lld\n",e1,e2);
    }
    printf("%lld",e1>e2?e1:e2);
    return 0;
}
