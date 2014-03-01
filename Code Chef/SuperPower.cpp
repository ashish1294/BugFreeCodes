#include<iostream>
#include<cstdio>

#define modp 1000000007

unsigned long long modulo(unsigned long long int x, unsigned long long int y);
void convert(unsigned long long int num);
using namespace std;
string numstr;
int main()
{
    long int t,i;
    unsigned long long int a,ans,f;
    scanf("%ld",&t);
    while(t--)
    {
        ans=0;f=1;
        scanf("%lld",&a);
        convert(a);
        for(i=numstr.length()-1;i>=0;i--,f*=10)
            ans+=(numstr[i]-'0')*f;
        ans=modulo(2,ans);
        ans=modulo(ans,2);
        printf("%ld\n",(long int)ans);
    }
    return 0;
}

unsigned long long modulo(unsigned long long int x, unsigned long long int y)
{
    unsigned long long int ans;
    if (y==0)
        return 1;
    if(y==1)
        return x;
    ans = modulo(x,y/2);
    ans = ans * ans % modp;
    if (y%2)
        ans=ans * x % modp;
    return ans%modp;
}
void convert(unsigned long long int num)
{
    numstr="";
    unsigned i=1<<31;
    while(i>0)
    {
        if(num&i)
            numstr=numstr+"1";
        else
            numstr=numstr+"0";
        i /= 2;
    }
}
