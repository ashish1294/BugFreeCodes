//http://projecteuler.net/problem=12
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
int main()
{
    int primes[4000],i=3,j,t;
    int numprimes = 0;
    primes[numprimes++] = 2;
    for (i = 3; i <= 32000; i+=2)
    {
       bool isprime = true;
       double cap = sqrt(i) + 1.0;
       for (j = 0; j < numprimes; j++)
       {
            if (j >= cap) break;
            if (i % primes[j] == 0)
            {
                 isprime = false;
                 break;
            }
        }
        if (isprime) primes[numprimes++] = i;
    }
    long long int n,nc,k;
    for(k=10000;;k++)
    {
        n= (k*(k+1))/2;
        nc=n;
        long long int ans =1;
        for(i=0;i<numprimes;i++)
        {
            if(n==1)
                break;
            int coun=0,coi=i;
            for(j=1;j<=64;j++)
            {
                if(n%primes[i]==0)
                {
                    coun++;
                    n /= primes[i];
                }
                else
                    break;
            }
            ans *=(coun+1);
        }
        if(ans>500)
        {
            printf("%lld",nc);
            return 0;
        }
    }
}
