//http://www.codechef.com/APRIL14/problems/POTATOES
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int primes[500];
int isp[2010];
int main()
{
    int i,j,np=0,t,x,y;
    for(i=2;i<=2004;i+=2)
    {
        isp[i]=1;
        isp[i+1]=0;
    }
    primes[np++]=2;
    for(i=3;i<2004;i+=2)
    {
        if(isp[i]==0)
        {
            for(j=i*i;j<2004;j+=i)
            {
                isp[j]=1;
            }
            isp[i]=1;
            primes[np++]=i;
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&x,&y);
        for(i=0;primes[i]<=x+y;i++);
        printf("%d\n",primes[i]-x-y);
    }
    return 0;
}
