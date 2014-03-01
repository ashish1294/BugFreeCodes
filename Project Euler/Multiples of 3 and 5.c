#include<stdio.h>
int main()
{
    int sum=0,i;
    for(i=3;i<1000;i++)
    {
        if(i%3==0||i%5==0)
            sum += i;
    }
    printf("%d",sum);
    return 0;
}
