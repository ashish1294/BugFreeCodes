#include<stdio.h>

int main()
{
    int t,n,temp;
    long int c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %ld",&n,&c);
        while(n--)
        {
            scanf("%d",&temp);
            c = c - temp;
        }
        if (c>=0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
