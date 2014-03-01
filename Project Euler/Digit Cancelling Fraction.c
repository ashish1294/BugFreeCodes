//http://projecteuler.net/problem=33
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int gcd(int a,int b)
{return b==0?a:gcd(b,a%b);}
int main()
{
    int i,j,num=1,den=1;
    for(i=11;i<100;i++)
    {
        if(i%10==0) continue;
        for(j=i+1;j<100;j++)
        {
            if(j%10==0) continue;
            int a1=i/10,a2=i%10,b1=j/10,b2=j%10,ii=i/gcd(i,j),jj=j/gcd(i,j);
            if(a1==b1)
            {
                if (((a2/gcd(a2,b2))==ii) && ((b2/gcd(a2,b2))==jj))
                {
                    printf("Non-Trivial Fraction Found: %d/%d in 1\n",i,j);
                    num *= i;den *= j;
                }
            }
            if(a1==b2)
            {
                if (((a2/gcd(a2,b1))==ii) && ((b1/gcd(a2,b1))==jj))
                {
                    printf("Non-Trivial Fraction Found: %d/%d in 2\n",i,j);
                    num *= i;den *= j;
                }
            }
            if(a2==b1)
            {
                if (((a1/gcd(a1,b2))==ii) && ((b2/gcd(a1,b2))==jj))
                {
                    printf("Non-Trivial Fraction Found: %d/%d in 3\n",i,j);
                    num *= i;den *= j;
                }
            }
            if(a2==b2)
            {
                if (((a1/gcd(a1,b1))==ii) && ((b1/gcd(a1,b1))==jj))
                {
                    printf("Non-Trivial Fraction Found: %d/%d in 4\n",i,j);
                    num *= i;den *= j;
                }
            }
        }
    }
    printf("Final Products of fractions : %d/%d\n",num,den);
    int g=gcd(num,den);
    num=num/g;den=den/g;
    printf("Fraction in Lowest Common Term : %d/%d\n",num,den);
    return 0;
}
