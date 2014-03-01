//http://www.spoj.com/problems/SPCQ/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
inline long long int linp()
{
    register long long int noRead=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked());
    for(;p<48 || p>57;p=getc(stdin));
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
int main()
{
    int t,s;
    long long int n,nc;
    scanf("%d",&t);
    while(t--)
    {
        //scanf("%lld",&n);
        n=linp();
        while(1)
        {
            nc=n;s=0;
            while(nc>0)
            {
                s+=(nc%10);
                nc/=10;
            }
            if(n%s==0) break;
            else n++;
        }
        printf("%lld\n",n);
    }
    return 0;
}
