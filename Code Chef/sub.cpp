/*
 * blur.cpp
 * Created on: 2013-10-23 21:01
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define For(i, a, b) for(int i = (a), _b = (b); i < _b; i++)
#define Rep(i, n) For(i, 0, n)

int compare(vector <string> &box, int x1, int y1, int x2, int y2,int maxx, int maxy) {
    //cout <<"c!";
    for(int i = 0; i < maxx; i++) {
        for(int j = 0; j < maxy; j++) {
            if(box[x1+i][y1+j] != box[x2+i][y2+j])
                return 1;
        }
    }
    return 0;
}
int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector <string> box(n);
        Rep(i, n)
            cin >> box[i];
        //cout <<"II\n";
        int size = 0;
        for(int maxx = n; maxx >=1; maxx--) {
            //cout <<"1";
            for(int maxy = m; maxy >=1; maxy--) {
                //cout <<"2";
                for(int x1 = 0; x1 <= n - maxx; x1++) {
                    //cout <<"3";
                    for(int y1 = 0; y1 <= m - maxy; y1++) {
                        //cout <<"4";
                        for(int x2 = x1; x2 <= n - maxx; x2++) {
                            //cout <<"5";
                            for(int y2 = y1; y2 <= m - maxy; y2++) {
                                //cout <<"6";
                                if(x1 != x2 || y1 != y2)
                                    if(compare(box, x1, y1, x2, y2, maxx, maxy) == 0) {
                                       //cout << maxx << ' ' <<maxy << '\n';
                                        size = max(size, maxx*maxy);
                                    }
                            }
                        }
                    }
                }
            }
        }

        cout << size << '\n';
    }
    return 0;
}
