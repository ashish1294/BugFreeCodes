#include<stdio.h>
#include<stdbool.h>
#define MAX 100000000
#define LMT 10000
#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))
int flag[MAX>>6];
void sieve()
{
    register int i, j, k,numpr=1;
    for(i = 3; i < LMT; i+=2)
        if(!ifc(i))
        {
            numpr++;
            for(j=i*i, k=i<<1; j < MAX; j+=k)
                isc(j);
        }
    printf("2\n");
    for(i=3,j=1;i<MAX;i=i+2)
    {
        if(!ifc(i))
        {
            j++;
            if(j%100==1)
                printf("%d\n",i);
        }
    }
}
int main()
{
    sieve();
    return 0;
}
