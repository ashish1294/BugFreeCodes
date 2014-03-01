#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
static int arr[310][310];
static dparr[310][310][15];
inline void readint(int *var)
{
    register char ch=0;
    *var=0;
    //Escaping space and Enter characters
    while (ch<33)
        ch=getchar_unlocked();
    //Consider only numerals
    while (ch>47 && ch<58)
    {
        *var=(*var * 10) + (ch-'0');
        ch=getchar_unlocked();
    }
}
//Everything same except long int
inline void readlongint(long int *var)
{
    register char ch=0;
    *var=0;
    while (ch<33)
        ch=getchar_unlocked();
    //Consider only numerals
    while (ch>47 && ch<58)
    {
        *var=(*var * 10) + (ch-'0');
        ch=getchar_unlocked();
    }
}

int main()
{
    int n,i,j,k,x1,y1,x2,y2,count,countans;
    long int q;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            readint(&arr[i][j]);
            //scanf("%d",&arr[i][j]);
        }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=0;k<11;k++)
                dparr[i][j][k]=dparr[i-1][j][k]+dparr[i][j-1][k]-dparr[i-1][j-1][k];
            dparr[i][j][arr[i][j]]++;
        }
    }
    readlongint(&q);
    //scanf("%ld",&q);
    while(q--)
    {
        //scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        readint(&x1);
        readint(&y1);
        readint(&x2);
        readint(&y2);
        countans=0;
        for(k=0;k<11;k++)
        {
            count=dparr[x2][y2][k]+dparr[x1-1][y1-1][k]-dparr[x2][y1-1][k]-dparr[x1-1][y2][k];
            if(count>0)
                countans++;
        }
        printf("%d\n",countans);
    }
    return 0;
}
