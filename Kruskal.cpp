#include<bits/stdc++.h>
using namespace std;

struct edge {
    int u,v,w;
};

vector<edge>edgeList;
vector<int>id;
int vertices, edges;

void initialise()
{
    for(int i = 0;i <= vertices; i++)
    id[i] = i;
}

bool mycomp(edge e1, edge e2)
{
    return e1.w < e2.w;
}

int root(int u)
{
    if(id[u]!=u)
    return root(id[u]);
    return u;
}

void union1(int u,int v)
{
    u = root(u);
    v = root(v);
    id[v] = u;
}

long long int kruskal()
{
    long long int minimumCost = 0;
    for(int i = 0 ;i < edges; i++)
    {
        int x = edgeList[i].u;
        int y = edgeList[i].v;

        int cost = edgeList[i].w;
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x,y);
        }
    }
    return minimumCost;
}

int main()
{
    cin >> vertices >> edges;

    for(int i = 0; i < edges; i++)
    {
        edge e;
        cin >> e.u >> e.v >> e.w;
        edgeList.push_back(e);
    }

    id = vector<int>(vertices+1);
    initialise();

    sort(edgeList.begin(), edgeList.end(), mycomp);
    long long int minimumCost = kruskal();
    
    cout << minimumCost << endl;
    return 0;
}