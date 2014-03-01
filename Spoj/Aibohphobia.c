//http://www.spoj.com/problems/AIBOHP/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define max(a,b) (a>b?a:b)
inline int fs(char *str)
{
    register char c=0;
    register int i=0;
    while(c<33) c=getc(stdin);
    //while(c<33) c=getchar_unlocked();
    while(c!='\n' && c!=' ' && c!=EOF)
    {
        str[i]=c;
        //c=getchar_unlocked();
        c=getc(stdin);
        i++;
    }
    str[i]='\0';
    return i;
};
int dp[2][10000];
char st[10000];
int main()
{
    int t,len,i,j;
    scanf("%d",&t);
    while(t--)
    {
        len=fs(st);
        //scanf("%s",st);
        //len=0;
        //while(st[len]!='\0') len++;
        for(i=0;i<=len;i++) dp[0][i]=dp[1][i]=0;
        for(i=len-1;i>=0;i--)
        {
            for(j=1;j<=len;j++)
            {
                if(st[i]==st[j-1]) dp[1][j]=dp[0][j-1]+1;
                else dp[1][j]=max(dp[0][j],dp[1][j-1]);
            }
            for(j=0;j<=len;j++)
            {
                dp[0][j]=dp[1][j];
            }
        }
        printf("%d\n",len-dp[1][j-1]);
    }
    return 0;
}
