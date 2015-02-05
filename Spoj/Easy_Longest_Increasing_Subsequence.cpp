/*
	Problem Name = Easy Longest Increasing Subsequence
	Problem Link = http://www.spoj.com/problems/ELIS
	User = ashish1294
*/
#include<bits/stdc++.h>

using namespace std;
int arr[100], lis[100];
int main()
{
    int i, n, j, ans = 1;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]), lis[i] = 1;
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                lis[i] = max(lis[i], 1 + lis[j]);
            }
        }
        ans = max(ans, lis[i]);
    }
    printf("%d\n", ans);
    return 0;
}
