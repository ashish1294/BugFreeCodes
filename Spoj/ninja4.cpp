#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
                long long int x=0,y=0,n=1,m,i;
                scanf("%lld",&m);
                for(i=1;i<=m;)
                {
                    x=x+n; y=y;
                    if(n==m)
                        break;
                    n++;
                    x=x; y=y+n;
                    if(n==m)
                        break;
                    n++;
                    x=x-n; y=y;
                    if(n==m)
                        break;
                    n++;
                    x=x; y=y-n;
                    if(n==m)
                        break;
                    n++;
                }
    printf("%lld %lld\n",x,y);
    }
    return 0;
}
