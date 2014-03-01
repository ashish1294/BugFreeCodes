//http://www.spoj.com/problems/KGSS/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<limits.h>
#define LL long long int
struct node{int m1,m2;};
int arr[200000];
struct node tree[1000000];
struct node init(LL si,int ss,int se)
{
    if(ss==se)
    {
        tree[si].m1=arr[ss];
        tree[si].m2=INT_MIN;
        return tree[si];
    }
    else
    {
        int mid = ss + ((se-ss)/2);
        int next = 2LL*si;
        struct node aa = init(next+1,ss,mid);
        struct node bb = init(next+2,mid+1,se);
        if(aa.m1>bb.m1)
        {
            tree[si].m1=aa.m1;
            if(aa.m2>bb.m1) tree[si].m2=aa.m2;
            else tree[si].m2=bb.m1;
        }
        else
        {
            tree[si].m1=bb.m1;
            if(bb.m2>aa.m1) tree[si].m2=bb.m2;
            else tree[si].m2=aa.m1;
        }
        return tree[si];
    }
}
struct node update(int si,int ss,int se,int in,int val)
{
    if(ss==se)
    {
        tree[si].m1=val;
        arr[ss]=val;
        return tree[si];
    }
    int mid = ss + ((se-ss)/2);
    struct node aa,bb;
    int next = 2LL*si;
    if(in<=mid)
    {
        aa = update(next+1,ss,mid,in,val);
        bb = tree[next+2];
    }
    else
    {
        aa = update(next+2,mid+1,se,in,val);
        bb = tree[next+1];
    }
    if(aa.m1>bb.m1)
    {
        tree[si].m1=aa.m1;
        if(aa.m2>bb.m1) tree[si].m2=aa.m2;
        else tree[si].m2=bb.m1;
    }
    else
    {
        tree[si].m1=bb.m1;
        if(bb.m2>aa.m1) tree[si].m2=bb.m2;
        else tree[si].m2=aa.m1;
    }
    return tree[si];
}
struct node query(LL si,int ss,int se,int qs,int qe)
{
    if (qs<=ss && qe>=se) return tree[si];
    struct node aa, bb,nn;
    if (se<qs || ss>qe){aa.m1=INT_MIN;aa.m2=INT_MIN;return aa;}
    LL mid = ss + ((se-ss)/2);
    int next = 2LL*si;
    aa = query(next+1,ss,mid,qs,qe);
    bb = query(next+2,mid+1,se,qs,qe);
    if(aa.m1>bb.m1)
    {
        nn.m1=aa.m1;
        if(aa.m2>bb.m1) nn.m2=aa.m2;
        else nn.m2=bb.m1;
    }
    else
    {
        nn.m1=bb.m1;
        if(bb.m2>aa.m1) nn.m2=bb.m2;
        else nn.m2=aa.m1;
    }
    return nn;
}
inline int inp()
{int noRead=0;
  register char p=getchar_unlocked();
  for(;p<33;p=getchar_unlocked());
  while(p>32){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');
  p=getchar_unlocked();}return noRead;};
int main()
{
    int n,i,q,s,e;
    struct node ans;
    char ch;
    //scanf("%d",&n);
    n=inp();
    for(i=0;i<n;i++)
        //scanf("%d",&arr[i]);
        arr[i]=inp();
    init(0,0,n-1);
    //scanf("%d",&q);
    q=inp();
    while(q--)
    {
        ch=getchar_unlocked();
        while(ch!='U'&&ch!='Q') ch = getchar_unlocked();
        //scanf("%*c%c",&ch);
        //scanf("%d%d",&s,&e);
        s=inp(); e=inp();
        if(ch=='U') update(0,0,n-1,s-1,e);
        else
        {
            ans=query(0,0,n-1,s-1,e-1);
            printf("%d\n",ans.m1+ans.m2);
        }
    }
    return 0;
}
