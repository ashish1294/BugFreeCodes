//http://www.codechef.com/problems/SPOON
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
char mat[500][500];
int main()
{
    int t,n,m,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++) scanf("%s",mat[i]);
        int flag=1;
        for(i=0;i<n && flag;i++)
        {
            for(j=0;j<m;j++)
            {
                if(j<m-4 && (mat[i][j]=='s'||mat[i][j]=='S') && (mat[i][j+1]=='p'||mat[i][j+1]=='P') && (mat[i][j+2]=='o'||mat[i][j+2]=='O') && (mat[i][j+3]=='o'||mat[i][j+3]=='O') && (mat[i][j+4]=='n'||mat[i][j+4]=='N'))
                {
                    flag=0;
                    break;
                }
                else if(i<n-4 && (mat[i][j]=='s'||mat[i][j]=='S') && (mat[i+1][j]=='p'||mat[i+1][j]=='P') && (mat[i+2][j]=='o'||mat[i+2][j]=='O') && (mat[i+3][j]=='o'||mat[i+3][j]=='O') && (mat[i+4][j]=='n'||mat[i+4][j]=='N'))
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag) printf("There is indeed no spoon!\n");
        else printf("There is a spoon!\n");
    }
    return 0;
}
