#include<stdio.h>
#include<math.h>
int main()
{
    long int T,N,n,i;
    scanf("%ld",&N);
    while(N!=0)
    {
            i=1;
            n=N;
            while(n)
            {
                n>>=1;
                i<<=1;
            }
            i>>=1;
            if(i==N)
                printf("%ld\n",N);
            else
                printf("%ld\n",((N-i)*2));
        scanf("%ld",&N);
    }
    return 0;
}
