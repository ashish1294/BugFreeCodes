//http://www.codechef.com/problems/NAME2/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<string.h>
char m[30000],w[30000];
inline void fs(char *str)
{
    register char c = 0;
    register int i = 0;
    //while (c<33) c=getchar_unlocked();
    while (c<33) c=getc(stdin);
    while (c!='\n' && c!=' ')
    {
        str[i]=c;
        c=getc(stdin);
        //c=getchar_unlocked();
        i++;
    }
    str[i] ='\0';
};
int main()
{
    int t,i,lm,lw,ans,j;
    scanf("%d",&t);
    while(t--)
    {
        fs(m);fs(w);
        //scanf("%s%s",m,w);
        ans=0;lm=strlen(m);lw=strlen(w);
        for(i=0,j=0;i<lm && j<lw;i++)
            if(m[i]==w[j]) j++;
        if(j==lw) ans=1;
        for(i=0,j=0;ans==0 && i<lw && j<lm;i++)
            if(w[i]==m[j]) j++;
        if(j==lm) ans=1;
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
