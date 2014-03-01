#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
#define T 1000000
#define ULL unsigned long long
int main()
{

    unsigned long long int t=0,n,i,j,q,A[T],B[T],x,y,ans[50000];
    char c;
    cout<<"Start";
    scanf("%llu %llu",&n,&q);
    scanf("%llu",&A[0]);
    B[0]=A[0];
    for(i=1;i<n;i++)
    {
        scanf("%llu",&A[i]);
        B[i]=A[i]+B[i-1];
    }
    for(j=0;j<q;j++)
    {
        scanf("%c %llu %llu",&c,&x,&y);
        if(c=='S')
        {
            ans[t]=B[y]-B[x]+A[x];
            t++;
        }
        else if(c=='G')
        {
            A[x]+=y;
            for(i=x;i<n;i++)
                B[i]+=y;
        }
        else
        {
            A[x]-=y;
            for(i=x;i<n;i++)
                B[i]-=y;
        }
    }
    for(i=0;i<t;i++)
        printf("%llu\n",ans[i]);
 return 0;
}
