/*
    Problem : Chef and Stones
    Link : http://www.codechef.com/JAN15/problems/ONEKING
    User : ashish1294
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}
int main()
{
    int t, n, l, r, co;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        v.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &l, &r);
            v.push_back(make_pair(l, r));
            //a[i] = 0;
        }
        sort(v.begin(), v.end(), comp);
        co = 0, l = -100000;
        for(int i = 0 ; i < n; i++)
        {
            if(l < v[i].first)
            {
                l = v[i].second;
                co++;
            }
        }
        printf("%d\n", co);
    }
    return 0;
}
