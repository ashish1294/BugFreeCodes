//http://www.spoj.com/problems/PTIME/
//@ashish1294 NITK Surathkal
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int main()
{
	int primes[1500],i=3,j,n;
    int numprimes = 0;
    primes[numprimes++] = 2;
    for (i = 3; i <= 10000; i+=2)
    {
       bool isprime = true;
       double cap = sqrt(i) + 1.0;
       for (j = 0; j < numprimes; j++)
       {
            if (j >= cap) break;
            if (i % primes[j] == 0){isprime = false; break;}
        }
        if (isprime) primes[numprimes++] = i;
    }
    scanf("%d",&n);
	for(i=0;i<numprimes;i++)
	{
		int nc=n,ni=primes[i],ans=0;
		if(ni>n)
			break;
		while((n/ni)>0)
		{
			ans += n/ni;
			ni *= primes[i];
		}
		if(i!=0)
			printf(" * ");
		printf("%d^%d",primes[i],ans);
	}
	return 0;
}
