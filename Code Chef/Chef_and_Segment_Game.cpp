/*
	Problem Name = Chef and Segment Game
	Problem Link = http://www.codechef.com/NOV14/problems/CHEFSEG
	User = ashish1294
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstdio>
#include<cmath>
#define LOG2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))
using namespace std;

int main()
{
    int t;
    unsigned long long int x,k;
    long double ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu%llu",&x,&k);
        int ll = LOG2(k);
        long long ss = pow(2, ll);
        long long int left = k - ss + 1;
        long long int den = ss * 2, num = (left*2) - 1;
        ans = ((long double) num * x) / ((long double) (den) );
        printf("%.12Lf\n",ans);
    }
    return 0;
}
