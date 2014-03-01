//http://www.spoj.com/problems/LITE/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294

//Segment Tree with Lazy Propogation
#include<stdio.h>
struct node{
    int sum,extra;
};
struct node tree[1000000];
struct node update(int si,int ss,int se,int is,int ie)
{
    if (is<=ss && ie>=se)
    {
        tree[si].sum=se-ss+1-tree[si].sum;
        tree[si].extra^=1;
        return tree[si];
    }
    if(se<is || ss>ie){ return tree[si]; }
    int mid = ss + ((se-ss)/2);
    int next = 2LL*si;
    struct node aa=update(next+1,ss,mid,is,ie),bb=update(next+2,mid+1,se,is,ie);
    tree[si].sum=aa.sum+bb.sum;
    if(tree[si].extra==1) tree[si].sum=se-ss+1-tree[si].sum;
    return tree[si];
}
int query(int si,int ss,int se,int qs,int qe,int pass)
{
    if (qs<=ss && qe>=se)
    {
        int tot=pass%2;
        if(tot==0) {return tree[si].sum;}
        else {return (se-ss+1-tree[si].sum);}
    }
    else if(ss>qe || se<qs){return 0;}
    int mid = ss + ((se-ss)/2);
    int next = 2LL*si;
    int aa = query(next+1,ss,mid,qs,qe,tree[si].extra+pass);
    int bb = query(next+2,mid+1,se,qs,qe,tree[si].extra+pass);
    return aa+bb;
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
void init(int si,int ss,int se)
{
    tree[si].sum=0;tree[si].extra=0;
    if(ss==se){return;}
    int mid = ss + (se-ss)/2;
    int next = 2LL*si;
    init(next+1,ss,mid);init(next+2,mid+1,se);
}
int main()
{
    int n,m,a,b,c,i;
    n=inp();m=inp();
    init(0,0,n-1);
    while(m--)
    {
        a=inp();b=inp();c=inp();
        if(a==0)
        {
            update(0,0,n-1,b,c);
        }
        else
        {
            printf("%d\n",query(0,0,n-1,b-1,c-1,0));
        }
    }
    return 0;
}
