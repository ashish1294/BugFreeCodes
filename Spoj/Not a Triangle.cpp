//http://www.spoj.com/problems/NOTATRI/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include <iostream>
#include <vector>
#include <algorithm>
#include<stdlib.h>
#include<stdio.h>
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
int main()
{
    int n,i,j,ans;
    while(1)
    {
        n=inp();
        if(n == 0) return 0;
        vector<int> len(n);
        for(i=0;i!=n;++i) len[i]=inp();
        sort(len.begin(),len.end());
        ans=0;
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
                ans += len.end() - upper_bound(len.begin()+j+1,len.end(),len[i]+len[j]);
        printf("%d\n",ans);
    }
    return 0;
}
