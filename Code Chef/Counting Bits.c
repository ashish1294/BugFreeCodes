//http://www.codechef.com/CDCRFT14/problems/BIT
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int arr[1010];
int main()
{
    int x[10],y[10];
    x[0]=1;x[1]=2;y[0]=3;y[1]=4;
    *x=*y;
    printf("%d %d %d %d",x[0],x[1],y[0],y[1]);
    int i,j,t,n,te;
    arr[1]=1;
    for(i=2;i<=1000;i++)
    {
        te=0;
        for(j=0;j<10;j++)
            if(((1<<j)&i)) te++;
        arr[i]=arr[i-1]+te;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",arr[n]);
    }
    return 0;
}
