#include<stdio.h>
int comp(const void*a, const void*b)
{
    int *c = (int*)a;
    int *d = (int*)b;
    return ((*c)-(*d));
}
int main()
{
    int n,i;
    long long int x;
    scanf("%d%lld",&n,&x);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),comp);
    long long int s=0;
    int succ=0,fail=n;
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            arr[i]/=2;s+=arr[i];
            if(s>x)
            {
                break;
            }
            else {fail--;}
        }
        else
        {
            arr[i]/=2;s+=arr[i]+1;
            if(s>x)
            {
                break;
            }
            else {fail--;}
        }
    }
    if (s>x) {printf("%d %d\n",fail,succ);return 0;}
    for(i=0;i<n;i++)
    {
        s +=arr[i];
        if(s>x) break;
        else {succ++;}
    }
    printf("%d %d\n",fail,succ);
    return 0;
}
