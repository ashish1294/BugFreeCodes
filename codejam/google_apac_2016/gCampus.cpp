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
#include <climits>

struct tt{
	int ind;
	int u;
	int v;
	int imp;
};
struct tt arr[10010];
bool cmp(struct tt a, struct tt b)
{
	if(a.u != b.u) return a.u < b.u;
	if(a.v != b.v) return a.v < b.v;
	return a.ind < b.ind;
}
class MinHeap
{
	private:
	struct node{
		int v,dist;
	}*minnode;
	int si,maxcap,*pos;
	node** tree;
	void minHeapify(int idx)
	{
		int small=idx,left=(idx<<1)+1,right;
		right=left+1;
		if (left<si && tree[left]->dist < tree[small]->dist) small=left;
		if (right<si && tree[right]->dist < tree[small]->dist) small=right;
		if (small != idx)
		{
			// Swap positions
			pos[tree[small]->v] = idx;
			pos[tree[idx]->v] = small;
			// Swap nodes
			node* temp = tree[small];
			tree[small]=tree[idx];
			tree[idx]=temp;
			minHeapify(small);
		}
	}

	public:
	void init(int capacity)
	{
		maxcap=capacity;
		pos=(int *)malloc(maxcap*sizeof(node));
		si=maxcap;
		tree=(node**)malloc(maxcap*sizeof(node*));
		for (int v = 0; v < maxcap; ++v)
		{
			tree[v] = (struct node*)malloc(sizeof(struct node));
			tree[v]->v=v;
			tree[v]->dist=INT_MAX;
			pos[v] = v;
		}
	}

	void extractMin()
	{
		minnode = tree[0];
		tree[0] = tree[si-1];
		pos[minnode->v] =si-1;
		pos[tree[0]->v] = 0;
		si--;
		minHeapify(0);
	}

	int getminv()
	{
		return minnode->v;
	}

	int getmindist()
	{
		return minnode->dist;
	}

	bool ispresent(int v)
	{
		if (pos[v]<si) return true;
		return false;
	}

	void decreaseKey(int v, int dist)
	{
		int i = pos[v];
		tree[i]->dist = dist;
		while (i && tree[i]->dist < tree[(i-1)/2]->dist)
		{
			// Swap this node with its parent
			pos[tree[i]->v]=(i-1)/2;
			pos[tree[(i-1)/2]->v] = i;
			node* temp = tree[i];
			tree[i]=tree[(i-1)/2];
			tree[(i-1)/2]=temp;
			i = (i-1)/2;
		}
	}

	void print()
	{
		for(int i=0;i<si;i++)
		{
			printf("i=%d v=%d dist=%d\n",i,tree[i]->v,tree[i]->dist);
		}
		printf("\n");
	}

	inline int getsize()
	{
		return si;
	}
};
class Graph{

	public:
	int V,E;
	MinHeap mH;
	struct listnode{
		int dest;
		int cost;
		int ind;
		struct listnode* next;
	}**graph;

	void init(int Ver,int Edg)
	{
		V=Ver;E=Edg;
		graph = (listnode**)malloc(V*sizeof(struct listnode*));
		for(int i=0;i<V;i++) graph[i]=NULL;
	}

	void AddEdge(int src,int dest,int cost, int in)
	{
		struct listnode* nn1 = (struct listnode *)malloc(sizeof(struct listnode));
		nn1->dest=dest;
		nn1->cost=cost;
		nn1->ind = in;
		nn1->next=graph[src];
		graph[src]=nn1;

		struct listnode* nn2 = (struct listnode *)malloc(sizeof(struct listnode));
		nn2->dest=src;
		nn2->cost=cost;
		nn2->ind = in;
		nn2->next=graph[dest];
		graph[dest]=nn2;
	}

	void printgr()
	{
		for(int i=0;i<V;i++)
		{
			struct listnode* tt = graph[i];
			printf("%d->",i);
			while(tt!=NULL)
			{
				printf("%d->",tt->dest);
				tt=tt->next;
			}
			printf("NUll\n");
		}
	}

	void dijkstra(int src)
	{
		long long int *dist;
		int *par = (int *) malloc(V * sizeof(int));
		dist = (long long int *) malloc(V * sizeof(long long int));
		mH.init(V);
		for(int i=0;i<V;i++) dist[i]=LLONG_MAX, par[i] = -1;
		dist[src] = 0;
		mH.decreaseKey(src, dist[src]);
		while (mH.getsize()>0)
		{
			mH.extractMin();
			int u = mH.getminv();
			dist[u]=mH.getmindist();
			if(u != src)
			{
				//printf("u = %d edge = %d cost = %lld\n", u, par[u], dist[u]);
				arr[par[u]].imp = 1;
			}
			listnode* tt = graph[u];
			while (tt != NULL)
			{
				int v = tt->dest;
				if (mH.ispresent(v) && dist[u]!=LLONG_MAX && tt->cost + dist[u] < dist[v])
				{
					//printf("Updating par => o = %lld n = %lld ind = %d\n", dist[v], dist[u] + tt->cost, tt->ind);
					par[v] = tt->ind;
					dist[v] = dist[u] + tt->cost;
					mH.decreaseKey(v, dist[v]);
				}
				tt = tt->next;
			}
		}
		free(dist);
		free(par);
	}
};

using namespace std;

int main()
{
    int t, tc, n, m, i, j, k, u, v, c;
    scanf("%d", &tc);
    for(t = 1; t <= tc; t++)
    {
    	scanf("%d%d", &n, &m);
    	Graph gr; gr.init(n,m);
    	for(i = 0; i <m; i++)
    	{
    		scanf("%d%d%d", &u, &v, &c);
    		if(u > v)
    		{
    			int tem = u;
    			u = v;
    			v = tem;
    		}
    		arr[i].u = u;
    		arr[i].v = v;
    		arr[i].ind = i;
    		arr[i].imp = 0;
    		gr.AddEdge(u, v, c, i);
    	}
    	for(i = 0; i < n; i++)
    		gr.dijkstra(i);
        printf("Case #%d: \n", t);
        sort(arr, arr + m, cmp);
        for(i = 0; i < m;i++)
        {
        	//printf("ed %d = %d u = %d v = %d \n", i, arr[i].imp, arr[i].u, arr[i].v);
        	if(arr[i].imp == 1)
        	{
        		while((i + 1 < m) && (arr[i].u == arr[i+1].u) && (arr[i].v == arr[i+1].v))
        		{
        			arr[i+1].imp = 1;
        			i++;
        		}
        	}
        }
        for(i = m-1; i >= 0;i--)
        {
        	//printf("ed %d = %d u = %d v = %d \n", i, arr[i].imp, arr[i].u, arr[i].v);
        	if(arr[i].imp == 1)
        	{
        		while((i -1 >= 0) && (arr[i].u == arr[i-1].u) && (arr[i].v == arr[i-1].v))
        		{
        			arr[i-1].imp = 1;
        			i--;
        		}
        	}
        	else
        	{
        		printf("%d\n", arr[i].ind);
        	}
        }
    }
    return 0;
}
