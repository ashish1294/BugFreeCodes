#include<stdio.h>

int main()
{
    int t=10,temp,i;
    int a[42]={0};
    while(t--)
    {
        i=10;
        while(i--)
        {
            scanf("%d",&temp);
            a[temp%42] = 1;
        }
        i=0;
        temp=0;
        while(i<42)
            { temp += a[i];a[i]=0;i++;}
        printf("%d\n",temp);
    }
    return 0;
}
