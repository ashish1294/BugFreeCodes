#include<stdio.h>
#include<stdio.h>
int main()
{
    int n,m,r,i,j,k,temp;
    scanf("%d %d %d",&n,&m,&r);
    int coolness[2500];
    int seq[n][m];

    for(j=0;j<2500;j++)
        coolness[j]=-1;
    coolness[42]=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&seq[i][j]);
        }
        for(j=0;j<m;j++)
        {
            if(coolness[seq[i][j]]>=0)
            {
                //printf("%d = %d\n",seq[i][j],coolness[seq[i][j]]);
                for(k=0;k<m;k++)
                {
                    if(k!=j&&(coolness[seq[i][k]]<0||coolness[seq[i][k]]>coolness[seq[i][j]]))
                    {
                        coolness[seq[i][k]]=coolness[seq[i][j]]+1;
                        //printf("cool %d = %d",seq[i][k],coolness[seq[i][k]]);
                    }
                }
            }
        }
        //printf("\n11cool=%d\n",coolness[11]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(coolness[seq[i][j]]>=0)
            {
                //printf("%d = %d\n",seq[i][j],coolness[seq[i][j]]);
                for(k=0;k<m;k++)
                {
                    if(k!=j&&(coolness[seq[i][k]]<0||coolness[seq[i][k]]>coolness[seq[i][j]]))
                    {
                        coolness[seq[i][k]]=coolness[seq[i][j]]+1;
                        //printf("cool %d = %d",seq[i][k],coolness[seq[i][k]]);
                    }
                }
            }
        }
        //printf("\n11cool=%d\n",coolness[11]);
    }
    for(i=0;i<r;i++)
    {
        scanf("%d",&temp);
        printf("%d\n",coolness[temp]);
    }
    //printf("\n");
    return 0;
}
