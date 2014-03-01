//http://www.spoj.com/problems/DEFKIN/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<algorithm>
using namespace std;
int X[50000],Y[50000];
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
    int t=inp(),n,m,tow,i,j,maxx,maxy,difx,dify,lx,ly;
    long long int ans;
    while(t--)
    {
        n=inp();m=inp();tow=inp();
        for(i=0;i<tow;i++)
        {
            X[i]=inp();
            Y[i]=inp();
        }
        sort(X,X+tow);
        sort(Y,Y+tow);
        X[tow]=n+1;
        Y[tow]=m+1;
        maxx=1;maxy=1;lx=0;ly=0;
        for(i=0;i<=tow;i++)
        {
            difx=X[i]-lx;
            dify=Y[i]-ly;
            if(difx>maxx) maxx=difx;
            if(dify>maxy) maxy=dify;
            lx=X[i];ly=Y[i];
        }
        ans=1LL*(maxx-1)*(maxy-1);
        printf("%lld\n",ans);
    }
    return 0;
}
