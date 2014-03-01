//http://www.spoj.com/problems/HIGHWAYS/
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
class MinHeap
{
	private:
	struct node{
		int v;
		float dist;
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

	void decreaseKey(int v, float dist)
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
		struct listnode* next;
	}**graph;

	void init(int Ver,int Edg)
	{
		V=Ver;E=Edg;
		graph = (listnode**)malloc(V*sizeof(struct listnode*));
		for(int i=0;i<V;i++) graph[i]=NULL;
	}

	void AddEdge(int src,int dest,int cost)
	{
		struct listnode* nn1 = (struct listnode *)malloc(sizeof(struct listnode));
		nn1->dest=dest;
		nn1->cost=cost;
		nn1->next=graph[src];
		graph[src]=nn1;

		struct listnode* nn2 = (struct listnode *)malloc(sizeof(struct listnode));
		nn2->dest=src;
		nn2->cost=cost;
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

	float dijkstra(int src,int ddest)
	{
		float dist[V];
		mH.init(V);
		for(int i=0;i<V;i++) dist[i]=INT_MAX;
		dist[src] = 0;
		mH.decreaseKey(src, dist[src]);
		while (mH.getsize()>0)
		{
			mH.extractMin();
			int u = mH.getminv();
			dist[u]=mH.getmindist();
			if(u==ddest) return dist[u];
			listnode* tt = graph[u];
			while (tt != NULL)
			{
				int v = tt->dest;
				if (mH.ispresent(v) && dist[u]!=INT_MAX && (tt->cost*dist[u])>(dist[v]*100.0))
				{
					dist[v] = (dist[u]*tt->cost)/100.0;;
					mH.decreaseKey(v, dist[v]);
				}
				tt = tt->next;
			}
		}
		return dist[ddest];
	}
};
inline int linp()
{
    register int noRead=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked());
    for(;p<48 || p>57;p=getc(stdin));
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};
main()
{
	int n,m,a,b,x,T;
	float ans;
	while(1)
	{
		//scanf("%lld%lld%lld%lld",&n,&m,&st,&en);
		n=linp();
		if(n==0) break;
		m=linp();
		Graph gr; gr.init(n,m);
		int curr=1;
		for(int i=0;i<m;i++)
		{
			//scanf("%lld%lld%lld",&a,&b,&x);
			a=linp();b=linp();x=linp();
			gr.AddEdge(a-1,b-1,100-x);
		}
		ans= gr.dijkstra(0,n-1);
		printf("%d\n",100-ans);
	}
	return 0;
}

