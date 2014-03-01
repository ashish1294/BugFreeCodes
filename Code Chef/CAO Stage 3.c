#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int t,r,c,mon_die_con;
    char arr[21][21];

    char temp[21];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
        {
            fflush(stdin);
            scanf("%s",arr[i]);
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
                if(arr[i][j]=='^')
                    if (((j>1)&&(arr[i][j-1]=='^'||arr[i][j-1]=='m')&&(arr[i][j-2]=='^'||arr[i][j-2]=='m'))||((i>1)&&(arr[i-1][j]=='^'||arr[i-1][j]=='m')&&(arr[i-2][j]=='^'||arr[i-2][j]=='m'))||((j<c-2)&&(arr[i][j+1]=='^'||arr[i][j+1]=='m')&&(arr[i][j+2]=='^'||arr[i][j+2]=='m'))||((i<r-2)&&(arr[i+1][j]=='^'||arr[i+1][j]=='m')&&(arr[i+2][j]=='^'||arr[i+2][j]=='m')))
                        arr[i][j]='m';
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if (arr[i][j]=='m')
                {
                    mon_die_con=0;
                    for(k=0;k<c;k++)
                    {
                        if (arr[i][k]=='m')
                            mon_die_con++;
                        else if ((arr[i][k]=='#'||arr[i][k]=='l')&&(k<j))
                            mon_die_con=0;
                        else if ((arr[i][k]=='#'||arr[i][k]=='l')&&(k>j))
                            break;
                    }
                    for(k=0;k<r;k++)
                    {
                        if (arr[k][j]=='m')
                            mon_die_con++;
                        else if ((arr[k][j]=='#'||arr[k][j]=='l')&&(k<i))
                            mon_die_con=0;
                        else if ((arr[k][j]=='#'||arr[k][j]=='l')&&(k>i))
                            break;
                    }
                }
            }
        }
    }
}
