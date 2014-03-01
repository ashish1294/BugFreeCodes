//http://projecteuler.net/problem=27 - Quadratic Primes
//Author = Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
static bool arr[100000];
static int primes[100000];
int main()
{
    long long int i,j,np=0;
    arr[2]=true;
    primes[np++]=2;
    for(i=4;i<100000;i++)
    {
        arr[i]=false;
        arr[i-1]=true;
    }
    for(i=2;i<100000;i++)
    {
        if(arr[i]==true)
        {
            for(j=i*i;j<100000;j+=i)
                arr[j]=false;
            if(i<1000) primes[np++]=i;
        }
    }
    int maxlen=-1,maxa=-1,maxb=-1,n,len;
    for(i=1;i<1000;i+=2)
    {
        for(j=0;j<np;j++)
        {
            len=0;
            for(n=0;;n++)
            {
                int term = (n*n)+(i*n)+primes[j];
                if(arr[term]==true) len++;
                else break;
            }
            if(len>maxlen){maxlen=len;maxa=i;maxb=primes[j];}
            len=0;
            for(n=0;;n++)
            {
                int term = (n*n)-(i*n)+primes[j];
                if(arr[term]==true) len++;
                else break;
            }
            if(len>maxlen){maxlen=len;maxa=-i;maxb=primes[j];}
            len=0;
            for(n=0;;n++)
            {
                int term = (n*n)+(i*n)-primes[j];
                if(arr[term]==true) len++;
                else break;
            }
            if(len>maxlen){maxlen=len;maxa=i;maxb=-primes[j];}
            len=0;
            for(n=0;;n++)
            {
                int term = (n*n)-(i*n)-primes[j];
                if(arr[term]==true) len++;
                else break;
            }
            if(len>maxlen){maxlen=len;maxa=-i;maxb=-primes[j];}
        }
    }
    printf("\nThe Maximum Length is %d generated when a=%d and b=%d Product=%d\n",maxlen,maxa,maxb,maxa*maxb);
    return 0;
}
