//http://www.codechef.com/CODX2014/problems/REN2013G
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
int cost[1010][1010],minc[1010];
bool visited[1010];
int arr[1010][2];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    arr[0][0]=arr[0][1]=cost[0][0]=visited[0]=minc[0]=0;
    for(i=1;i<=n+1;i++)
    {
        scanf("%d%d",&arr[i][0],&arr[i][1]);
        for(j=0;j<=i;j++)
            cost[i][j]=cost[j][i]=((arr[i][0]-arr[j][0])*(arr[i][0]-arr[j][0])) + ((arr[i][1]-arr[j][1])*(arr[i][1]-arr[j][1]));
        visited[i]=0;
    }

    //Dijkstra's Algorithm
    for(i=0;i<=n+1;i++) minc[i]=cost[0][i];
    for(i=0;i<=n+1;i++)
    {
        int minin,minval=INT_MAX;
        for(j=0;j<=n+1;j++)
            if(visited[j]==0 && minc[j]<minval)
            {
                minval=minc[j];
                minin=j;
            }
        visited[minin]=1;
        for(j=0;j<=n+1;j++)
            if (visited[j]==0 && minc[minin]+cost[minin][j]<minc[j])
                minc[j]=minc[minin]+cost[minin][j];
    }
    printf("%d\n",minc[n+1]);
    return 0;
}
