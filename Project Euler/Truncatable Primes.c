//http://projecteuler.net/problem=37
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
static bool arr[10000001];
int primes[1000000];
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
    int sum=0;
    printf("%d\n",np);
    for(i=4;i<np;i++)
    {
        int kk=1,ppr=primes[i],flag=1;
        while(ppr>0 && flag)
        {
            ppr /=10;
            if(ppr==0)break;
            if(arr[ppr]==false){flag=0;break;}
            kk*=10;
            //if(primes[i]==3797) printf("Flag =%d ppr=%d\n",flag,ppr);
        }
        ppr=primes[i];
        //if(primes[i]==3797) printf("Flag =%d ppr=%d break\n",flag,ppr);
        while(ppr>0 && flag)
        {
            ppr = ppr%kk;
            kk/=10;
            if(ppr==0) break;
            if(arr[ppr]==false){flag=0;break;}
            //if(primes[i]==3797) printf("Flag =%d\n ppr=%d",flag,ppr);
        }
        if(flag)
        {
            printf("Prime = %d\n",primes[i]);
            sum +=primes[i];
        }
    }
    printf("Sum is:%d\n",sum);
    return 0;
}
