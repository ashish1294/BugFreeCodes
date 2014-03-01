//http://www.spoj.com/problems/MULTQ3/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294

//Segment Tree with Lazy Propogation
#include<stdio.h>
struct node{
    int mod0,mod1,mod2,extra;
};
void rot(struct node*a){int t=a->mod0;a->mod0=a->mod2;a->mod2=a->mod1;a->mod1=t;}
struct node tree[1000000];
struct node update(int si,int ss,int se,int is,int ie)
{
    if (is<=ss && ie>=se) {tree[si].extra++;tree[si].extra%=3;rot(&tree[si]);return tree[si];}
    if (se<is || ss>ie){return tree[si];}
    int mid = ss + ((se-ss)/2);
    int next = 2LL*si;
    struct node aa=update(next+1,ss,mid,is,ie),bb=update(next+2,mid+1,se,is,ie);
    tree[si].mod0=aa.mod0+bb.mod0;tree[si].mod1=aa.mod1+bb.mod1;tree[si].mod2=aa.mod2+bb.mod2;
    tree[si].extra%=3;
    if(tree[si].extra==1)rot(&tree[si]);
    else if(tree[si].extra==2){rot(&tree[si]);rot(&tree[si]);}
    return tree[si];
}
int query(int si,int ss,int se,int qs,int qe,int pass)
{
    if (qs<=ss && qe>=se)
    {
        int tot = (pass)%3;
        if(tot==0) return tree[si].mod0;
        else if(tot==1) return tree[si].mod2;
        else return tree[si].mod1;
    }
    if (se<qs || ss>qe){return 0;}
    int mid = ss + ((se-ss)/2);
    int next = 2LL*si;
    int aa = query(next+1,ss,mid,qs,qe,tree[si].extra+pass);
    int bb = query(next+2,mid+1,se,qs,qe,tree[si].extra+pass);
    return aa+bb;
}
int init(int si,int ss,int se)
{
    if(ss==se){tree[si].mod0=1;tree[si].mod1=0;tree[si].mod2=0;tree[si].extra=0;return 1;}
    int mid = ss + (se-ss)/2;
    int next = 2LL*si;
    int aa = init(next+1,ss,mid),bb=init(next+2,mid+1,se);
    tree[si].mod0=aa+bb;tree[si].mod1=0;tree[si].mod2=0;tree[si].extra=0;
    return tree[si].mod0;
}
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
    int n,q,a,b,c;
    n=inp();q=inp();
    init(0,0,n-1);
    while(q--)
    {
        a=inp();b=inp();c=inp();
        if(a==0)  update(0,0,n-1,b,c);
        else printf("%d\n",query(0,0,n-1,b,c,0));
    }
    return 0;
}
