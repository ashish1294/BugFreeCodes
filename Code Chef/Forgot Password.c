//http://www.codechef.com/JUNE14/problems/FORGETPW/
//Author - Ashish Kedia, NITK Surathkal,
//@ashish1294
#include<stdio.h>
#include<string.h>
//#define gtc getchar_unlocked()
#define gtc getc(stdin)
#define ptc(x) putc(x,stdout)
//#define ptc(x) putchar_unlocked(x)
int rule[256], ispre, start, end;
char str[1000010];
inline int inp()
{
    register int noRead=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc);
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    return noRead;
};
inline int inpstr(char * s)
{
    register int i = 0;
    ispre = 0, start = -1;
    register char c = gtc;
    for(;c<33 || c>126;c=gtc);
    while(c>=33 && c<=126)
    {
        s[i++] = rule[c] == 0? c : rule[c];
        if(start == -1 && s[i-1] != '0')
            start = i - 1;
        if(ispre)
        {
            if(s[i-1] != '0')
            {
                end = i - 1;
            }
        }
        else if(s[i-1] == '.')
            ispre = 1, end = i - 2;
        c = gtc;
    }
    if(start == -1)
        start = i;
    if(!ispre)
        end = i - 1;
    s[i] = '\0';
    return i;
}
int main()
{
    int t = inp(), n, i, len;
    char c, p;

    while(t--)
    {
        for(i = 0; i <= 255; i++)
            rule[i] = 0;

        n = inp();
        for(i = 0; i < n; i++)
        {
            c = gtc;
            while(c < 33 || c > 126)
                c = gtc;
            p = gtc;
            while(p < 33 || p > 126)
                p = gtc;
            rule[c] = p;
        }

        len = inpstr(str);
        if(end < start)
            ptc('0');

        for(i = start; i <= end ; i++)
            ptc(str[i]);
        ptc('\n');
    }
    return 0;
}
