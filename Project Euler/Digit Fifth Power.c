//http://projecteuler.net/problem=30
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
    long long int allsum=0,i;
    for(i=2;i<200000;i++)
    {
        long long int n=i,sum=0;
        while(n>0)
        {
            long long int d = n%10;
            sum += (d*d*d*d*d);
            n /=10;
        }
        if(sum==i)
        {
            allsum +=sum;
            printf("Number Found = %lld     Sum=%lld\n",i,allsum);
        }
    }
    return 0;
}
