#include <stdio.h>
#include <stdlib.h>
#include<algorithm>
//Fast Log2 Implementation
#define LOG2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))
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

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int KruskalMST()
{
    int e=0,i=0,sum=0,v;
    std::sort(edge,edge+E);
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

//Fast Input-Output
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
inline int linp()
{
    register unsigned long long noRead=0;
    register char p=getchar_unlocked();
    //register char p=getc(stdin);
    for(;p<48 || p>57;p=getchar_unlocked());
    //for(;p<48 || p>57;p=getc(stdin));
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return (LOG2(noRead));
};
inline void out(int t)
{
	register char st[11];
	register int a=0;
	while(t>0)
	{
		st[a++]=(t%10)+'0';
		t/=10;
	}
	while(a>0) putchar_unlocked(st[--a]);
	putchar_unlocked('\n');
}
int main()
{
	int t=inp(),i,ans,a,b;
	unsigned long long c;
	while(t--)
	{
		V=inp();E=inp();
		edge=(struct Edge*)malloc(E*sizeof(struct Edge));
		for(i=0;i<E;i++)
		{
			a=inp();b=inp();
			edge[i].src=a-1;
			edge[i].dest=b-1;
			edge[i].weight=linp();
		}
		ans=KruskalMST();
		out(ans+1);
	}
	return 0;
}
