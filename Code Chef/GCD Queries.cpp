/*
    Problem : Chef and Stones
    Link : http://www.codechef.com/JAN15/problems/GCD
    User : ashish1294
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010], tree[5000010];
int gcd(int x, int y)
{
    return (y == 0 ? x : gcd(y, x%y));
}
int init(int si, int st, int en)
{
    if(st == en)
    {
        tree[si] = a[st];
        return tree[si];
    }
    int mid = ((en - st)>>1) + st, newst = si<<1;
    int x = init(newst, st, mid);
    int y = init(newst + 1, mid + 1, en);
    //printf("st = %d, en = %d, x = %d, y = %d\n", st, en, x, y);
    tree[si] = gcd(x, y);
    return tree[si];
}
int query(int si, int st, int en, int qst, int qen)
{
    //printf("st = %d, en = %d, qst = %d, qen = %d\n", st, en, qst, qen);
    if(qen < qst || qst > en || qen < st) return 0;
    if(qst <= st && qen >= en)
    {
        return tree[si];
    }
    int mid = ((en - st)>>1) + st, newst = si<<1;
    int x = query(newst, st, mid, qst, qen);
    int y = query(newst + 1, mid + 1, en, qst, qen);
    int ret = gcd(x, y);
    //printf("st = %d, en = %d, qst = %d, qen = %d ans = %d\n", st, en, qst, qen, ret);
    return ret;
}
int main()
{
    int t, n, q, l, r, x, y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        init(1, 1, n);
        while(q--)
        {
            scanf("%d%d", &l, &r);
            x = query(1, 1, n, 1, l - 1);
            y = query(1, 1, n, r + 1, n);
            //printf("x = %d, y = %d\n", x, y);
            printf("%d\n", gcd(x, y));
        }
    }
    return 0;
}
