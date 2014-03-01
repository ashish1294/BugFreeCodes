//http://www.spoj.com/problems/GSS1/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#define LL long long
inline LL int max(LL int a,LL int b){return a>b?a:b;}
struct node{
    LL int Lbest;
    LL int Rbest;
    LL int bests;
    LL sum;
};
LL arr[100000];
struct node tree[1000000];
struct node init(LL int si,int ss,int se)
{
    if(ss==se)
    {
        tree[si].Lbest=arr[ss];
        tree[si].Rbest=arr[se];
        tree[si].bests=arr[se];
        tree[si].sum=arr[se];
        return tree[si];
    }
    LL int mid = ss + (se-ss)/2;
    LL int next = 2LL*si;
    struct node aa = init(next+1,ss,mid), bb= init(next+2,mid+1,se);
    tree[si].Lbest = max(aa.Lbest,aa.sum+bb.Lbest);
    tree[si].Rbest = max(bb.Rbest,bb.sum+aa.Rbest);
    tree[si].bests = max(max(aa.bests,bb.bests),aa.Rbest+bb.Lbest);
    tree[si].sum = aa.sum+bb.sum;
    return tree[si];
}
struct node query(LL int si,int ss,int se,int qs,int qe)
{
    if(qs<=ss && qe>=se) return tree[si];
    LL int mid = ss + (se-ss)/2;
    LL int next = 2LL*si;
    if (qs<=mid && qe<=mid) return query(next+1,ss,mid,qs,qe);
    if (qs>mid) return query(next+2,mid+1,se,qs,qe);
    if(qs<=mid)
    {
        struct node aa = query(next+1,ss,mid,qs,qe),bb = query(next+2,mid+1,se,qs,qe),ret;
        ret.Lbest = max(aa.Lbest,aa.sum+bb.Lbest);
        ret.Rbest = max(bb.Rbest,bb.sum+aa.Rbest);
        ret.bests = max(max(aa.bests,bb.bests),aa.Rbest+bb.Lbest);
        ret.sum = aa.sum+bb.sum;
        return ret;
    }
};
inline LL int inp()
{
    register LL int noRead=0;
    int neg=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked()){if(p=='-') neg=1;};
    for(;p<48 || p>57;p=getc(stdin)){if(p=='-') neg=1;}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    if (neg) return -noRead;
    else return noRead;
};
int main()
{
    LL int n,i,m,x,y;
    //scanf("%lld",&n);
    n=inp();
    for(i=0;i<n;i++)
        arr[i]=inp();
        //scanf("%lld",&arr[i]);
    init(0,0,n-1);
    scanf("%lld",&m);
    for(i=0;i<m;i++)
    {
        x=inp();y=inp();
        //scanf("%lld %lld",&x,&y);
        struct node ans = query(0,0,n-1,x-1,y-1);
        printf("%lld\n",ans.bests);
    }
    return 0;
}
