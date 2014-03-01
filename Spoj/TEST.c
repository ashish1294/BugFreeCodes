#include<stdio.h>

int main()
{
    int i;
    int flag=1;
    while(scanf("%d",&i)!=EOF)
    {
        if(i==42)
            flag=0;
        if(flag)
            printf("%d\n",i);
    }
    return 0;
}
