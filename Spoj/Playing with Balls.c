#include<stdio.h>
int main()
{
    int t,b,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&w,&b);
        if(b%2==0)
            printf("0.000000\n");
        else
            printf("1.000000\n");
    }
    return 0;
}
