//http://www.spoj.com/problems/COURAGE/
//Author Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<limits.h>
#define min(a,b) (a<b?a:b)
struct node{
    int s,m;
};
struct node tree[1000000];
long long int app[100001];
inline struct node init(int si,int ss,int se)
{
    if(ss==se)
    {
        tree[si].s=tree[si].m=app[ss];
        return tree[si];
    }
    int next = si+si,mid = ss + ((se-ss)/2);
    struct node aa = init(next+1,ss,mid),bb = init(next+2,mid+1,se);
    tree[si].s = aa.s + bb.s;
    tree[si].m = min(aa.m,bb.m);
    return tree[si];
}
inline struct node update(int si,int ss,int se,int val,int in)
{
    if(ss==se)
    {
        tree[si].s +=val;
        tree[si].m = tree[si].s;
        return tree[si];
    }
    int next = si+si,mid = ss + ((se-ss)/2);
    struct node aa,bb;
    if(in<=mid)
    {
        aa = update(next+1,ss,mid,val,in);
        bb = tree[next+2];
    }
    else
    {
        aa = tree[next+1];
        bb = update(next+2,mid+1,se,val,in);
    }
    tree[si].s = aa.s + bb.s;
    tree[si].m = min(aa.m,bb.m);
    return tree[si];
}
inline struct node query(int si,int ss,int se,int l,int r)
{
    if(l<=ss && r>=se) return tree[si];
    if(l>se || r<ss)
    {
        struct node aa;aa.s=0;aa.m = INT_MAX;
        return aa;
    }
    int next = 2LL*si,mid = ss + ((se-ss)/2);
    struct node aa = query(next+1,ss,mid,l,r),bb = query(next+2,mid+1,se,l,r),cc;
    cc.s = aa.s+bb.s;
    cc.m = min(aa.m,bb.m);
    return cc;
}
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
inline char inpc()
{
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<65 || p>90;p=getchar_unlocked());
    for(;p<65 || p>90;p=getc(stdin));
    return p;
};
int main()
{
    int n,i,p,x,y;
    char event;
    n=inp();
    for(i=0;i<n;i++) app[i]=inp();
    init(0,0,n-1);
    p=inp();
    while(p--)
    {
        event=inpc();x=inp();y=inp();
        if (event=='E') update(0,0,n-1,-x,y);
        else if(event=='G') update(0,0,n-1,x,y);
        else if(event=='C')
        {
            struct node ans = query(0,0,n-1,x,y);
            long long int as = ans.s - ans.m;
            printf("%lld\n",as);
        }
    }
    return 0;
}
