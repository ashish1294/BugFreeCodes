#include<stdio.h>
int main()
{
    int n, i, x, max = 0, tmpmax = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++ )
    {
        scanf("%d", &x);
        if( x == 0)
        {
            if( tmpmax > max)
                max = tmpmax;
            tmpmax = 0;
        }
        else
        {
            tmpmax++;
        }
    }
    if(tmpmax > max)
        max = tmpmax;

    printf("%d\n",max);
    return 0;
}
