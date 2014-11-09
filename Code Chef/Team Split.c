//http://www.codechef.com/MARCH14/problems/TMSLT
//Author - Ashish Kedia, NITK SUrathkal
//@ashish1294
#include<stdio.h>
#define m 1000000
inline int inp()
{
    int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int co[1000000];
int gen[1000000];
int mul(int a,int b){
    long long int x = 0,y=a%m;
    while(b > 0)
    {
        if(b%2 == 1)
            x =(x+y)%m;
        y = (y*2)%m;
        b /= 2;
    }
    return x%m;
}
int main()
{
    int kk;
    int t=inp(),n,a,b,c,d,i,ch;
    long long int diff,tmp,tmp1;
    for(i=0;i<1000000;i++) gen[i]=-1;
    for(kk=1;kk<=t;kk++)
    {
        n=inp();a=inp();b=inp();c=inp();d=inp();
        tmp=d;
        co[tmp]++;
        for(i=1;i<n;i++)
        {
            if(gen[tmp]>=0) tmp1=gen[tmp];
            else
            {
                tmp1= ((a*mul(tmp,tmp))%m + (b*tmp) + c)%m;
                //tmp1 = ((a*((tmp*tmp)%m)) + (b*tmp) + c)%m;
                gen[tmp]=tmp1;
            }
            co[tmp1]++;
            tmp=tmp1;
        }
        ch=0;
        for(i=999999,diff=0;i>=0;i--)
        {
            if(co[i]%2==1)
            {
                if(ch==0) diff += i;
                else diff -= i;
                ch^=1;
            }
            co[i]=0;
            gen[i]=-1;
        }
        printf("%lld\n",diff);
    }
    return 0;
}
