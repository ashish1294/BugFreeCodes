//http://projecteuler.net/problem=7
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
static bool isprime[1000000];
static int primes[100000];
int main()
{
    long long int np=0,i,j;
    isprime[2]=true;
    primes[np++]=2;
    for(i=4;i<1000000;i=i+2)
    {
        isprime[i]=false;
        isprime[i-1]=true;
    }
    for(i=3;i<1000000;i=i+2)
    {
        if(isprime[i]==true)
        {
            for(j=i*i;j<1000000;j=j+i)
                isprime[j]=false;
            primes[np++]=i;
            if(np>10001)
                break;
        }
    }
    printf("%d\n",primes[10000]);
    return 0;
}
