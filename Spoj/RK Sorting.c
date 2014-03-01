//http://www.spoj.com/problems/RKS/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define min(a,b) (a<b?a:b)
struct num{int n,f,in;};
int comp(const void*a, const void*b)
{
    return ((((struct num*)a)->n)>(((struct num*)b)->n));
}
int compf(const void*a, const void*b)
{
    struct num aa = *((struct num*)a);
    struct num bb = *((struct num*)b);
    if(aa.f!=bb.f) return (bb.f-aa.f);
    else return (aa.in-bb.in);
}
int main()
{
    int n,i,c;
    scanf("%d%d",&n,&c);
    struct num ar[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i].n);
        ar[i].in=i;
    }
    qsort(ar,n,sizeof(struct num),comp);
    ar[0].f=1;
    for(i=1;i<n;i++)
    {
        if(ar[i-1].n==ar[i].n)
        {
            ar[i].f=ar[i-1].f+1;
            ar[i].in=min(ar[i].in,ar[i-1].in);
        }
        else ar[i].f=1;
    }
    if(ar[n-1].n==ar[n-2].n) ar[n-1].in=min(ar[n-1].in,ar[n-2].in);
    for(i=n-2;i>=0;i--)
    {
        if(ar[i].n==ar[i+1].n)
        {
            ar[i].f=ar[i+1].f;
            ar[i].in=min(ar[i].in,ar[i+1].in);
        }
    }
    qsort(ar,n,sizeof(struct num),compf);
    for(i=0;i<n;i++)
        printf("%d ",ar[i].n);
    printf("\n");
    return 0;
}
