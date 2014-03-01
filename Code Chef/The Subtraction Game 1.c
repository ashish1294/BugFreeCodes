#include<stdio.h>

int main()
{
    int t,n,i;
    long long int gcd=0,temp;
    long int findgcd(long int, long int);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        gcd=0;
        while(n--)
        {
            scanf("%lld",&temp);
            if (gcd==0)
                gcd=temp;
            else if(gcd<temp)
                gcd = findgcd(gcd,temp);
            else
                gcd = findgcd(temp,gcd);
        }
        printf("%lld\n",gcd);
    }
    return 0;
}

long int findgcd(long int small, long int big)
 {
  	  if(big%small==0)
  	  return small;

  	  else
  	  return findgcd(big%small, small);
	  }
