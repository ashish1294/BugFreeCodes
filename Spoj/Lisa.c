//http://www.spoj.com/problems/LISA/
//Author - Ashish Kedia, NITK Surathkal,
//@ashish1294
#include<stdio.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
char st[110];
long long int dpmin[110][110];
long long int dpmax[110][110];
//Fast IO For Strings
inline int fs(char *str)
{
    register char c=0;
    register int i=0;
    while(c<'0' || c>'9')
        //c=getchar_unlocked();
        c=getc(stdin);
    while(c!='\n' && c!=' ')
    {
        str[i]=c;
        //c=getchar_unlocked();
        c=getc(stdin);
        i++;
    }
    str[i]='\0';
    return i;
};
int main()
{
    int t,len,i,j,k,l,ll,r,mint,maxt;
    scanf("%d",&t);
    while(t--)
    {
        len=fs(st);
        for(i=0;i<len;i++)
            for(j=i;j<len;j++)
            {
                dpmax[i][j]=-1;
                dpmin[i][j]=9223372036854775807LL;
            }
        for(ll=1;ll<=len;ll+=2)
        {
            for(i=0;i+ll<=len;i+=2)
            {
                l=i;r=i+ll-1;
                if(l==r)
                {
                    int x= st[l]-'0';
                    dpmax[l][r]=x;
                    dpmin[l][r]=x;
                }
                else
                {
                    for(k=l+1;k<r;k+=2)
                    {
                        if(st[k]=='+')
                        {
                            mint=dpmin[l][k-1]+dpmin[k+1][r];
                            maxt=dpmax[l][k-1]+dpmax[k+1][r];
                        }
                        if(st[k]=='*')
                        {
                            mint=dpmin[l][k-1]*dpmin[k+1][r];
                            maxt=dpmax[l][k-1]*dpmax[k+1][r];
                        }
                        dpmin[l][r]=min(dpmin[l][r],mint);
                        dpmax[l][r]=max(dpmax[l][r],maxt);
                    }
                }
            }
        }
        printf("%lld %lld\n",dpmax[0][len-1],dpmin[0][len-1]);
    }
    return 0;
}
