//http://www.codechef.com/problems/MARCHA1/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<math.h>
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
    int t,n,m,sum,j;
    int flag=0;
    long long int i;
    scanf("%d",&t);
    int notes[20];
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&notes[i]);
        flag=0;
        for (i=(1<<n)-1;i>=0;i--)
        {
            sum=0;
            for(j=0;j<n;j++)
                if (i & (1<<j))
                    sum += notes[j];
            if (sum==m)
            {
                printf("Yes\n");
                flag=1;
                break;
            }
        }
        if (flag==0)
            printf("No\n");
    }
    return 0;
}
