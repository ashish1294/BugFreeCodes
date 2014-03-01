#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long int x,y;
        scanf("%ld%ld",&x,&y);
        if(x==y)
        {
            if(x%2==0)
                printf("%ld\n",2*x);
            else
                printf("%ld\n",2*x-1);
        }
        else if(x==y+2)
        {
            if(x%2==0)
                printf("%ld\n",2*(x-1));
            else
                printf("%ld\n",2*x-3);
        }
        else
            printf("No Number\n");
    }
    return 0;
}
