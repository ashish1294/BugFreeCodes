//http://www.codechef.com/problems/D1
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
bool flag;
/*int modulo(int a,int b)
{
    if(b==1)
    {
        if(a>10000) flag=true;
        return a%10000;
    }
    if(b==0) return 1;
    if(b%2==0)
    {
        int aa=modulo(a,b/2);
        aa*=aa;
        if(aa>10000) flag=true;
        return aa%10000;
    }
    int aa = a*modulo(a,b-1);
    if(aa>10000) flag=true;
    return aa%10000;
}*/
void modulo(long x,long a)
{
    long y=1;int flag=0;
    if(x>=10000&&a>0){flag=1;x%=10000;}
    while(a>0)
    {
        if(a%2==1)
        {
            y=(y*x);
            if(y>=10000){flag=1;y%=10000;}
        }
        if(a==1)break;
        x=(x*x);
        if(x>=10000){flag=1;x%=10000;}
        a=a/2;
    }
    if(flag==0) printf("%ld\n",y);
    else
    {
        if(y<10)printf("000");
        else if(y<100)printf("00");
        else if(y<1000)printf("0");
        printf("%ld\n",y);
    }
}
inline int inp()
{
    register int noRead=0;
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
    int i,j,t,n,lim,ts,nc;
    flag=false;
    int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709};
    //scanf("%d",&t);
    t=inp();
    while(t--)
    {
        //scanf("%d",&n);
        n=inp();
        lim=sqrt(n);nc=n;
        int ndiv=1,ans;
        for(i=0;i<=125 && primes[i]<=701 && primes[i]<=lim;i++)
        {
            ts=0;
            while((n%primes[i])==0)
            {
                ts++;
                n/=primes[i];
            }
            ndiv*=(ts+1);
        }
        if(n>1) ndiv*=2;
        if((lim*lim)==nc) modulo(lim,ndiv-2);
        else modulo(nc,((ndiv-2)/2));
        /*if(flag==false) printf("%d\n",ans);
        else
        {
            if(ans<10) printf("000");
            else if(ans<100) printf("00");
            else if(ans<1000) printf("0");
            printf("%d\n",ans);
        }*/
    }
    return 0;
}
