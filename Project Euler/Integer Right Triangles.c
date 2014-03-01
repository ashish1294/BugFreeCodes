//http://projecteuler.net/problem=39
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<math.h>
int i,j,k,arr[1001]={0},root[10000001],max=9;
int main()
{
    for(i=0;i<1000001;i++) root[i]=-1;
    for(i=0;i<1001;i++) {arr[i]=0;root[i*i]=i;}
    for(i=1;i<500;i++)
    {
        for(j=i;j<500;j++)
        {
            if(i+j+sqrt(i*i+j*j)>1000) break;
            int r = root[i*i+j*j];
            if(r==-1) continue;
            //printf("Pyth Trip = %d,%d,%d sum=%d\n",i,j,r,i+j+r);
            arr[i+j+r]++;
        }
    }
    for(i=10;i<=1000;i++) if(arr[i]>arr[max]) max=i;
    printf("The Perimeter for which the number of solution is maximum: %d",max);
    return 0;
}
