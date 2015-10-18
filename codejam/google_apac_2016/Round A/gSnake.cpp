/*
    Author: Ashish Kedia (ashish1294)
    National Institute of Technology Karnataka, Surathkal
*/
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <map>
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
using namespace std;
int b[110][110];
int tim[110], dir[110], r, c;
pair<int, int> next_pos(int x, int y, int curr_dir)
{
	pair<int, int> ret;
	if(curr_dir == RIGHT)
	{
		if(y == c)
		{
			ret = make_pair(x, 1);
		}
		else
		{
			ret = make_pair(x, y + 1);
		}
	}
	else if(curr_dir == LEFT)
	{
		if(y == 1)
		{
			ret = make_pair(x, c);
		}
		else
		{
			ret = make_pair(x, y - 1);
		}
	}
	else if(curr_dir == UP)
	{
		if(x == 1)
		{
			ret = make_pair(r, y);
		}
		else
		{
			ret = make_pair(x - 1, y);
		}
	}
	else if(curr_dir == DOWN)
	{
		if(x == r)
		{
			ret = make_pair(1, y);
		}
		else
		{
			ret = make_pair(x + 1, y);
		}
	}
	return ret;
}
int main()
{
    int t, tc, n, m, i, j, k, s;
    scanf("%d", &tc);
    for(t = 1; t <= tc; t++)
    {
    	scanf("%d%d%d", &s, &r, &c);
    	for(i = 1; i <= r; i++)
    	{
    		for(j = 1; j <= c; j++)
    		{
    			if(((i + j) & 1) == 1) b[i][j] = 1;
    			else b[i][j] = 0;
    		}
    	}
    	for(i = 0; i < s; i++)
    	{
    		scanf("%d", &tim[i]);
    		char ch;
    		cin>>ch;
    		//printf("ch = %c\n", ch);
    		if(ch == 'L') dir[i] = 0;
    		else dir[i] = 1;
    	}
    	//printf("Done\n");
    	vector<int> csr, csc;
    	csr.push_back(1);
    	csc.push_back(1);
    	int curr_time = 1, curr_dir = RIGHT, game = 1, curr_len = 1, curr_ind = 0, ans = -1, tt = 0;
    	while(game)
    	{
    		if(curr_time == tim[curr_ind])
    		{
    			if(dir[curr_ind] == 0)
    			{
    				if(curr_dir == LEFT) curr_dir = DOWN;
    				else if(curr_dir == RIGHT) curr_dir = UP;
    				else if(curr_dir == UP) curr_dir = LEFT;
    				else if(curr_dir == DOWN) curr_dir = RIGHT;
    			}
    			else
    			{
    				if(curr_dir == LEFT) curr_dir = UP;
    				else if(curr_dir == RIGHT) curr_dir = DOWN;
    				else if(curr_dir == UP) curr_dir = RIGHT;
    				else if(curr_dir == DOWN) curr_dir = LEFT;
    			}
    			curr_ind++;
    		}
    		pair<int, int> next = next_pos(csr[csr.size() - 1], csc[csc.size() - 1], curr_dir);
    		//printf("next = %d %d\n", next.first, next.second);
    		if(b[next.first][next.second] == 1)
    		{
    			b[next.first][next.second] = 0;
    			csr.push_back(next.first);
    			csc.push_back(next.second);
    		}
    		else
    		{
    			for(j = 0; j < csr.size() - 1; j++)
    			{
    				csr[j] = csr[j + 1];
    				csc[j] = csc[j + 1];
    			}
    			csr[csr.size() - 1] = next.first;
    			csc[csc.size() - 1] = next.second;
    		}
    		for(i = 0; i < csr.size(); i++)
    		{
    			for(j = i + 1; j < csr.size(); j++)
    			{
    				if(csr[i] == csr[j] && csc[i] == csc[j])
    				{
    					game = 0;
    				}
    			}
    		}
    		curr_time++;
    	}
    	ans = csr.size();
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
