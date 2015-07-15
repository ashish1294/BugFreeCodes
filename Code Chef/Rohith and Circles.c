//http://www.codechef.com/JULY15/problems/NTHCIR
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
long double k[6];
int main()
{
    long long int t, tt, i, j;
    long long int n, p, m, b;
    long double r1, r2, r3, r4, sum = 0; 
    scanf("%lld", &t);
    tt = t;
    scanf("%lld%lld%lld%lld",&n, &p, &m, &b);
    scanf("%Lf%Lf%Lf%Lf", &r1, &r2, &r3, &r4);

    //Intializing
    k[1] = -(1 / r1);
    k[2] =  (1 / r2);
    k[3] =  (1 / r3);
    k[4] =  (1 / r4);
    long double add = k[1] + k[2];
    k[5] = (2 * (add + k[4])) - k[3];

    while(t--)
    {
        n = (p * n) % m + b;
        if(n == 1) sum += r1;
        else if (n <= 5) sum += 1 / k[n];
        else
        {
            long double to_div = (add * (n - 4) * (n - 3)) + ((n - 3) * k[4]) - ((n - 4) * k[3]);
            sum += 1 / to_div;
        }
    }
    printf("%.6Lf", sum);
    return 0;
}
