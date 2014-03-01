//http://projecteuler.net/problem=17
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int i,j,arr[100][100];
    for(i=0;i<100;i++)
        for(j=0;j<=i;j++)
            scanf("%d",&arr[i][j]);
    for(i=98;i>=0;i--)
    {
        for(j=0;j<=i;j++)
            arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
    }
    printf("%d",arr[0][0]);
    return 0;
}
