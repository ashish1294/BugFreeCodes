/*
    Author: Ashish Kedia (ashish1294)
    National Institute of Technology Karnataka, Surathkal
*/
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <map>

using namespace std;
int arr[1010];
long double rarr[1010];
int main()
{
    int t, tc, n, m, i, j, k, l, r;
    scanf("%d", &tc);
    for(t = 1; t <= tc; t++)
    {
    	scanf("%d%d", &n, &m);
    	for(i = 0; i < n; i++)
    	{
    		scanf("%d", &arr[i]);
    		rarr[i] = std::cbrt(((long double)arr[i]));
    	}
    	printf("Case #%d:\n", t);
    	for(i = 0; i < m; i++)
    	{
    		scanf("%d%d", &l, &r);
    		long double ans = 1;
    		double ex = r - l + 1;
    		ex = 1/ ex;
    		//printf("ex = %lf\n", ex);
    		for(j = l ; j <= r; j++)
    		{
    			ans *= pow(arr[j], ex);
    			//printf("Mult by = %lf\n", pow(arr[j], ex));
    		}
    		printf("%.10Lf\n", ans);
    	}
    }
    return 0;
}
