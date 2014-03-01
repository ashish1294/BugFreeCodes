//http://www.spoj.com/problems/SAMER08C/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,m,**arr,*dp1,*dp2,i,j;
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(n==0 && m==0) return 0;
        arr=(int**)malloc(m*sizeof(int*));
        dp1=(int*)malloc(m*sizeof(int));
        dp2=(int*)malloc(n*sizeof(int));
        for(i=0;i<m;i++)
        {
            arr[i]=(int*)malloc(n*sizeof(int));
            for(j=0;j<n;j++)
                scanf("%d",&arr[i][j]);
            dp2[0]=arr[i][0]-arr[i][0];
            if(dp2[0]>0)
            dp2[n-1]=arr[i][n-1]-arr[i][n-2];
            for(j=1;j<n-1;j++) dp2[j]=arr[j]-arr[j-1]-arr[j+1];

        }

    }
}
