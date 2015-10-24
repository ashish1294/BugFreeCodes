/*
    https://www.quora.com/challenges#related_questions
    Author - Ashish Kedia (@ashish1294)
    National Institute of Technology Karnataka, Surathkal, India
    <a>https://www.ashishkedia.me</a>
    ashish1294@gmail.com
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;
class edge{

  public:
    double cost; //If we take this edge - our expected reading time
    int dest; //The target node for this particular edge
    int in_dest; //Index of this node in destination node's adjacency list
    edge(int d, int di)
    {
        cost = -1;
        dest = d;
        in_dest = di;
    }
};
vector<edge> gr[100010]; //Vector of edges for each node to represent graph
int read_time[100010]; //To store the reading time for each node
double if_root[100010]; //To store the total_expected cost if it is chosen as root
bool is_vis[100010]; // To indicate if the node has been already visited
int computed[100010]; //To store the number of adjacent nodes for which the expected time has been computed already
double now_cost[100010]; //The sum cost of all edges of node. expected cost = now_cost / no.of outgoing edges
/*
    We Basically have to find the root node such that the expected time of
    reaching a leaf node is minimized
*/

double solve1(int src, int ind)
{
    if(gr[src][ind].cost > -1) return gr[src][ind].cost;
    if(src < 10) printf("Solving %d %d\n", src, ind);
    double ret = read_time[src];
    if(computed[src] == gr[src].size())
    {
        ret = now_cost[src] - gr[src][ind].cost;
    }
    else
    {
        for(int i = 0; i < gr[src].size(); i++)
        {
            if(i != ind)
            {
                now_cost[src] += solve1(gr[src][i].dest, gr[src][i].in_dest);
            }
        }
        ret = now_cost[src];
        gr[src][ind].cost = read_time[src] + ret;
    }
    if(gr[src].size() > 1) ret /= (gr[src].size() - 1);
    computed[gr[src][ind].dest]++;
    return gr[src][ind].cost;
}

double solve(int src, double curr_cost, int par_ind)
{
    //printf("solve %d %.1lf %d\n", src, curr_cost, par_ind);
    if(if_root[src] >= 0)
    {
        //printf("already Computed = %lf\n", if_root[src]);
        double ret = read_time[src];
        if(computed[src] > 1)
            ret += (now_cost[src] - gr[src][par_ind].cost) / (computed[src] - 1);
        //printf("Returning = %.1lf\n", ret);
        return ret;
    }
    if(par_ind >= 0)
    {
        gr[src][par_ind].cost = curr_cost;
        computed[src]++;
        now_cost[src] += curr_cost;
    }

    if(computed[src] == gr[src].size())
    {
        //Base Case for recursion. We have reached a node where all costs are computed already
        if_root[src] = read_time[src] + (now_cost[src] / computed[src]);
        //printf("Base Case Reached - %d = %lf\n", src, if_root[src]);
        double ret = read_time[src];
        if(computed[src] > 1)
            ret += (now_cost[src] - gr[src][par_ind].cost) / (computed[src] - 1);
        //printf("Returning = %.1lf\n", ret);
        return ret;
    }
    else if(computed[src] == gr[src].size() - 1)
    {
        for(int i = 0; i < gr[src].size(); i++)
        {
            if(gr[src][i].cost == -1)
            {
                //This will be true for only one value of i
                double total_cost = read_time[src];
                if(computed[src] > 0)
                    total_cost += (now_cost[src] / computed[src]);
                //printf("Calling = %d tt = %.1lf\n", gr[src][i].dest, total_cost);
                double ret, val = solve(gr[src][i].dest, total_cost, gr[src][i].in_dest);
                if(val >= 0)
                {
                    gr[src][i].cost = val;
                    now_cost[src] += gr[src][i].cost;
                    computed[src]++;
                    if_root[src] = read_time[src] + (now_cost[src] / computed[src]);
                    ret = read_time[src];
                    if(computed[src] > 1)
                        ret += (now_cost[src] - gr[src][par_ind].cost) / (computed[src] - 1);
                }
                else ret = -1;
                //printf("Returning = %.1lf\n", ret);
                return ret;
            }
        }
    }
    //printf("Need Nodes ! Can't computer further !\n");
    return -1;
}

int main()
{
    int n, u, v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &read_time[i]);
    }
    for(int i = 0; i < n; i++)
    {
        is_vis[i] = false;
        computed[i] = 0;
        now_cost[i] = 0.0;
        if_root[i] = -1;
    }
    for(int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        u--, v--; //Node Counting starts from 0

        //Undirected Tree. So insert both u-v and v-u
        gr[u].push_back(edge(v, gr[v].size()));
        gr[v].push_back(edge(u, gr[u].size() - 1));
    }
    /*for(int i = 0; i < n; i++)
    {
        if(gr[i].size() == 1)
        {
            //This is a leaf node of the tree. Start bottom up recursion
            solve(i, 0, -1);
        }
    }*/
    //printf("-----------------Second----------------------------\n");
    //Iterating Again because some nodes's if_root may be remaining
    //for(int i = 0; i < n; i++) if(if_root[i] == -1) solve(i, 0, -1);
    for(int i = 0; i < n; i++)
    {
        if_root[i] = 0;
        for(int j = 0 ; j < gr[i].size(); j++)
        {
            if_root[i] += solve1(gr[i][j].dest, gr[i][j].in_dest);
        }
        if_root[i] /= gr[i].size();
        if_root[i] += read_time[i];
    }
    int min_ind = 0;
    for(int i = 0; i < n; i++)
    {
        //printf("ifroot[%d] = %lf, now = %lf\n", i, if_root[i], now_cost[i]);
        if(if_root[min_ind] > if_root[i])
        {
            //printf("Minimum = %lf\n", if_root[i]);
            min_ind = i;
        }
    }
    printf("%d\n", min_ind + 1);
    return 0;
}
