//http://projecteuler.net/problem=34
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
int rotate(int a,int r)
{
    int kk=a;
    if(a<10) return a;
    int arr[10],i=0,j;
    while(a>0)
    {
        arr[i]=a%10;
        a/=10;
        if(arr[i]==0 || arr[i]==2 || arr[i]==4 || arr[i]==6 || arr[i]==8 || arr[i]==5) return -1;
        i++;
    }
    a=0;
    for(j=i-r-1;j>=0;j--)
        a = (a*10) + arr[j];
    for(j=i-1;j>=i-r;j--)
        a = (a*10) + arr[j];
    return a;
}
int dig(int a)
{
    if(a<10) return 1;
    else if(a<100) return 2;
    else if(a<1000) return 3;
    else if(a<10000) return 4;
    else if(a<100000) return 5;
    else if(a<1000000) return 6;
    else if(a<10000000) return 7;
    else if(a<100000000) return 8;
    else return 9;
}
static bool arr[1000001];
int primes[1000000];
int main()
{
    long long int i,j,np=0;
    for(i=4;i<=1000000;i=i+2)
    {
        arr[i]=false;
        arr[i-1]=true;
    }
    arr[2]=true;
    primes[np++]=2;
    for(i=3;i<=1000000;i=i+2)
    {
        if(arr[i]==true)
        {
            for(j=i*i;j<1000000;j+=i)
                arr[j]=false;
            primes[np++]=i;
        }
    }
    int count=0;
    printf("Numprime=%d\n",np);
    for(i=0;i<np;i++)
    {
        int n=primes[i],flag=1;
        int digs=dig(n);
        for(j=1;j<digs;j++)
        {
            int na=rotate(n,j);
            if(na==-1 || arr[na]==false) {flag=0;break;}
        }
        if(flag){printf ("Circular Prime %d Found: %d\n",count,primes[i]);count++;}
    }
    printf("\nCount of Circular Primes : %d\n",count);
    return 0;
}
