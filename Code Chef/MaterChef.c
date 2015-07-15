//http://www.codechef.com/JULY15/problems/MCHEF/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int rating[100010];
long long int max_rating[100010][510];
inline int inp()
{
    int noRead=0;
    int neg=0;
    register char p=getchar_unlocked();
    //register char p=getc(stdin);
    for(;p<48 || p>57;p=getchar_unlocked()){if (p=='-') neg=1;}
    //for(;p<48 || p>57;p=getc(stdin)){if(p=='-') neg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    if(neg) return -noRead;
    else return noRead;
};

long long int tree[1000000];

void init(int si,int ss,int se)
{
    tree[si] = INT_MAX;
    if(ss==se){return;}
    int mid = ss + (se-ss)/2;
    int next = 2LL*si;
    init(next+1,ss,mid);
    init(next+2,mid+1,se);
}

void update(int si,int ss,int se, int is, int ie, int cost)
{
    if (is<=ss && ie>=se)
    {
        tree[si] = min(tree[si], cost);
        return;
    }
    if(se<is || ss>ie){ return; }
    int mid = ss + ((se-ss)/2);
    int next = 2LL*si;
    update(next+1,ss,mid,is,ie, cost);
    update(next+2,mid+1,se,is,ie, cost);
}
int query(int si,int ss,int se, int point)
{
    if(ss == se && ss == point)
    {
        return tree[si];
    }
    else if(point >= ss && point <= se)
    {
        int mid = ss + ((se-ss)/2);
        int next = 2LL*si;
        int aa = query(next+1, ss, mid, point);
        int bb = query(next+2, mid+1, se, point);
        return min(min(aa, bb), tree[si]);
    }
    else return INT_MAX;
}

int main()
{
    int t, n, m, k, x, l, r, c, i, j;
    long long int total_rating;
    scanf("%d", &t);
    while(t--)
    {
        n = inp(), k = inp(), m = inp();
        total_rating = 0;
        for (i = 0; i < n; i++)
        {
            x = inp();
            total_rating += x;
            if (x < 0) rating[i] = -x;
            else rating[i] = 0;
        }
        init(0, 0, n - 1);
        for(i = 0; i < m; i++)
        {
            l = inp(), r = inp(), c = inp();
            update(0, 0, n - 1, l - 1, r - 1, c);
        }
        for (j = 0; j <= n; j++) max_rating[0][j] = 0;
        for (i = 1; i <= n; i++)
        {
            max_rating[i][0] = 0;
            x = query(0, 0, n - 1, i - 1);
            for (j = 1; j <= k; j++)
            {
                if(x > j) max_rating[i][j] = max_rating[i-1][j];
                else max_rating[i][j] = max(rating[i - 1] + max_rating[i-1][j - x], max_rating[i-1][j]);
            }
        }
        printf("%lld\n", total_rating + max_rating[n][k]);
    }
    return 0;
}
