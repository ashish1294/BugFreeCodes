/*
    Problem : Chef and Stones
    Link : http://www.codechef.com/JAN15/problems/QSET
    User : ashish1294
*/
#include<bits/stdc++.h>
using namespace std;
char str[100010];
struct node{
    long long int stl[3], enr[3], o[3], whole_sum;
};
struct node tree[300010], dummy;
struct node init(int si, int st, int en)
{
    tree[si].stl[0] = tree[si].stl[1] = tree[si].stl[2] = 0;
    tree[si].enr[0] = tree[si].enr[1] = tree[si].enr[2] = 0;
    tree[si].o[0] = tree[si].o[1] = tree[si].o[2] = 0;
    if(st == en)
    {
        tree[si].whole_sum = (str[st - 1] - '0') % 3;
        //printf("st = %d char = %c sum = %lld\n", st, str[st], tree[si].whole_sum);
        tree[si].stl[tree[si].whole_sum]++;
        tree[si].enr[tree[si].whole_sum]++;
        tree[si].o[tree[si].whole_sum]++;
        return tree[si];
    }
    int mid = ((en - st)>>1) + st, newst = si<<1;
    node left = init(newst, st, mid);
    node right = init(newst + 1, mid + 1, en);
    for(int i = 0 ; i < 3; i++)
    {
        tree[si].stl[i] += left.stl[i];
        tree[si].stl[(left.whole_sum + i) % 3] += right.stl[i];
        if(st == 1 && en == 2)
        {
            //printf("1, 2 stl[%d] = %lld, stl[%lld] = %lld\n", i, left.stl[i], (left.whole_sum + i) % 3, right.stl[i]);
        }
        tree[si].enr[i] += right.enr[i];
        tree[si].enr[(right.whole_sum + i) % 3] += left.enr[i];

        tree[si].o[i] = left.o[i] + right.o[i];
        for(int j = 0; j < 3; j++)
        {
            tree[si].o[(i + j) % 3] += left.enr[i] * right.stl[j];
        }
    }
    tree[si].whole_sum = (left.whole_sum + right.whole_sum) % 3;
    return tree[si];
}
struct node change(int si, int st, int en, int loc, int new_val)
{
    if(loc < st || loc > en) return tree[si];
    tree[si].stl[0] = tree[si].stl[1] = tree[si].stl[2] = 0;
    tree[si].enr[0] = tree[si].enr[1] = tree[si].enr[2] = 0;
    tree[si].o[0] = tree[si].o[1] = tree[si].o[2] = 0;
    if(st == en)
    {
        tree[si].whole_sum = new_val % 3;
        tree[si].stl[tree[si].whole_sum]++;
        tree[si].enr[tree[si].whole_sum]++;
        tree[si].o[tree[si].whole_sum]++;
        return tree[si];
    }
    int mid = ((en - st)>>1) + st, newst = si<<1;
    node left = change(newst, st, mid, loc, new_val);
    node right = change(newst + 1, mid + 1, en, loc, new_val);
    for(int i = 0 ; i < 3; i++)
    {
        tree[si].stl[i] += left.stl[i];
        tree[si].stl[(left.whole_sum + i) % 3] += right.stl[i];

        tree[si].enr[i] += right.enr[i];
        tree[si].enr[(right.whole_sum + i) % 3] += left.enr[i];

        tree[si].o[i] = left.o[i] + right.o[i];
        for(int j = 0; j < 3; j++)
        {
            tree[si].o[(i + j) % 3] += left.enr[i] * right.stl[j];
        }
    }
    tree[si].whole_sum = (left.whole_sum + right.whole_sum) % 3;
    return tree[si];
}
struct node query(int si, int st, int en, int qst, int qen)
{
    if(qen < st || qst > en) return dummy;
    if(st >= qst && en <= qen) return tree[si];
    int mid = ((en - st)>>1) + st, newst = si<<1;
    node left = query(newst, st, mid, qst, qen), ret;
    node right = query(newst + 1, mid + 1, en, qst, qen);
    ret.stl[0] = ret.stl[1] = ret.stl[2] = 0;
    ret.enr[0] = ret.enr[1] = ret.enr[2] = 0;
    ret.o[0] = ret.o[1] = ret.o[2] = 0;
    for(int i = 0 ; i < 3; i++)
    {
        ret.stl[i] += left.stl[i];
        ret.stl[(left.whole_sum + i) % 3] += right.stl[i];

        ret.enr[i] += right.enr[i];
        ret.enr[(right.whole_sum + i) % 3] += left.enr[i];

        ret.o[i] = left.o[i] + right.o[i];
        for(int j = 0; j < 3; j++)
        {
            ret.o[(i + j) % 3] += left.enr[i] * right.stl[j];
        }
    }
    ret.whole_sum = (left.whole_sum + right.whole_sum) % 3;
    return ret;
}
int main()
{
    int n, m, t, l, r;
    dummy.stl[0] = dummy.stl[1] = dummy.stl[2] = 0;
    dummy.enr[0] = dummy.enr[1] = dummy.enr[2] = 0;
    dummy.o[0] = dummy.o[1] = dummy.o[2] = 0;
    dummy.whole_sum = 0;
    scanf("%d%d", &n, &m);
    scanf("%s", str);
    init(1, 1, n);
    while(m--)
    {
        scanf("%d%d%d", &t, &l, &r);
        if(t == 1)
        {
            change(1, 1, n, l, r);
        }
        else
        {
            struct node ans = query(1, 1, n, l, r);
            printf("%lld\n", ans.o[0]);
        }
    }
    return 0;
}
