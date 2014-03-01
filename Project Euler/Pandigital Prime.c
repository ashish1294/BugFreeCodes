//http://projecteuler.net/problem=41
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
bool arr[7777777];
int primes[7000000];
int ispandig(int a)
{
    int ar[10]={0},i,max=0;
    for(i=0;i<10;i++) ar[i]=0;
    while(a>0)
    {
        if(ar[a%10]!=0) return 0;
        ar[a%10]=1;
        if((a%10)>max) max=a%10;
        a/=10;
    }
    for(i=1;i<=max;i++) if(ar[i]==0) return 0;
    return 1;
}
int main()
{
    long long int i,j,np=0;
    for(i=4;i<=7654322;i=i+2)
    {
        arr[i]=false;
        arr[i-1]=true;
    }
    arr[2]=true;
    primes[np++]=2;
    for(i=3;i<=7654322;i=i+2)
    {
        if(arr[i]==true)
        {
            for(j=i*i;j<7654322;j+=i)
                arr[j]=false;
            primes[np++]=i;
        }
    }
    for(i=np-1;i>=0;i--)
    {
        //printf("Prime = %d\n",primes[i]);
        if(ispandig(primes[i]))
        {
            printf("The LArgest Pan Digital Prime is: %d",primes[i]);
            return 0;
        }
    }
    return 0;
}
