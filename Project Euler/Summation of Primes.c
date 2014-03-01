//http://projecteuler.net/problem=10
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define MAX 2000000
#define LMT 1415
#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))
int flag[MAX>>6];
int main()
{
    register int i, j, k,numpr=1;
    for(i = 3; i < LMT; i+=2)
        if(!ifc(i))
        {  numpr++; for(j=i*i, k=i<<1; j < MAX; j+=k)   isc(j);}
    long long int sum=2;
    for(i=3;i<MAX;i=i+2)   {  if(!ifc(i))  { sum+= i; }}
    printf("%lld\n",sum);
    return 0;
}
