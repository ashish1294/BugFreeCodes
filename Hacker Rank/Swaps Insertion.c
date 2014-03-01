#include<stdio.h>
static long long int inv;
void Insertion_Sort(long long int Arr[],long int l, long int u)
{
    long int i,j,temp;
    for(i=l+1;i<=u;i++)
    {
        temp=Arr[i];
        j=i-1;
        while(j>=l&&(Arr[j]>temp))
        {
            Arr[j+1]=Arr[j];
            j--;
            inv++;
        }
        Arr[j+1]=temp;
    }
}
void Merge(long int Arr[],long int Arr1[],long int l,long int mid, long int u)
{
    long int i=l,j=mid+1,k=0;
    while((i<=mid)&&(j<=u))
    {
        if(Arr1[i]<Arr1[j])
        {
            Arr[k]=Arr1[i];
            i++;
            k++;
        }
        else
        {
            Arr[k]=Arr1[j];
            j++;
            k++;
            inv=inv+j-mid-1;
        }
    }

    if(i>mid)
    {
        for(;j<=u;j++,k++)
            Arr[k]=Arr1[j];
    }
    else
    {
        for(;i<=mid;i++,k++,inv=inv+j-mid-1)
            Arr[k]=Arr1[i];
    }
    return;
}
void Merge_Sort(long int Arr[] ,long int l,long int u)
{
    if(u==0)
        return;
    long int i, mid=(l+u)/2;
    long int Arr1[u+1];
    for(i=0;i<=u;i++)
    {
            Arr1[i]=Arr[i];
    }
    if(mid>20)
    {
        Merge_Sort(Arr1,0,mid);
        Merge_Sort(Arr1,mid+1,u);
    }
    else
    {
        Insertion_Sort(Arr1,0,mid);
        Insertion_Sort(Arr1,mid+1,u);
    }
    Merge(Arr,Arr1,l,mid,u);
    return;
}
int main()
{
    int t;
    long int n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        long int arr[n];
        for(i=0;i<n;i++)
        {
            scanf("%ld",&arr[i]);
        }
        inv=0;
        Merge_Sort(arr,0,n-1);
        printf("%lld\n",inv);
    }
    return 0;
}
