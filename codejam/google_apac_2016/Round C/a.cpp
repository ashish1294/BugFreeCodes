/*
    Author - Ashish Kedia (@ashish1294)
    National Institute of Technology Karnataka, Surathkal, India
    <a>https://www.ashishkedia.me</a>
    ashish1294@gmail.com
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b)
{
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}
int pp[110];
int main()
{
    int t, n, p, m;
    long long int w;
    scanf("%d", &t);
    for(int tt =  1; tt <= t; tt++)
    {
        map<string, vector<long long int> > mp;
        vector<pair<int, string> > ran;
        scanf("%d", &p);
        for(int i = 1; i <= p; i++) scanf("%d", &pp[i]);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &w);
            for(int j = 1; j <= p; j++)
            {
                string s;
                cin>>s;
                //cout<<s<<" scored"<<(w * pp[j])<<endl;
                mp[s].push_back(w * pp[j]);
            }
        }
        scanf("%d", &m);
        for(map<string, vector<long long int> >::iterator it = mp.begin(); it != mp.end(); it++)
        {
            sort(it->second.begin(), it->second.begin());
            reverse(it->second.begin(), it->second.end());
            long long int total = 0;
            for(int i = 0 ; i < m && i < it->second.size(); i++)
            {
                total+= it->second[i];
            }
            ran.push_back(make_pair(total, it->first));
        }
        printf("Case #%d:\n", tt);
        sort(ran.begin(), ran.end(), cmp);
        for(int i = 0; i < ran.size();)
        {
            int j = i;
            for(; i < ran.size() && ran[i].first == ran[j].first;i++)
            {
                cout<<j+1<<". "<<ran[i].second<<endl;
            }
        }
    }
    return 0;
}
