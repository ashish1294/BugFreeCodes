/*
    Problem : Chef and Stones
    Link : http://www.codechef.com/JAN15/problems/SEAVOTE
    User : ashish1294
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, s, a, x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        s = 0;
        x = 100;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            s += a;
            if(a) x++;
        }
        if(s >= 100 && s < x) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
