#include<stdio.h>
int arr1[6][6],arr2[6][6];
int main()
{
    int t,ti,n1,n2,i,j,co,ans;
    scanf("%d",&t);
    for(ti=1;ti<=t;ti++)
    {
        scanf("%d",&n1);
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++)
                scanf("%d",&arr1[i][j]);
        scanf("%d",&n2);
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++)
                scanf("%d",&arr2[i][j]);
        for(i=1,co=0;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                if(arr1[n1][i]==arr2[n2][j])
                {
                    co++;
                    ans=arr1[n1][i];
                    break;
                }
            }
        }
        if(co==0)       printf("Case #%d: Volunteer cheated!\n",ti);
        else if(co==1)  printf("Case #%d: %d\n",ti,ans);
        else            printf("Case #%d: Bad magician!\n",ti);
    }
    return 0;
}
