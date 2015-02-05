/*
	Problem Name = Majority
	Problem Link = http://www.spoj.com/problems/MAJOR
	User = ashish1294
*/
#include<bits/stdc++.h>

using namespace std;
int a[1000010], b[1000010];
int main()
{
    int t, n, i, j, ans;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < 20001; i++) b[i] = 0;
        ans = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &j);
            b[j + 1000]++;
        }
        for(i = 1; i < 2001; i++)
        {
            if(b[i] > b[ans])
            {
                ans = i;
            }
        }
        if(b[ans] > (n / 2))
        {
            printf("YES %d\n", ans - 1000);
        }
        else printf("NO\n");
    }
    return 0;
}
