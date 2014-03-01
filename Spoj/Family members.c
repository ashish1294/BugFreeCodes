//http://www.spoj.com/problems/FAMWEALT/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
long long int tree[1000010];
void update(int no)
{
    int l=no+no;
    int r=l+1;
    if(l<=1000000)
    {
        tree[l] = tree[no]+tree[no];
        update(l);
    }
    if(no%2==0 && r<=1000000)
    {
        tree[r] = tree[no] + tree[no];
        update(r);
    }
    else if(r<=1000000)
    {
        tree[r] = tree[no] + tree[no] + tree[no] +tree[no];
        update(r);
    }
}
int main()
{
    int i,t,x,y,w;
    for(i=0;i<=1000000;i++) tree[i]=0;
    tree[1]=1; update(1);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&x,&y,&w);
        //printf("t[x]=%lld t[y]=%lld\n",tree[x],tree[y]);
        double ans = (double)((((double)tree[x])*w)/(tree[y]));
        printf("%.6lf\n",ans);
    }
    return 0;
}
