//http://www.spoj.com/problems/SPCS/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
char st[100001];
//Fast IO For Strings
inline int fs(char *str)
{
    register char c=0,pr=0;
    register int i = 0;
    //while (c<33) c=getchar_unlocked();
    while (c<33) c=getc(stdin);
    str[i]=c;i++;
    //c=getchar_unlocked();
    c=getc(stdin);
    while (c!='\n')
    {
        str[i]=c;
        if(str[i]!=str[i-1]) i++;
        //c=getchar_unlocked();
        c=getc(stdin);
    }
    str[i] ='\0';
    return i;
};

int main()
{
    int t,len,i,fl;
    scanf("%d",&t);
    while(t--)
    {
        len=fs(st);
        fl=1;
        for(i=0;i<=(len/2);i++)
        {
            if(st[i]!=st[len-1-i])
            {
                fl=0;
                break;
            }
        }
        if(fl) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
