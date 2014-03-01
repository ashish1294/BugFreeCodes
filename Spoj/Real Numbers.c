//http://www.spoj.com/problems/REALNO/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
double ar,mi,ma;
int main()
{
    int t,n,i,flag=0;
    char c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%lf",&ar);
        flag=0;
        mi=1-ar;
        ma=2-ar;
        for(i=1;i<n;i++)
        {
            scanf("%lf",&ar);
            if(flag==0 && ar>mi && ar<ma)
            {
                flag=1;
                c=getc(stdin);
                while(c!='\n') c=getc(stdin);
                //c=getchar_unlocked();
                //while(c!='\n') c=getchar_unlocked();
                break;
            }
            else
            {
                if(mi>0) mi=min(mi,1-ar);
                if(ma<2) ma=max(ma,2-ar);
            }
        }
        if(flag) printf("found\n");
        else printf("not found\n");
    }
    return 0;
}
