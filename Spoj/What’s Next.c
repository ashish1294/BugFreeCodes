#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,c;
    while(1)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==0&&b==0&&c==0)
            break;
        if((b-a)==(c-b))
            printf("AP %d\n",c+c-b);
        else if(b==0)
            printf("GP 0\n");
        else
            printf("GP %d\n",(c*c)/b);
    }
}
