#include <stdio.h>
#include <string.h>
inline int inp()
{
    int noRead = 0;
    register char p = getchar_unlocked();
    for(;p < 48 || p > 57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int main()
{
    int n, i, j, x, d;
    char s[50];
    long long int c;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        x=0;
        register char p = getchar_unlocked();
        for(;p < 48 || p > 57;p=getchar_unlocked());
        while(p>47 && p<58){ x = (x << 3) + (x << 1) + (p - '0');p=getchar_unlocked();}
        int tt = 0;
        while(x % 10 == 0) tt++, x /= 10;
        c = x;
        d = 0;
        while(x % 5 == 0)
        {
            d++;
            x /= 5;
        }
        while(d > 0)
        {
            c *= 4LL;
            d -= 2;
        }
        printf("%lld", c);
        while(tt--) putchar_unlocked('0');
        putchar_unlocked('\n');
    }
    return 0;
}