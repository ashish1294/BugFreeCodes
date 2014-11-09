//http://www.codechef.com/MARCH14/problems/STREETTA/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<limits.h>
#define inter(a,x) (((x>a.st || (x==a.st && a.tst==1)) && (x<a.en || (x==a.en && a.ten==1)))?1:0)
#define intersect(a,b) ((((a.st>b.en || (a.st==b.en && a.tst==0)) || (a.en<b.st || (a.en==b.st && a.ten==0))))?0:1)
#define MAXM 300000
using namespace std;
inline int inp()
{
    register int noRead=0,isneg=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked()) {if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    if(isneg) return (-noRead);
    else return noRead;
};
char stk[22];int sp;
inline void fo(long long int n)
{
    sp=0;
    if(n<0)
    {
        putchar_unlocked('-');
        n=-n;
    }
    while(n)
    {
        stk[sp++] = (n%10) + '0';
        n/=10;
    }
    sp--;
    while(sp>=0) putchar_unlocked(stk[sp--]);
}
struct inte{
    int st, en, a, b;
    bool type;
};
typedef struct inte inte;
struct seg_int{
    int st,en;
    bool tst,ten;
};
struct node
{
    vector<inte> v;
    struct seg_int inter;
    long long int a1, b1, a2, b2;
};
struct pp{long long int first,second;};
int *points, *fp;
struct inte *arr;
//inte arr[MAXM];
bool *isque;
//bool isque[MAXM];
//node *root,*tree;
node root[(MAXM<<1)+1], tree[1200100];
seg_int init_seg(int si, int ss, int se)
{
    if(ss==se)
    {
        root[ss].a2=root[ss].b2=0;
        root[ss].a1=0;root[ss].b1=LLONG_MIN;
        return root[ss].inter;
    }
    int mid = ss+ ((se-ss)/2), next = (si+si) + 1;
    seg_int aa = init_seg(next,ss,mid), bb = init_seg(next+1,mid+1,se);
    tree[si].inter.st=aa.st;tree[si].inter.tst=aa.tst;
    tree[si].inter.en=bb.en;tree[si].inter.ten=bb.ten;
    tree[si].a2=tree[si].b2=tree[si].a1=0;
    tree[si].b1=LLONG_MIN;
    return tree[si].inter;
}
void ins_seg(int si, int ss, int se, inte x)
{
    if (ss==se)
    {
        if(root[ss].inter.st>=x.st && root[ss].inter.en<=x.en)
        {
            if(x.type)
            {
                long long int dif = root[ss].inter.st-x.st;
                long long int ps = (dif * x.a) + x.b;
                root[ss].b2 += ps; root[ss].a2 += x.a;
            }
            else
            {
                long long int dif = root[ss].inter.st-x.st;
                long long int ps = (dif * x.a) + x.b;
                if(ps>root[ss].b1)
                {
                    root[ss].b1=ps;
                    root[ss].a1=x.a;
                }
            }
        }
        return;
    }
    if(intersect(tree[si].inter,x)==0) return;
    if(tree[si].inter.st>=x.st && tree[si].inter.en<=x.en)
    {
        if(x.type)
        {
            long long int dif = tree[si].inter.st-x.st;
            long long int ps = (dif * x.a) + x.b;
            tree[si].b2 += ps; tree[si].a2 += x.a;
        }
        else
        {
            long long int dif = tree[si].inter.st-x.st;
            long long int ps = (dif * x.a) + x.b;
            if(tree[si].b1==LLONG_MIN)
            {
                tree[si].b1=ps;
                tree[si].a1=x.a;
                return;
            }
            else
            {
                if(x.a==tree[si].a1)
                {
                    if(ps>tree[si].b1) tree[si].b1=ps;
                    return;
                }
                double num = tree[si].b1-ps;
                double dnum = x.a-tree[si].a1;
                double dan = num/dnum;
                if(dan<0 || dan>=(tree[si].inter.en-tree[si].inter.st))
                {
                    if(ps>tree[si].b1)
                    {
                        tree[si].b1=ps;
                        tree[si].a1=x.a;
                    }
                    return;
                }
                tree[si].v.push_back(x);
            }
        }
    }
    else
    {
        int mid = ss + ((se-ss)/2), next = (si+si) + 1;
        ins_seg(next,ss,mid,x);
        ins_seg(next+1,mid+1,se,x);
    }
}
struct pp query_seg(int si,int ss, int se, int index)
{
    struct pp aa,bb;
    aa.first=LLONG_MIN;aa.second=0;
    long long int mm,diff;
    if(ss==se)
    {
        if(inter(root[ss].inter,index)==0) return aa;
        aa.first = ((index-root[ss].inter.st)*root[ss].a1) + root[ss].b1;
        aa.second += ((index-root[ss].inter.st)*root[ss].a2) + root[ss].b2;
        return aa;
    }
    if(inter(tree[si].inter,index)==0) return aa;
    int mid = ss + ((se-ss)/2), next = (si+si)+1,i;
    aa = query_seg(next,ss,mid,index);
    bb = query_seg(next+1,mid+1,se,index);
    if(bb.first>aa.first) aa.first=bb.first;
    aa.second += bb.second;
    long long int tt = ((index-tree[si].inter.st)*tree[si].a1) + tree[si].b1;
    if(tt>aa.first) aa.first=tt;
    aa.second += ((index-tree[si].inter.st)*tree[si].a2) + tree[si].b2;
    for(i=0;i<tree[si].v.size();i++)
    {
        diff=index-tree[si].v[i].st;
        mm = ( tree[si].v[i].a * diff ) + tree[si].v[i].b;
        if(mm>aa.first) aa.first=mm;
    }
    return aa;
}
int main()
{
    int n,m,i,j,k,op,fi,pi,si;
    struct pp ans;
    n=inp();m=inp();
    points = (int*) malloc(sizeof(int)*(m<<1));
    fp = (int*) malloc(sizeof(int)*(m<<1));
    arr = (struct inte*) malloc(sizeof(struct inte)*m);
    isque = (bool*) malloc(sizeof(bool)*m);
    for(i=0,pi=0;i<m;i++)
    {
        op=inp();
        if(op<3)
        {
            arr[i].st=inp();arr[i].en=inp();arr[i].a=inp();arr[i].b=inp();
            arr[i].type=op-1;
            points[pi++]=arr[i].st;
            points[pi++]=arr[i].en;
            isque[i]=false;
        }
        else
        {
            arr[i].st=inp();
            points[pi++]=arr[i].st;
            isque[i]=true;
        }
    }
    sort(points,points+pi);
    for(i=0,si=0;i<pi;)
    {
        fp[si++]=points[i];
        i++;
        while(i<pi && points[i]==points[i-1]) i++;
    }
    //root=(node*) malloc(sizeof(node)*((si<<1)+2));
    //tree=(node*) malloc(sizeof(node)*((si<<2)+10));
    fi=0;
    if(si)
    {
        root[fi].inter.st=INT_MIN;
        root[fi].inter.en=fp[0];
        root[fi].inter.tst=root[fi].inter.ten=0;
        fi++;
    }
    for(i=0;i<si-1;i++)
    {
        root[fi].inter.st=root[fi].inter.en=fp[i];root[fi].inter.tst=root[fi].inter.ten=1;
        fi++;
        root[fi].inter.st=fp[i];root[fi].inter.en=fp[i+1];root[fi].inter.tst=root[fi].inter.ten=0;
        fi++;
    }
    if(si)
    {
        root[fi].inter.st=root[fi].inter.en=fp[si-1];root[fi].inter.tst=root[fi].inter.ten=1;
        fi++;
        root[fi].inter.st=fp[si-1];root[fi].inter.en=INT_MAX;root[fi].inter.tst=root[fi].inter.ten=0;
        fi++;
    }
    if(fi) init_seg(0,0,fi-1);
    for(i=0;i<m;i++)
    {
        if(!isque[i]) ins_seg(0,0,fi-1,arr[i]);
        else
        {
            ans=query_seg(0,0,fi-1,arr[i].st);
            if(ans.first==LLONG_MIN)
            {
                putchar_unlocked('N');
                putchar_unlocked('A');
            }
            else fo(ans.first+ans.second);
            putchar_unlocked('\n');
        }
    }
    return 0;
}
