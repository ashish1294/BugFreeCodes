//http://www.spoj.com/problems/CHOTU/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<math.h>
int main()
{
    int t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&x,&y);
        long long int aa=(x*x);
        aa -= (y*y);
        double ans = sqrt(aa);
        ans*=2;
        printf("%.3lf\n",ans);
    }
    return 0;
}
