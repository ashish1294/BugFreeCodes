//http://www.spoj.com/problems/XMEN/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<iostream>
#include<set>
#include<algorithm>
#define max(a,b) (a>b?a:b)
using namespace std;
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
int A[100001],B[100001],dp[1000010],c[1000010];
int main()
{
    int t=inp(),n,i,j;
    while(t--)
    {
        n=inp();
        for(i=0;i<n;i++) A[inp()]=i;
        for(i=0;i<n;i++) B[i]=A[inp()];
        set<int> st;
        set<int>::iterator it;
        st.clear();
        for(i=0; i<n; i++)
        {
            st.insert(B[i]);
            it=st.find(B[i]);
            it++;
            if(it!=st.end()) st.erase(it);
        }
        printf("%d\n",st.size());
    }
    return 0;
}
