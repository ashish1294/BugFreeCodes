//http://www.spoj.com/problems/BUSYMAN/
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
struct activity{
    int start,end;
};
bool compend(struct activity a, struct activity b)
{
    return (a.end<b.end);
}
struct activity arr[100001];
int main()
{
    int t=inp(),n,te,ans,i;
    while(t--)
    {
        n=inp();ans=0;
        for(i=0;i<n;i++)
        {
            arr[i].start=inp();
            arr[i].end=inp();
        }
        std::sort(arr,arr+n,compend);
        for(i=0;i<n;)
        {
            te=arr[i].end;
            ans++;
            while(i<n && arr[i].start<te) i++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
