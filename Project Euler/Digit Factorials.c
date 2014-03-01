//http://projecteuler.net/problem=34
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
    int fact[]={1,1,2,6,24,120,720,5040,40320,362880},i,fsum=0;
    for(i=10;;i++)
    {
        int nc=i,sum=0;
        while(nc>0)
        {
            sum+=fact[nc%10];
            nc/=10;
        }
        if(sum==i)
        {
            fsum +=i;
            printf("Number Found : %d Sum=%d\n",i,fsum);
        }
    }
    return 0;
}
