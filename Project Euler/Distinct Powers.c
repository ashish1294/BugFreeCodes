//http://projecteuler.net/problem=27 - Quadratic Primes
//Author = Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
static bool arr[100];
int main()
{
    int kk,amax=4,bmax=4,ans=(amax-1)*(bmax-1);
    for(kk=2;kk<=sqrt(amax);kk++)
    {
        if(1)
        {
            int ss=0,f=2,lim=bmax/2;
            while(f<=lim)
            {
                if(((int)pow(kk,f))<=bmax)
                {
                    int tt = (bmax/f) -1;
                    f++;
                    ss +=tt;
                }
                else break;
            }
            ans -= ss;
        }
    }
    printf("\nThe number of Distinct Terms is:%d\n",ans);
    return 0;
}

