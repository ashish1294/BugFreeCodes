/*
    Problem : Chef and Stones
    Link : http://www.codechef.com/JAN15/problems/CLPERM
    User : ashish1294
*/
#include<bits/stdc++.h>
using namespace std;
long long int a[100010];
int main()
{
    int t, n, k, i;
    long long int m, ans;
    a[0] = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        bool flag = true;
        m = ans = 0;
        for(i = 1; i <= k; i++)
        {
            scanf("%lld", &a[i]);
        }
        sort(a + 1, a + k + 1);
        for(i = 1 ; i <= k && flag; i++)
        {
            m +=  (((a[i] - 1) * a[i]) / 2) - (((a[i - 1] + 1) * a[i - 1]) / 2);
            if(a[i] > m)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            flag = false;
            m += ((n * (n+1) ) / 2) - ((a[k] * (a[k] + 1)) / 2);
        }
        m++;
        if(m % 2 == 0)
        {
            printf("Mom\n");
        }
        else printf("Chef\n");
        //printf("m = %lld\n", m);
    }
    return 0;
}
