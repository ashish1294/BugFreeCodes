//http://projecteuler.net/problem=9
//Author - Ashish Kedia
//@ashish1294
#include<stdio.h>
#include<math.h>
int main()
{
    long long int i,j,k,u;
    long double l;
    for(i=1;i<1000;i++)
    {
        for(j=i+1;j<1000;j++)
        {
            k = i*i + j*j;
            l=sqrt(k);
            if(ceil(l)==floor(l))
            {
                u=ceil(l);
                if(i+j+u==1000)
                {printf("%lld %lld %lld ",i,j,l);
                }
            }
            if(i+j+l>1000)
                break;
        }
    }
    return 0;
}
