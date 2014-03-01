#include<stdio.h>
#include<math.h>
#define MAX 100000000
#define LMT 10000
#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))
int flag[MAX>>6];
int prlist[5761700];
int numpr=1;
void sieve()
{
    register int i, j, k;
    for(i = 3; i < LMT; i+=2)
        if(!ifc(i))
        {
            numpr++;
            for(j=i*i, k=i<<1; j < MAX; j+=k)
                isc(j);
        }
    prlist[0]=2;
    for(i=3,j=1;i<MAX;i=i+2)
    {
        if(!ifc(i))
            prlist[j++]=i;
    }
    numpr=j;
}
int binary_cmov (int arr[], int n, int key)
{
    int min = 0, max = n;
    while (min < max)
    {
            int middle = (min + max) >> 1;
            asm ("cmpl %3, %2\n\tcmovg %4, %0\n\tcmovle %5, %1": "+r" (min),"+r" (max) : "r" (key), "g" (arr [middle]),"g" (middle + 1), "g" (middle));
    }
    return min;
}
int binary (int arr[],int n,int key)
{
    int min = 0, max = n;
    while (min < max)
    {
        int middle = min + ((max-min)>>2);
        if (key > arr [middle])
            min = middle + 1;
        else
            max = middle;
    }
    return min;
}
int main()
{
    sieve();
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        int x = binary_cmov(prlist,numpr-1,n);
        if(prlist[x]==n)
        {
            x=x+1;
        }
        float e = (float)n/log(n);
        //printf("x=%d\n",x);
        //printf("ln(x)=%f\n",log(n));
        //printf("div=%lf\n",e);
        e = x - e;
        //printf("dif=%lf\n",e);
        if(e<0) e=-e;
        e =(float) e/x;
        e = e*100;
        printf("%.1f\n",e);
        scanf("%d",&n);
    }
    return 0;
}
