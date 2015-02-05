/*
	Problem Name = Tri graphs
	Problem Link = http://www.spoj.com/problems/ACPC10D
	User = ashish1294
*/
#include<bits/stdc++.h>

using namespace std;
long long int arr[100010][3], c[100010][3];
int main()
{
    int t = 0, n, i;
    while(1)
    {
        t++;
        scanf("%d", &n);
        if(n == 0) break;
        for(i = 0 ;i < n; i++)
        {
            scanf("%lld%lld%lld", &arr[i][0], &arr[i][1], &arr[i][2]);
            c[i][0] = c[i][1] = c[i][2] = INT_MAX;
        }
        c[n-1][1] = arr[n-1][1];
        c[n-1][0] = min(c[n-1][0], c[n-1][1] + arr[n-1][0]);
        for(i = n - 2; i >= 0; i--)
        {
            c[i][2] = min(c[i][2], c[i+1][2] + arr[i][2]);
            c[i][2] = min(c[i][2], c[i+1][1] + arr[i][2]);

            c[i][1] = min(c[i][1], c[i+1][0] + arr[i][1]);
            c[i][1] = min(c[i][1], c[i+1][1] + arr[i][1]);
            c[i][1] = min(c[i][1], c[i+1][2] + arr[i][1]);
            c[i][1] = min(c[i][1], c[i][2] + arr[i][1]);

            c[i][0] = min(c[i][0], c[i+1][0] + arr[i][0]);
            c[i][0] = min(c[i][0], c[i+1][1] + arr[i][0]);
            c[i][0] = min(c[i][0], c[i][1] + arr[i][0]);

            //printf("%d => %lld %lld %lld\n", i, c[i][0], c[i][1], c[i][2]);
        }
        printf("%d. %lld\n", t, c[0][1]);
    }
    return 0;
}
