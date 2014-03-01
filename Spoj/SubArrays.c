//http://www.spoj.com/problems/ARRAYSUB/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define max(a,b) (a>b?a:b)
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
int arr[1000001];
int main()
{
    int n,i,k,j,ma1,ma2,ma;
    //scanf("%d",&n);
    n=inp();
    //for(i=0;i<n;i++) scanf("%d",&arr[i]);
    for(i=0;i<n;i++) arr[i]=inp();
    scanf("%d",&k);
    for(i=0;i<=n-k;i++)
    {
        if(i==0 || ma==(i-1))
        {
            ma=i;
            for(j=1;j<k;j++) if(arr[i+j]>arr[ma]) ma=i+j;
        }
        else if(arr[i+k-1]>arr[ma]) ma=i+k-1;
        printf("%d ",arr[ma]);
    }
    return 0;
}
