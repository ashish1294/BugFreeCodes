#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
int st[1000], en[1000];
int main()
{
	int t,n,p,q;
	scanf("%d",&t);
	for(int tt = 1; tt <=t; tt++)
	{
        scanf("%d",&n);
        for(int i= 0; i < n; i++)
        {
            scanf("%d%d",&st[i], &en[i]);
        }
        scanf("%d",&p);
        printf("Case #%d:",tt);
        while(p--)
        {
            scanf("%d",&q);
            int co = 0;
            for(int i = 0; i < n; i++)
            {
                if(q>=st[i] && q<=en[i]) co++;
            }
            printf(" %d",co);
        }
        printf("\n");
	}
	return 0;
}
