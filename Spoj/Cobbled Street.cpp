//http://www.spoj.com/problems/CSTREET/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include<stdio.h>
#include<algorithm>
using namespace std;
int V,E;
struct Edge{
    int src, dest, weight;
}*edge;
inline bool operator<(const Edge& a, const Edge& b) {return a.weight<b.weight;}
//Union Algorithm
struct subset{ int parent,rank;};

inline int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

inline void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int KruskalMST()
{
    int e=0,i=0,sum=0,v;
    sort(edge,edge+E);
    struct subset *subsets = (struct subset*) malloc(V*sizeof(struct subset));
    for (v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1)
    {
        struct Edge next_edge = edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y)
        {
			sum+=next_edge.weight;
			e++;
            Union(subsets, x, y);
        }
    }
    return sum;
}

//Fast Input
inline int inp()
{
    register int noRead=0;
    register char p=getchar_unlocked();
    //register char p=getc(stdin);
    for(;p<48 || p>57;p=getchar_unlocked());
    //for(;p<48 || p>57;p=getc(stdin));
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};

int main()
{
	int t=inp(),p,i,ans;
	while(t--)
	{
		p=inp();V=inp();E=inp();
		edge=(struct Edge*)malloc(E*sizeof(struct Edge));
		for(i=0;i<E;i++)
		{
			edge[i].src=inp()-1;
			edge[i].dest=inp()-1;
			edge[i].weight=inp();
		}
		ans = KruskalMST();
		printf("%d",ans*p);
	}
	return 0;
}
