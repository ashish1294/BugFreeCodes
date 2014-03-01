//http://www.codechef.com/CODX2014/problems/REN2013D
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<algorithm>
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
inline int linp()
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
bool comp(long long int a, long long int b)
{
    return a<b;
}
int main()
{
    int t,n,i;
    //t=inp();
    scanf("%d",&t);
    long long int sum,hi;
    while(t--)
    {
        hi=0;
        //n=inp();
        scanf("%d",&n);
        long long int arr[n];
        for(i=0;i<n;i++)
        {
            //arr[i]=inp();
            scanf("%lld",&arr[i]);
            hi += arr[i];
        }
        std::sort(arr,arr+n);
        if(n>0) sum=arr[0]+1;
        else sum=1;
        for(i=1;i<n;i++)
        {
            if(arr[i]>sum) break;
            else sum+=arr[i];
        }
        if(sum<=hi) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
