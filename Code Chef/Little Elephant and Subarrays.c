//http://www.codechef.com/FEB14/problems/SUBMIN/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
inline int inp()
{
    int noRead=0;
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
    int n=inp(),i,arr[60],q,k,l,r,x,ans=0;
    for(i=0;i<n;i++) arr[i]=inp();
    q=inp();
    while(q--)
    {
        k=inp(); ans=0;
        for(i=0;i<n;i++)
            if(arr[i]==k)
            {
                l=r=0;
                for(x=i-1;x>=0 && arr[x]>k;l++,x--);
                for(x=i+1;x<n && arr[x]>=k;r++,x++);
                ans += (r*(l+1))+l+1;
            }
        printf("%d\n",ans);
    }
    return 0;
}
