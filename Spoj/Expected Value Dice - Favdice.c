//Suppose there is an n sided dice. It computes the expected value of number
//of times the dice must be rolled so that every number appears atleast once

#include<stdio.h>
int main()
{
    int n,t,i;
    double dd;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        dd=0;
        for(i=0;i<=n-1;i++)
        {
            dd += (((double)n)/(n-i));
        }
        printf("%.2lf\n",dd);
    }
    return 0;
}
