//http://www.codechef.com/COOK43/problems/LPAIR
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<algorithm>
#define getchar_unlocked() getc(stdin)
using namespace std;
inline int inp()
{
    register int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int F[100010],temp[100010];
struct ss{int a,b;};
ss arr[100010];
bool comp(ss aa,ss bb){return (aa.a<bb.a);}
long long merge(int a[],int l,int mid,int h,int temp[])
{
    int i,j,k;
    long long count=0;
    j = mid+1;
    for(k=l;k<=mid;k++)
    {
        while(j<=h)
        {
            if(a[k]>a[j]) j++;
            else break;
        }
        count+=j-(mid+1);
    }
    i = l;
    j = mid+1;
    k = l;
    while(i<=mid&&j<=h)
    {
        if(a[i]<a[j])
        {
            temp[k] = a[i];
            i++;k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        temp[k] = a[i];
        i++;k++;
    }
    while(j<=h)
    {
        temp[k] =  a[j];
        j++;k++;
    }
    for(k=l;k<=h;k++) a[k]=temp[k];
    return count;
}
long long mergesort(int a[],int l,int h,int temp[]){
    if(l==h) return 0;
    int mid;
    mid = (l+h)/2;
    long long lc,rc,mc;
    lc = mergesort(a,l,mid,temp);
    rc = mergesort(a,mid+1,h,temp);
    mc = merge(a,l,mid,h,temp);
    return lc+rc+mc;
}
int main()
{
    int n=inp(),i;
    for(i=0;i<n;i++)
        arr[i].a=inp();arr[i].b=inp();
    sort(arr,arr+n,comp);
    for(i=0;i<n;i++) F[i]=arr[i].b;
    long long int ans=mergesort(F,0,n-1,temp);
    printf("%lld\n",ans);
    return 0;
}
