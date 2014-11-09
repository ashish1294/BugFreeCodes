//http://www.codechef.com/JUNE14/problems/LEBLOCKS/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> d[205];
unsigned long long int fact[21];
vector<pair<int, int> > ele;
inline int inp()
{
    int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int main()
{
    int t = inp(), n, k, i, lim, j, l;
    unsigned long long int pairs, tempcos, totcos;
    long double ans;

    //Sieving Factorials
    fact[0]=1;
    for(i=1;i<=20;i++)
        fact[i]=fact[i-1]*i;
    while(t--)
    {
        n=inp();lim=inp();
        ele.clear();
        for(i=0;i<n;i++)
        {
            ele.push_back(make_pair(0,0));
            ele[i].first = inp(); ele[i].second = inp();
        }
        sort(ele.begin(),ele.end());
        for(i=0,ans=0;i<n;i++)
        {
            ans += max(0, ele[i].first - lim);
            for(j=i+1;j<n;j++)
            {
                if(ele[i].second==ele[j].second)
                {
                    for(int li=0;li<lim;li++) d[li].clear();
                    d[0].push_back(0);
                    for(int li=0;li<n;li++)
                    {
                        if(li!=i && li!=j)
                        {
                            for(int lj=lim-ele[li].first;lj>=0;lj--)
                            {
                                for(int kp=0;kp<d[lj].size();kp++)
                                {
                                    d[lj+ele[li].first].push_back(d[lj][kp]+1);
                                }
                            }
                        }
                    }
                    for(int li=max(lim-ele[i].first-ele[j].first+1,0);li<lim;li++)
                    {
                        pairs = max ( (ele[i].first + ele[j].first + li - lim) - max(ele[i].first+li-lim, 0) - max(ele[j].first+li-lim, 0), 0);
                        if(pairs==0) continue;
                        long double ttt = (long double) pairs/fact[n];
                        for(int lj=0;lj<d[li].size();lj++)
                        {
                            ans += ((fact[d[li][lj]]*fact[n-d[li][lj]-1])<<1)*ttt;
                        }
                    }
                }
            }
        }
        printf("%.8Lf\n",ans);
    }
    return 0;
}
