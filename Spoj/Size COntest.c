#include<stdio.h>
int main()
{
    long int t,a,b=0;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&a);
        if (a>0) b +=a;
    }
    printf("%ld",b);
    return 0;
}
