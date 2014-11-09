//http://www.codechef.com/AUG14/problems/CLETAB
//Ashish Kedia, NITK SUrathkal
//@ashish1294
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<climits>
using namespace std;
static int frame[205][2], order[410], next[405];
vector<int> nn[410];
int main()
{
	int t,n,m,ispre,clean,flag,minin,minval, i;
	scanf("%d",&t);
	while(t--)
	{
        scanf("%d%d",&n,&m);
        ispre = clean = flag = 0;
        for(i=0;i<401;i++) nn[i].clear(), next[i] = -1, order[i] = 0;
        for(i=0;i<201;i++) frame[i][0] = 0, frame[i][1] = -1;
        for(i=0;i<m;i++)
        {
            scanf("%d",&order[i]);
            nn[order[i]].push_back(i);
        }
        //printf("Input done\n");fflush(stdout);
        for(i=1;i<401;i++)
        {
            int sz = nn[i].size() - 1;
            //printf("%d size = %d\n",i,sz);fflush(stdout);
            for(int j=0;j<sz;j++)
            {
                //printf("i = %d j = %d %d\n",i,j,nn[i][j]);fflush(stdout);
                next[nn[i][j]] = nn[i][j+1];
            }
            //printf("Loop ran for %d\n",i);fflush(stdout);
            if(nn[i].size()>0)
            {
                //printf("if sat\n");fflush(stdout);
                next[nn[i][nn[i].size()-1]] = INT_MAX;
            }
        }
        //printf("Pre-Processing Done\n");fflush(stdout);
        //for(i=0;i<m;i++) printf("%d ",next[i]);
        for(i=0;i<m;i++)
        {
            ispre = flag = 0; minval = -1;
            //printf("Processing i = %d order = %d\n",i, order[i]);
            for(int j=0;j<n;j++)
            {
                if(frame[j][0] == order[i])
                {
                    ispre = 1;
                    frame[j][1] = next[i];
                    break;
                }
            }
            if(!ispre)
            {
                //printf("Not Present\n");
                for(int j=0;j<n;j++)
                {
                    if(frame[j][0] == 0)
                    {
                        frame[j][0] = order[i];
                        frame[j][1] = next[i];
                        flag = 1;
                        clean++;
                        //printf("Found Empty clean = %d\n",clean);
                        break;
                    }
                    else if(frame[j][1]>minval)
                    {
                        minval = frame[j][1];
                        minin = j;
                    }
                }
                if(!flag)
                {
                    //printf("Out %d minval = %d\n",frame[minin][0],minval);
                    frame[minin][0] = order[i];
                    frame[minin][1] = next[i];
                    clean++;
                    //printf("No Empty clean = %d\n",clean);
                }
            }
        }

        printf("%d\n",clean);
	}
	return 0;
}
