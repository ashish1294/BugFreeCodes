//http://www.spoj.com/problems/FACVSPOW/
// @ashish1294
#include<stdio.h>
#include<math.h>
#define MAX 1000001
static const double e = 2.7182818284590;
static long double dpsum[3000000];
int main()
{
    long long int i,a,j;
    dpsum[1]=0;
    for(i=2;i<3000000;i++)
        dpsum[i]=dpsum[i-1]+logl(i);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&a);
        {
            j=pow(e,(logl(a)+1));
            //printf("Approx =%lld\n",j);
            double ss = dpsum[j]/log(a);
            while(ss>j)
            {
                j--;
                ss = dpsum[j]/log(a);
            }
        }
        printf("%lld\n",j+1);
    }
    return 0;
}
