#include<stdio.h>
int main()
{
    int i;
    long long int lcm=2520;
    for(i=11;i<=20;i++)
    {
        if(lcm%i!=0)
        {
            long long int c=lcm;
            while(lcm%i!=0)
                lcm += c;
        }
    }
    printf("%lld\n",lcm);
    return 0;
}
