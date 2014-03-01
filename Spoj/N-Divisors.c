//http://www.spoj.com/problems/NDIV/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool arr[31625];
int primes[3410];
int main()
{
    int i,np=0,a,b,n,j,k,ans,lim,nc,ndiv,co;
    for(i=3;i<=31622;i+=2)
    {
        arr[i]=true;
        arr[i-1]=false;
    }
    primes[np++]=2;
    for(i=3;i<=31622;i+=2)
    {
        if(arr[i])
        {
            for(j=i*i;j<=31622;j+=i) arr[j]=false;
            primes[np++]=i;
        }
    }
    //printf("Primes=%d\n",np);
    scanf("%d%d%d",&a,&b,&n);
    for(k=a,ans=0;k<=b;k++)
    {
        lim=sqrt(k); nc=k;
        for(i=0,ndiv=1;i<np && primes[i]<=lim && nc>1 && ndiv<n;i++)
        {
            co=0;
            while(nc%primes[i]==0)
            {
                co++;nc/=primes[i];
            }
            ndiv*=(co+1);
        }
        if(nc>1) ndiv*=2;
        if(ndiv==n) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
