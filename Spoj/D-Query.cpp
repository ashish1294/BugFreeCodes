//http://www.spoj.com/problems/DQUERY/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<cstdio>
#include<algorithm>
#define MAX_N 30000
#define MAX_Q 200000
using namespace std;
struct event{
    int a,b;
    int index;
    bool type;
};
bool comp(event cc, event dd)
{
    //event* cc = ((event *)aa);
    //event* dd = ((event *)bb);
    if(cc.b!=dd.b) return (cc.b<dd.b);
    else if(cc.type==0) return true;
    else if(dd.type==0) return false;
    else return (cc.a<dd.a);
}
event arr[MAX_N+MAX_Q];
int tree[100000];
int last[1000001];
int ans[MAX_Q];
int update(int si,int ss,int se,int in,int val)
{
    if(ss==se)
    {
        if(val==1) {tree[si]++; return tree[si];}
        else if(val==-1){tree[si]--;return tree[si];}
    }
    int mid = ss + ((se-ss)/2);
    int next = 2LL*si;
    int aa,bb;
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
    tree[si]=aa+bb;
    return tree[si];
}
int query(int si,int ss,int se,int qs,int qe)
{
    if (qs<=ss && qe>=se) return tree[si];
    if (se<qs || ss>qe){return 0;}
    int mid = ss + ((se-ss)/2);
    int next = 2LL*si;
    return query(next+1,ss,mid,qs,qe)+query(next+2,mid+1,se,qs,qe);
}
inline int inp()
{
    int noRead=0;
    int neg=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked()){if (p=='-') neg=1;}
    for(;p<48 || p>57;p=getc(stdin)){if(p=='-') neg=1;}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    if(neg) return -noRead;
    else return noRead;
};
int main()
{
    int n,q;
    n=inp();
    //scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        arr[i].a=inp();
        //scanf("%d",&arr[i].a);
        arr[i].b=i+1;
        arr[i].type=0;
    }
    q=inp();
    //scanf("%d",&q);
    int en = n+q;
    for(int i=n;i<en;i++)
    {
        arr[i].a=inp(); arr[i].b=inp();
        //scanf("%d%d",&arr[i].a,&arr[i].b);
        arr[i].type=1;
        arr[i].index=i-n;
    }
    sort(arr,arr+en,comp);
    int k=0;
    for(int i=0;i<100000;i++) tree[i]=0;
    for(int i=0;i<1000000;i++) last[i]=-1;
    for(int i=0;i<en;i++)
    {
        if(arr[i].type==0)
        {
            if(last[arr[i].a]!=-1) update(0,0,n-1,last[arr[i].a],-1);
            update(0,0,n-1,arr[i].b-1,1);
            last[arr[i].a]=arr[i].b-1;
        }
        else
        {
            ans[arr[i].index] = query(0,0,n-1,arr[i].a-1,arr[i].b-1);
        }
    }
    for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}
