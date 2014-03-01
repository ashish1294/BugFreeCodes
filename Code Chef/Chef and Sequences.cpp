//http://www.codechef.com/FEB14/problems/CHSEQ22
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<algorithm>
#include<vector>
#define pr 1000000007
using namespace std;
vector<vector<int> > vv(100010);
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
	int n,m,i,send,j,a,b,in=0;
	long long int ans=1,y=2;
	n=inp();m=inp();
	for(i=0;i<m;i++)
    {
        a=inp();b=inp();
        vv[a].push_back(b);
    }
    for(i=1;i<=n;i++)
    {
        if(vv[i].size()>0) in++;
        if(vv[i].size()<2) continue;
        sort(vv[i].begin(),vv[i].end());
        send=vv[i][0];
        for(j=1;j<vv[i].size();j++)
            if(vv[i][j]>send && send<n)
            {
                vv[send+1].push_back(vv[i][j]);
                send=vv[i][j];
            }
    }
    while(in>0)
    {
        if(in%2==1) ans=(ans*y)%pr;
        y = (y*y)%pr;
        in /= 2;
    }
    ans = ans%pr;
	printf("%lld\n",ans);
	return 0;
}
