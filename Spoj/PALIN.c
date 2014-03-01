#include<stdio.h>
int ispallin(long int d)
{
    char str[20];
    int i=0;
    while(d>0)
    {
        str[i]=d%10;
        d /= 10;
        i++;
    }
    str[i]='\0';
    int j,flag=1;
    for(j=0;j<i;j++)
    {
        if(str[j]!=str[i-1-j])
        {
            flag=0;
            break;
        }
    }
    if(flag)
        return 1;
    else
        return 0;
}
int main()
{
    long long int t,a,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&a);
        for(i=a+1;;i++)
            if (ispallin(i)==1)
            {
                printf("%lld\n",i);
                break;
            }
    }
    return 0;
}
