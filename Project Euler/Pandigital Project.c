//http://projecteuler.net/problem=32
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int check_pan_dig(int a,int b,int nc)
{
    int na=a,nb=b,arr[10],i,dig;
    //printf("Checking %d %d %d check 1\n",na,nb,nc);
    for(i=1;i<10;i++) arr[i]=0;
    while(na>0)
    {
        dig=na%10;
        if(dig==0 || arr[dig]!=0) return 0;
        else arr[dig]++;
        na/=10;
    }
    //printf("Checking %d %d %d check 2\n",na,nb,nc);
    while(nb>0)
    {
        dig=nb%10;
        if(dig==0 || arr[dig]!=0) return 0;
        else arr[dig]++;
        nb/=10;
    }
    //printf("Checking %d %d %d check 3\n",na,nb,nc);
    while(nc>0)
    {
        dig=nc%10;
        if(dig==0 || arr[dig]!=0) return 0;
        else arr[dig]++;
        nc/=10;
    }
    //printf("Checking %d %d %d check 4\n",na,nb,nc);
    for(i=1;i<10;i++)if(arr[i]!=1) return 0;
    //printf("Checking %d %d %d check 5\n",na,nb,nc);
    return 1;
}
int main()
{
    int i,j,ar[10000];
    long long int sum=0;
    for(i=10;i<10000;i++) ar[i]=0;
    for(i=10;i<100;i++)
        for(j=100;j<1000;j++)
        {
            int pr=i*j;
            if(pr>9999) break;
            if(ar[pr]==0 && check_pan_dig(i,j,pr))  {sum+=pr;ar[pr]=1;printf("Product => %d x %d = %d\n",i,j,pr);}
        }
    for(i=1;i<10;i++)
        for(j=1000;j<100000;j++)
        {
            int pr=i*j;
            if(pr>9999) break;
            if(ar[pr]==0 && check_pan_dig(i,j,pr))  {sum+=pr;ar[pr]=1;printf("Product => %d x %d = %d\n",i,j,pr);}
        }

    printf("\nSum of all Pan-Digit Product is: %lld\n",sum);
    return 0;
}
