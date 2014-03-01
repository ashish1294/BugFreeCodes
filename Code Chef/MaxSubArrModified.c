#include<stdio.h>
#include<stdbool.h>
long long int max(long long int x, long long int y)
{ return (y > x)? y : x; }

void maxSubArraySumforward(long long int a[],long int size,long long int dparrfor[])
{
    long long int max_so_far = a[0];
    long int i;
    long long int curr_max = a[0];
    dparrfor[0]=max_so_far;
    for (i = 1; i <size; i++)
    {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
        dparrfor[i]=max_so_far;
    }
}
void maxSubArraySumbackward(long long int a[],long int size,long long int dparrback[])
{
    long long int max_so_far = a[size-1];
    long int i;
    long long int curr_max = a[size-1];
    dparrback[size-1]=max_so_far;
    for (i = size-2; i >=0; i--)
    {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
        dparrback[i]=max_so_far;
    }
}

inline void readlonglongint(long long int *var)
{
    register char ch=0;
    register bool neg=false;
    *var=0;
    //Escaping space and Enter characters
    while (ch<48 || ch >57)
    {
        ch=getc(stdin);
        if(ch=='-')
            neg=true;
    }
    //Consider only numerals
    while (ch>47 && ch<58)
    {
        *var=(*var * 10) + (ch-'0');
        ch=getc(stdin);
    }
    if(neg==true)
        *var = -(*var);
}
int main()
{
    int t;
    long int n,k,i;
    long long int part1max,part2max,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld%ld",&n,&k);
        long long int arr[n];
        for(i=0;i<n;i++)
        {
            readlonglongint(&arr[i]);
            //scanf("%lld",&arr[i]);
        }
        long long int dparrfor[n];
        long long int dparrback[n];
        maxSubArraySumforward(arr,n,dparrfor);
        maxSubArraySumbackward(arr,n,dparrback);
        ans = dparrfor[0] + dparrback[k+1];
        for(i=1;i<=(n-k-2);i++)
        {
            if((dparrfor[i]+dparrback[i+k+1])>ans)
                ans = dparrfor[i]+dparrback[i+k+1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
