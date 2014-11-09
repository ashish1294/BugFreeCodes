/*
	Problem Name = Let us construct palindrome
	Problem Link = http://www.codechef.com/NOV14/problems/PRPALN
	User = ashish1294
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstdio>
#include<cstring>

using namespace std;
char str[100010];
int main()
{
    int t, i, j, len, lim, ch, ans, sel;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        len = strlen(str);
        lim = len>>1;
        ans = ch = 1;
        sel = i = 0;
        while(i<lim)
        {
            if(str[i]!=str[len-1-i-sel])
            {
                if(sel==0) sel=1;
                else
                {
                    ans = 0;
                    break;
                }
            }
            else i++;
        }
        if(ans == 0)
        {
            sel = i = 0;
            ans = 1;
            while(i<lim)
            {
                if(str[len-1-i] != str[i+sel])
                {
                    if(sel == 0) sel = 1;
                    else
                    {
                        ans = 0;
                        break;
                    }
                }
                else i++;
            }
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
