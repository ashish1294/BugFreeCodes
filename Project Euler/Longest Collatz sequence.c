//http://projecteuler.net/problem=14
//Author: Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
    int i,maxin;
    long long int start,count,max;
    for(i=1000000;i>1;i--)
    {
        start=i;
        count=1;
        while(start!=1)
        {
            if(start%2==0) start /=2;
            else start = (3*start)+1;
            count++;
        }
        //printf("For Start=%d lenght=%lld max=%lld\n",i,count,max);
        if(count>max) {max=count;maxin=i;}
    }
    printf("The number that produces Longest Seq is:%d\n",maxin);
    return 0;
}
