#include<stdio.h>
#include<string.h>

int main()
{
    int t;
    scanf("%d",&t);
    char a[11], b[6];
    while(t--)
    {
        fflush(stdin);
        scanf("%s %s",a,b);
        if (strstr(a,b)==NULL)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
