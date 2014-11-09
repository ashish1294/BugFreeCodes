/*
	Problem Name = Distinct Characters Subsequence
	Problem Link = http://www.codechef.com/NOV14/problems/DISCHAR
	User = ashish1294
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstdio>
using namespace std;
char str[100010];
int main()
{
    int t, i, pre[26], co;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        for(i = 0; i < 26; i++)
        {
            pre[i] = 0;
        }
        i = 0;
        while(str[i]!='\0')
        {
            pre[str[i++]-'a'] = 1;
        }
        for(i = 0, co= 0; i < 26; i++)
        {
            co += pre[i];
        }
        printf("%d\n",co);
    }
    return 0;
}
