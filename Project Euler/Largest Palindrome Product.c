//http://projecteuler.net/problem=4
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294

#include<stdio.h>
int ispalin(long long int a)
{
    long long int rev=0,numc=a;
    while(a>0)
    {
        rev = (rev*10)+(a%10);
        a/=10;
    }
    if (rev==numc) return 1;
    else return 0;
}
int main()
{
    int i,j;
    long long int max =0;
    long long int prod ;
    for(i=999;i>=100;i--)
    {
        for(j=999;j>=100;j--)
        {
            prod = i*j;
            if(ispalin(prod) && prod>max)
                max=prod;
        }
    }
    printf("%lld\n",max);
    return 0;
}
