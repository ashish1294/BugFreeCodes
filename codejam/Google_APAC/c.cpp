#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string>
#include<map>
#include<iostream>
using namespace std;

int main()
{
	int t, n;
	string a, b;
	scanf("%d",&t);
	for(int tt= 1; tt <= t; tt++)
	{
        map<string, int> h, ch;
        map<string, string> x;
        scanf("%d",&n);
        for(int i = 0 ; i < n; i++)
        {
            cin>>a>>b;
            if(h[a] > 1 || h[a] < -1 || h[b] > 1 || h[b] < -1) printf("Error\n\n");
            h[a] += 1;
            h[b] -= 1;
            x[a] = b;
        }
        string st, en;
        for(map<string, int>::iterator i = h.begin(); i != h.end(); i++)
        {
            //cout<<"Dec "<<i->first<<" "<<i->second<<endl;
            if(i->second == 1)
            {
                //cout<<"first"<<endl;
                st = i->first;
            }
            if(i->second == -1)
            {
                //cout<<"last"<<endl;
                en = i->first;
            }
        }
        printf("Case #%d:",tt);
        int co  = 0;
        for(string j = st; j != en;)
        {
            cout<<" "<<j<<"-"<<x[j];
            j = x[j];
            co++;
        }
        if(co != n) printf("Error\n\n");
        cout<<endl;
	}
	return 0;
}
