//http://www.spoj.com/problems/DCRYPT/
#include<stdio.h>
#include<ctype.h>
int main()
{
    int t,k;
    long int i;
    char s[1000000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        scanf("%s",s);
        i=0;
        while(s[i]!='\0')
        {
            if(s[i]=='.')
            {
                s[i]=' ';
                i++;
                continue;
            }
            if(isupper(s[i]))
            {
                int pos = s[i]-'A';
                pos +=k;
                pos = pos % 26;
                s[i]=(char)(pos + 'A');
            }
            else
            {
                int pos = s[i]-'a';
                pos +=k;
                pos = pos%26;
                s[i] = (char)(pos + 'a');
            }
            if (k>25)
            {
                if(islower(s[i]))
                    s[i]=toupper(s[i]);
                else
                    s[i]=tolower(s[i]);
            }
            i++;
        }
        printf("%s\n",s);
    }
    return 0;
}
