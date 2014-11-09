//http://www.codechef.com/AUG14/problems/CRAWA
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
	int t,x,y,f;
	scanf("%d",&t);
	while(t--)
	{
        scanf("%d%d",&x,&y);
        f=0;
        if(y>=0 && y%2==0 && x>=-y && x<=(y-1)) printf("YES\n");
        else if(y<0 && y%2==0 && x>=y && x<=(1-y)) printf("YES\n");
        else if(x>0 && x%2==1 && y>=(1-x) && y<=(x+1)) printf("YES\n");
        else if(x<=0 && x%2==0 && y>=x && y<=(-x)) printf("YES\n");
        else printf("NO\n");
	}
	return 0;
}
