//http://www.codechef.com/AUG14/problems/PRGIFT
//Ashish Kedia, NITK Surathkal
//@ashish1294
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int main()
{
	int t,n,k,temp,co,nc;
	scanf("%d",&t);
	while(t--)
	{
        scanf("%d%d",&n,&k);
        nc=n;
        co=0;
        while(nc--)
        {
            scanf("%d",&temp);
            if(temp%2==0) co++;
        }
        if(n==0) printf("NO\n");
        else if(k==0)
        {
            if(co<n) printf("YES\n");
            else printf("NO\n");
        }
        else
        {   if(co>=k) printf("YES\n");
            else printf("NO\n");
        }
	}
	return 0;
}
