#include<bits/stdc++.h>
using namespace std;

#define pii pair<long long int,int>

vector<vector<pair<int,int>>>graph;
int vertices, edges;

long long int prim(int src)
{
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push(make_pair(0,src));
    long long int minimumCost = 0;
    bool visited[vertices+1];
    for(int i = 0;i <= vertices; i++)
    visited[i] = false;
    
    while(!pq.empty())
    {
        pii node = pq.top();
        pq.pop();
        int x = node.second;

        if(visited[x])
        continue;

        minimumCost += node.first;
        visited[x] = true;
        for(auto i:graph[x])
        {
            if(!visited[i.second])
            pq.push(i);
        }
    }
    return minimumCost;
}

int main()
{
    cin >> vertices >> edges;
    graph = vector<vector<pair<int,int>>>(vertices + 1);
    for(int i = 0; i < edges; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w,v));
        graph[v].push_back(make_pair(w,u));
    }

    long long int minimumCost = prim(1);
    
    cout << minimumCost << endl;
    return 0;
}