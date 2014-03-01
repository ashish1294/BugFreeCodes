//http://www.codechef.com/JAN14/problems/FGFS
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdlib.h>
struct cust{
    int a,d,p; //a=Arrival Time, d= Departure Time, p=Preferred Compartment
};
struct cust arr[100000];
int comp(const void* a, const void* b)
{
    struct cust* aa = ((struct cust*)a);
    struct cust* bb = ((struct cust*)b);
    int dd=aa->p - bb->p;
    if(dd==0) dd=aa->d-bb->d;
    return dd;
}
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
    int t=inp(),n,k,i,j,co,dep;
    while(t--)
    {
        n=inp();k=inp();co=0;dep=0;
        for(i=0;i<n;i++)
        {
            arr[i].a=inp();
            arr[i].d=inp();
            arr[i].p=inp();
        }
        qsort(arr,n,sizeof(struct cust),comp);
        for(i=0;i<n;i++)
        {
            co++;
            dep=arr[i].d;
            while(i<n-1 && arr[i+1].p==arr[i].p)
            {
                if(arr[i+1].a>=dep) {co++;dep=arr[i+1].d;}
                i++;
            }
        }
        printf("%d\n",co);
    }
    return 0;
}
