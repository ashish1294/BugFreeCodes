//http://www.codechef.com/JULY15/problems/ADDMUL/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294

#include <stdio.h>
#define MOD 1000000007
int input()
{
    int noRead = 0;
    register char p = getchar_unlocked();
    for(;p < 48 || p > 57; p = getchar_unlocked());
    while(p > 47 && p< 58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0'); p=getchar_unlocked();}
    return noRead;
}
long long int arr[100010];
struct node{
    long long int add, mul, sum, set_val;
} tree[1000000];

long long int init(int si, int ss, int se)
{
    tree[si].add = 0, tree[si].mul = 1, tree[si].set_val = -1;
    if(ss == se)
        tree[si].sum = arr[ss];
    else
    {
        int mid = ss + (se-ss)/2;
        int next = 2LL*si;
        tree[si].sum = init(next+1,ss,mid) + init(next+2,mid+1,se) % MOD;
    }
    return tree[si].sum;
}

long long int query(int si, int ss, int se, int qs, int qe, int add_extra, int mul_extra, long long int set_val, int type, int val)
{
    if(set_val > 0)
    {
        tree[si].sum = ((se - ss + 1LL) * set_val) % MOD;
        tree[si].add = 0, tree[si].mul = 1, tree[si].set_val = set_val;
    }
    else
    {
        tree[si].sum = ( ((tree[si].sum * mul_extra) % MOD) + ((add_extra * (se - ss + 1LL)) % MOD) ) % MOD;
        tree[si].add = (((tree[si].add * mul_extra) % MOD) + add_extra) % MOD;
        tree[si].mul = (tree[si].mul * mul_extra) % MOD;
    }
    if(ss >= qs && se <= qe)
    {
        if(type == 1)
        {
            tree[si].sum = (tree[si].sum + (1LL * (se - ss + 1LL) * val) % MOD) % MOD;
            tree[si].add = (tree[si].add + val) % MOD;
        }
        else if(type == 2)
        {
            tree[si].sum = (tree[si].sum * val) % MOD;
            tree[si].mul = (tree[si].mul * val) % MOD;
            tree[si].add = (tree[si].add * val) % MOD;
        }
        else if(type == 3)
        {
            tree[si].sum = ((se - ss + 1LL) * val) % MOD;
            tree[si].add = 0, tree[si].mul = 1, tree[si].set_val = set_val;
        }
    }
    else if(qs > se || qe < ss)
    {
        if(type == 4) return 0;
    }
    else
    {
        int mid = ss + (se-ss)/2;
        int next = 2LL*si;
        tree[si].sum = 
            query(next + 1, ss, mid, qs, qe, tree[si].add, tree[si].mul, tree[si].set_val, type, val) +
            query(next + 2, mid + 1, se, qs, qe, tree[si].add, tree[si].mul, tree[si].set_val, type, val);
        tree[si].sum %= MOD;
        tree[si].add = 0, tree[si].mul = 1, tree[si].set_val = -1;
    }
    return tree[si].sum;
}

long long int display(int si, int ss, int se, int qs, int qe, int add_extra, int mul_extra, long long int set_val)
{
    struct node n = tree[si];
    if(set_val > 0)
    {
        n.sum = ((se - ss + 1LL) * set_val) % MOD;
        n.add = 0, tree[si].mul = 1, tree[si].set_val = set_val;
    }
    else
    {
        n.sum = (((tree[si].sum * mul_extra) % MOD) + ((add_extra * (se - ss + 1LL)) % MOD) ) % MOD;
        n.add = (((tree[si].add * mul_extra) % MOD) + add_extra) % MOD;
        n.mul = (tree[si].mul * mul_extra) % MOD;
    }
    //printf("disp si = %d %lld %lld %lld\n", si, n.sum, n.add, n.mul);
    if(ss >= qs && se <= qe) return n.sum;
    else if(qs > se || qe < ss) return 0;
    else
    {
        int mid = ss + (se-ss)/2;
        int next = 2LL*si;
        n.sum = 
            display(next + 1, ss, mid, qs, qe, n.add, n.mul, n.set_val) +
            display(next + 2, mid + 1, se, qs, qe, n.add, n.mul, n.set_val);
        return n.sum % MOD;
    }
}

long long int brute(int qs, int qe, int type, int val)
{
    int i;
    long long int ans = 0;
    for(i = qs; i <= qe; i++)
    {
        if(type == 1) arr[i] = (arr[i] + val) % MOD;
        else if(type == 2) arr[i] = (arr[i] * val) % MOD;
        else if(type == 3) arr[i] = (val) % MOD;
        else
        {
            ans = (ans + arr[i]) % MOD;
        }
    }
    return ans;
}

void print_tree()
{
    int i, n = 15;
    for(i = 0; i < 15; i++)
    {
        printf("tree[%d] = s = %lld, a = %lld, m = %lld, set = %lld\n", i, tree[i].sum, tree[i].add, tree[i].mul, tree[i].set_val);
    }
}

int main()
{
    int n = input(), q = input(), i, t, l, r, v;
    long long int ans;
    for(i = 0; i < n; i++) arr[i] = input();
    init(0, 0, n - 1);
    //printf("AFter init\n`");
    //print_tree();
    //printf("%lld\n", tree[0].sum);
    while(q--)
    {
        scanf("%d", &t);
        if(t < 4)
        {
            scanf("%d%d%d", &l, &r, &v);
            query(0, 0, n - 1, l - 1, r - 1, 0, 1, -1, t, v);
            brute(l -1, r - 1, t, v);
            //printf("Tree After query = \n");
            //print_tree();
        }
        else
        {
            scanf("%d%d",&l, &r);
            ans = display(0, 0, n - 1, l - 1, r - 1, 0, 1, -1);
            printf("%lld\n", ans);
            printf("brute = %lld\n", brute(l - 1, r - 1, 4, 0));       
        }
    }
    return 0;
}
