//http://www.spoj.com/problems/FENCE1/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
int main()
{
    double pi=3.1415926f,ans;
    int l;
    while(1)
    {
        scanf("%d",&l);
        if(l==0) break;
        ans=(l*l)/pi;
        ans/=2;
        printf("%.2lf\n",ans);
    }
    return 0;
}
