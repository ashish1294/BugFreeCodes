//http://www.codechef.com/COOK42/problems/CAKE1AM
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
int main()
{
    int t,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,a1,a2,a3,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
        a1=((x2-x1)*(y2-y1));
        a2=((x4-x3)*(y4-y3));
        x5=max(x1,x3);y5=max(y1,y3);x6=min(x2,x4);y6=min(y2,y4);
        if(x5<x6 && y5<y6)
        {
            a3=((x6-x5)*(y6-y5));
        }
        else a3=0;
        ans=a1+a2-a3;
        printf("%d\n",ans);
    }
    return 0;
}
