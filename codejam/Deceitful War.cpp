#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
long double a1[1010],a2[1010],a3[1010];
int issel[1010];
int main()
{
    int t,n,i,j,p1,flag;
    scanf("%d",&t);
    for(int ti=1;ti<=t;ti++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%Lf",&a1[i]);
            issel[i]=0;
        }
        for(i=0;i<n;i++)
        {
            scanf("%Lf",&a2[i]);
            a3[i]=a2[i];
        }
        sort(a1,a1+n);
        sort(a2,a2+n);
        for(i=0,p1=0;i<n;i++)
        {
            for(j=0,flag=0;j<n;j++)
            {
                if(issel[j]==0 && a2[j]>a1[i])
                {
                    p1++;
                    issel[j]=1;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(j=0;j<n;j++)
                {
                    if(issel[j]==0)
                    {
                        issel[j]=1;
                        break;
                    }
                }
            }
        }
        int l1=0,r1=n-1,p2=0;
        for(i=n-1;i>=0;i--)
        {
            if(a1[r1]>a2[i])
            {
                p2++;
                r1--;
            }
            else
            {
                l1++;
            }
        }
        printf("Case #%d: %d %d\n",ti,p2,n-p1);
    }
    return 0;
}
