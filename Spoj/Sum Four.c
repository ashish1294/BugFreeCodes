//http://www.spoj.com/problems/SUMFOUR/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdlib.h>
int dpab[10000001],dpcd[10000001];
int comp(const void* a, const void* b)
{
    int *c = ((int *)a);
    int *d = ((int *)b);
    return ((*c)-(*d));
}
int bin_sh(int arr[],int val,int lim)
{
    int size=0,temp=0,low=0,high=lim,mid;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(arr[mid]==val)
        {
            temp=mid-1;
            while(mid<lim&&arr[mid]==val)
            {
                size++;mid++;
            }
            while(temp>=0&&arr[temp]==val)
            {
                size++;temp--;
            }
            return size;
        }
        else if(arr[mid]>val) high=mid-1;
        else low=mid+1;
    }
    return 0;
}
int main()
{
    long long int n,i,j;
    scanf("%lld",&n);
    int A[n],B[n],C[n],D[n],a=0,c=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            dpab[a++]=A[i]+B[j];
            dpcd[c++]=-(C[i]+D[j]);
        }
    qsort(dpcd,n*n,sizeof(int),comp);
    qsort(dpab,n*n,sizeof(int),comp);
    long long int ans=0;
    for(i=0;i<a;i++)
    {
        int s=0,tt=dpab[i];
        while(i<a && dpab[i]==tt)
        {
            s++;i++;
        }
        int res = bin_sh(dpcd,dpab[i],c-1);
        ans += res*s;
    }
    printf("%lld\n",ans);
    return 0;
}
