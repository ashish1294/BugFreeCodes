#include<stdio.h>
#include<math.h>

int main()
{
    int t,digit;
    long long int n,i,j,k,coun;
    scanf("%d",&t);
    while(t--)
    {
        //printf("in while");
        scanf("%lld",&n);
        j=sqrt(n);
        coun=0;
        //printf("for bef");
        for(i=1;i<=j;i++)
        {
            //printf("\n%lld\n",i);
            if(n%i==0)
            {
                k=i;
                while(k)
                {
                    digit=k%10;
                    if(digit==3||digit==5||digit==6)
                    {
                        //printf("%lld\b\n",i);
                        coun++;
                        break;
                    }
                    k /= 10;
                }
                k=n/i;
                while(k)
                {
                    digit=k%10;
                    if(digit==3||digit==5||digit==6)
                    {
                        //printf("%lld\b\n",n/i);
                        coun++;
                        break;
                    }
                    k /= 10;
                }
            }
        }
        printf("%lld\n",coun);
    }
    return 0;
}
