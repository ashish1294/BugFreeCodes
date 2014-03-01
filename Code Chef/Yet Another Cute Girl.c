#include<stdio.h>
static int arr[33]={1601558355,-673221153,-34112137,2147342173,-547359241,2144853879,2146959197,-134382121,-169910403,-579338273,-671221761,2011135869,-33693729,-142770217,2146917885,-545785985,-536873473,-168304649,2105407485,-8391201,-2629771,-537397283,-545292321,-35684489,-537395235,-681576961,1977614207,-9052161,-8423425,-34087427,2138961791,-673316897,-167805569};
int main()
{
    int t;
    long long m,n,i,co,temp,j;
    static int arr[1000005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&m,&n);
        memset(arr,0,sizeof(int)*(n-m+2));
        if(m==n)
        {
            long int a1;
            for(i=2;i<=m;i++)
            {
                if(m%i==0)
                {
                    long int a2=1;
                    while(m%i==0)
                    {
                        a2++;
                        m /= i;
                    }
                    a1*=a2;
                }
             }
            if(m>1)
                a1*=2;
            if((arr[a1>>5]&(1<<(a1%32)))==0)
                co=1;
            else
                co=0;
        }
        else
        {
        for(i=2;i*i<=n;i++)
        {
            for(j=(m/i)*i;j<=n;j+=i)
            {
                if(j!=i&&j>=m)
                {
                    arr[j-m]++;
                    if((j/i)*(j/i)>n)
                        arr[j-m]++;
                }
            }
        }
        co=0;
        for(i=m;i<=n;i++)
        {
            temp=arr[i-m]+2;
            if(i!=1)
                if ((arr[temp>>5]&(1<<(temp%32)))==0)
                    co++;
        }
        }
        printf("%lld\n",co);
    }
    return 0;
}
