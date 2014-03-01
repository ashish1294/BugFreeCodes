#include<stdio.h>
int main()
{
    long int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld%ld%ld",&a,&b,&c);
        long long int sum=a+b+c;
        if(sum%2==0)
        {
            printf("Bob\n");
        }
        else
        {
            printf("Alice\n");
        }
    }
    return 0;
}
