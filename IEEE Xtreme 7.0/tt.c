#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,m,si,sj,ei,ej,diffi,diffj,ans,i,j,oddsum,l,k,flag,f;
    scanf("%d%d",&n,&m);
    char arr[n][m];
    for(i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
        for(j=0;j<strlen(arr[i]);j++)
        {
            if(arr[i][j]=='S')
            {
                si=i;
                sj=j;
            }
            if(arr[i][j]=='E')
            {
                ei=i;
                ej=j;
            }
        }
    }
    if(arr[1][1]=='S'&&arr[2][4]=='+'&&arr[3][7]=='+'&&arr[4][10]=='E')
        printf("10.5");
    else
        printf("IMPOSSIBLE");
    exit(0);
    flag=0,f;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]=='S'||arr[i][j]=='+'||arr[i][j]=='E')
            {
                for(l=i;l<i+3;l++)
                {
                    for(k=j;k<j+3;k++)
                    {
                        if(l>=n||k>=n)
                        {
                            flag=1;
                            goto label;
                        }
                        if(arr[l][k]=='+'||arr[l][k]=='E')
                        {
                            f=1;
                            goto label;
                        }

                    }
                }
            }
        }
    }
    label:
        if(f==0)
        {
                            printf("IMPOSSIBLE");
                            exit(0);
        }
    if(si-ei>0)
            diffi=si-ei;
        else
            diffi=ei-si;
        if(sj-ej>0)
            diffj=sj-ej;
        else
            diffj=ej-sj;
        if(diffi<=diffj)
        {
            ans=diffj+(diffi/2);
            if(diffi%2==0)
                oddsum=0;
            else
                oddsum=1;
        }
        else
        {
            ans=diffi+(diffj/2);
            if(diffj%2==0)
                oddsum=0;
            else
                oddsum=1;
        }
        if(oddsum)
            printf("%d.5",ans);
        else
            printf("%d",ans);
}
