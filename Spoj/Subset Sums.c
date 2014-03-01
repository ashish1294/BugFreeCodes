//http://www.spoj.com/problems/SUBSUMS/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int comp(const void*a,const void*b)
{
    long long int aa =*((long long int*)a);
    long long int bb =*((long long int*)b);
    if(aa<bb) return 0; else return 1;
}
inline int inp()
{
    register int noRead=0;
    register bool neg=false;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked()){if(p=='-')neg=1;};
    for(;p<48 || p>57;p=getc(stdin)){if(p=='-')neg=1;};
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    if(neg) return (-noRead);
    else return noRead;
};
inline long long int linp()
{
    register long long int noRead=0;
    register bool neg=false;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    if(p=='-') neg=1;
    //for(;p<48 || p>57;p=getchar_unlocked()){if(p=='-')neg=1;}
    for(;p<48 || p>57;p=getc(stdin)){if(p=='-')neg=1;}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    if(neg) return (-noRead);
    else return noRead;
};
int main()
{
    long long int n,tt,i,j,p,q,pl,pu,C,D,ss=0;
    //scanf("%lld%lld%lld",&n,&C,&D);
    n=linp();C=linp();D=linp();
    tt=n>>1;
    long long int A[tt],B[n-tt];
    for(i=0;i<tt;i++)
    {
        //scanf("%lld",&A[i]);
        A[i]=linp();
    }
    p=1<<tt;
    long long int ListA[p];
    for(i=0;i<p;i++)
    {
        ListA[i]=0;
        for(j=0;j<=tt;j++)
            if(i&(1<<j)) ListA[i] += A[j];
    }
    //printf("Arr A: p=%lld\n",p); for(i=0;i<p;i++) printf("%lld ",ListA[i]); printf("\n");
    qsort(ListA,p,sizeof(long long int),comp);
    //printf("Arr A:"); for(i=0;i<p;i++) printf("%lld ",ListA[i]); printf("\n");
    tt=n-tt;
    for(i=0;i<tt;i++)
    {
        //scanf("%lld",&B[i]);
        B[i]=linp();
    }
    q=1<<tt;
    long long int ListB[q];
    for(i=0;i<q;i++)
    {
        ListB[i]=0;
        for(j=0;j<tt;j++)
            if(i&(1<<j)) ListB[i] += B[j];
    }
    //printf("Arr B:"); for(i=0;i<q;i++) printf("%lld ",ListB[i]);printf("\n");
    qsort(ListB,q,sizeof(long long int),comp);
    //printf("Arr B:"); for(i=0;i<q;i++) printf("%lld ",ListB[i]);printf("\n");
    ss=0;
    for(i=0,pl=q-1,pu=q-1;i<p;i++)
    {
        while(pl>=0 && ListB[pl]>=(C-ListA[i])) pl--;
        while(pu>pl && ListB[pu]>(D-ListA[i])) pu--;
        ss += (pu-pl);
       // printf("i=%lld ele=%lld pl=%lld pu=%lld vall=%lld valu=%lld added=%lld\n",i,ListA[i],pl,pu,ListB[pl],ListB[pu],pu-pl);
    }
    printf("%lld\n",ss);
    return 0;
}
