//http://www.spoj.com/problems/SNGINT/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define getchar_unlocked() getc(stdin)
#define putchar_unlocked(x) putc(x,stdout)
inline int inp()
{
    int noRead=0;
    register char p=getc(stdin);
    for(;p<48 || p>57;p=getc(stdin));
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
int arr[10];
int main()
{
    int t=inp(),n,i,nc;
    while(t--)
    {
        n=inp();nc=n;
        for(i=9;i>1 && n>1;i--)
        {
            arr[i]=0;
            while(n%i==0)
            {
                arr[i]++;
                n/=i;
            }
        }
        if(nc==0) printf("10");
        else if(nc==1) printf("1");
        else if(n!=1) printf("-1");
        else
        {
            for(i=2;i<10;i++)
                while(arr[i])
                {
                    printf("%d",i);
                    arr[i]--;
                }
        }
        printf("\n");
    }
    return 0;
}
