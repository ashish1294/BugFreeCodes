//http://www.spoj.com/problems/IITKWPCG/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
#include <stdio.h>
#include <stdlib.h>
//Fast Log2 Implementation
#define LOG2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))
int V,E;
struct Edge{
    int src, dest, weight;
}*edge;
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
//Union Algorithm
struct subset{ int parent,rank;};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
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
    qsort(edge, E, sizeof(struct Edge), myComp);
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
	int t=inp(),i,ans,a,b;
	unsigned long long c;
	while(t--)
	{
		V=inp();E=inp();
		edge=(struct Edge*)malloc(E*sizeof(struct Edge));
		for(i=0;i<E;i++)
		{
			a=inp();b=inp();
			scanf("%llu",&c);
			edge[i].src=a-1;
			edge[i].dest=b-1;
			edge[i].weight=LOG2(c);
		}
		ans=KruskalMST();
		printf("%d\n",ans+1);
	}
	return 0;
}
