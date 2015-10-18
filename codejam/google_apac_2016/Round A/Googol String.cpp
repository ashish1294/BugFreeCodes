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

unsigned long long int nextPowerOf2(unsigned long long int n)
{
  unsigned int count = 0;
  unsigned long long int x = 1;
 
  /* First n in the below condition is for the case where n is 0*/
  if (n && !(n&(n-1)))
    return n;
 
  while( n != 0)
  {
    n  >>= 1;
    count += 1;
  }
 
  return x<<count;
}

int solve(unsigned long long int x)
{
    unsigned long long int n = nextPowerOf2(x);
    if(n == x) return 0;
    return 1 - solve(n - x);
}
int main()
{
    int t, tc, n, m, i, j, k;
    long long int kk;
    scanf("%d", &tc);
    for(t = 1; t <= tc; t++)
    {
        scanf("%lld", &kk);
        printf("Case #%d: %d\n", t, solve(kk));
    }
    return 0;
}
