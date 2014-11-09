//http://www.codechef.com/APRIL14/problems/ADIGIT
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define getchar_unlocked() getc(stdin)
#define putchar_unlocked(x) putchar(x)
static int arr[10][100001],ori[100001];
inline int inp()
{
    register int noRead=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked());
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    return noRead;
};
int main()
{
    int n=inp(),m=inp(),i,j,x,sp,stk[20];
    register char c = getchar_unlocked();
    while(c<48 || c>57) c = getchar_unlocked();
    for(i=1;i<=n;i++)
    {
        ori[i]=c-'0';
        c=getchar_unlocked();
        for(j=0;j<10;j++)
        {
            if(ori[i]>j) arr[j][i]=arr[j][i-1]+ori[i]-j;
            else arr[j][i]=arr[j][i-1]+j-ori[i];
        }
    }
    for(i=0;i<m;i++)
    {
        x=inp();
        x=arr[ori[x]][x-1];
        if(x==0) putchar_unlocked('0');
        else
        {
            sp=0;
            while(x)
            {
                stk[sp++]=x%10+ '0';
                x/=10;
            }
            sp--;
            while(sp>=0) putchar_unlocked(stk[sp--]);
        }
        putchar_unlocked('\n');
    }
    return 0;
}
