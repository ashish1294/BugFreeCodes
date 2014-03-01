#include <stdio.h>
long long C(int,int);

int main(void)
{
    int t,n,m,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        printf("%lld\n",C(n-1,m-1));
    }
    return 0;
}

long long int C(int a,int b)
{
    int t,i;
    long long int ans=1;
    if (b > a/2)
        b = a - b;
    for (i=0;i<b;i++)
    {
        ans *= (a-i);
        ans /= (i+1);
    }
    return ans;
}
