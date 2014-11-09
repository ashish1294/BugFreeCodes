#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
char str[10], type[100];
int x[100], y[100], ch[10][10];
int main()
{
	int t, ki, kj, n;
	scanf("%d",&t);
	for(int tt= 1; tt <= t; tt++)
	{
        scanf("%d",&n);
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                ch[i][j] = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%s",str);
            x[i] = str[0] - 'A';
            y[i] = str[1] - '1';
            ch[x[i]][y[i]] = 1;
            type[i] = str[3];
        }
        int co = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(i==j) continue;
                if(type[i] == 'K')
                {
                    ki = x[i] - 1;
                    kj = y[i] - 1;
                    if(ki == x[j] && kj==y[j]) co ++;
                    ki = x[i] - 1;
                    kj = y[i];
                    if(ki == x[j] && kj==y[j]) co ++;
                    ki = x[i] - 1;
                    kj = y[i] + 1;
                    if(ki == x[j] && kj==y[j]) co ++;
                    ki = x[i];
                    kj = y[i] - 1;
                    if(ki == x[j] && kj==y[j]) co ++;
                    ki = x[i];
                    kj = y[i] + 1;
                    if(ki == x[j] && kj==y[j]) co ++;
                    ki = x[i] + 1;
                    kj = y[i] - 1;
                    if(ki == x[j] && kj==y[j]) co ++;
                    ki = x[i] + 1;
                    kj = y[i];
                    if(ki == x[j] && kj==y[j]) co ++;
                    ki = x[i] + 1;
                    kj = y[i] + 1;
                    if(ki == x[j] && kj==y[j]) co ++;
                }
                if(type[i] == 'P')
                {
                    ki = x[i]+1;
                    kj = y[i]-1;
                    if(ki == x[j] && kj==y[j]) co ++;
                    ki = x[i]+1;
                    kj = y[i]+1;
                    if(ki == x[j] && kj==y[j]) co ++;
                }
                else if(type[i] == 'R')
                {
                    for(kj = y[i] - 1, ki = x[i]; kj>=0; kj--)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(kj = y[i] + 1, ki = x[i]; kj<8; kj++)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(ki = x[i] - 1, kj = y[i]; ki>=0; ki--)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(ki = x[i] + 1, kj = y[i]; ki < 8; ki++)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                }
                else if(type[i] == 'B')
                {
                    for(ki = x[i] + 1, kj = y[i] + 1; ki < 8 && kj < 8; ki++, kj++)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(ki = x[i] - 1, kj = y[i] - 1; ki >= 0 && kj >= 0; ki--, kj--)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(ki = x[i] + 1, kj = y[i] - 1; ki < 8 && kj >=0 ; ki++, kj--)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(ki = x[i] - 1, kj = y[i] + 1; ki >= 0 && kj < 8; ki--, kj++)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                }
                if(type[i] == 'Q')
                {
                    for(ki = x[i] + 1, kj = y[i] + 1; ki < 8 && kj < 8; ki++, kj++)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(ki = x[i] - 1, kj = y[i] - 1; ki >= 0 && kj >= 0; ki--, kj--)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(ki = x[i] + 1, kj = y[i] - 1; ki < 8 && kj >=0 ; ki++, kj--)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(ki = x[i] - 1, kj = y[i] + 1; ki >= 0 && kj < 8; ki--, kj++)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(kj = y[i] - 1, ki = x[i]; kj>=0; kj--)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(kj = y[i] + 1, ki = x[i]; kj<8; kj++)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(ki = x[i] - 1, kj = y[i]; ki>=0; ki--)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                    for(ki = x[i] + 1, kj = y[i]; ki < 8; ki++)
                    {
                        if(ki == x[j] && kj==y[j])
                        {
                            co ++;
                            break;
                        }
                    }
                }
                else if(type[i] == 'N')
                {
                    ki = x[i] - 1;
                    kj = y[i] - 2;
                    if(ki == x[j] && kj==y[j]) co++;
                    ki = x[i] + 1;
                    kj = y[i] - 2;
                    if(ki == x[j] && kj==y[j]) co++;
                    ki = x[i] - 2;
                    kj = y[i] - 1;
                    if(ki == x[j] && kj==y[j]) co++;
                    ki = x[i] - 2;
                    kj = y[i] + 1;
                    if(ki == x[j] && kj==y[j]) co++;
                    ki = x[i] - 1;
                    kj = y[i] + 2;
                    if(ki == x[j] && kj==y[j]) co++;
                    ki = x[i] + 1;
                    kj = y[i] + 2;
                    if(ki == x[j] && kj==y[j]) co++;
                    ki = x[i] + 2;
                    kj = y[i] - 1;
                    if(ki == x[j] && kj==y[j]) co++;
                    ki = x[i] + 2;
                    kj = y[i] + 1;
                    if(ki == x[j] && kj==y[j]) co++;
                }
            }
        }
        printf("Case #%d: %d\n",tt, co);
	}
	return 0;
}
