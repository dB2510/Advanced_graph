#include<bits/stdc++.h>
using namespace std;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<pair<int,int>>graph[vertices];
    for(int i = 0;i < edges; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }

    int dist[vertices];
    for(int i = 0; i<vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    int src;
    cin >> src;
    dist[src] = 0;

    set<pair<int,int>>sptSet;
    sptSet.insert(make_pair(0,src));

    while (!sptSet.empty())
    {
        pair<int,int>u = *(sptSet.begin());
        sptSet.erase(sptSet.begin());

        for(auto v:graph[u.second])
        {
            if(dist[v.first] > dist[u.second] + v.second)
            {
                if(dist[v.first] != INT_MAX)
                sptSet.erase(sptSet.find(make_pair(dist[v.first],v.first)));
                dist[v.first] = dist[u.second] + v.second;
                sptSet.insert(make_pair(dist[v.first],v.first));
            }
        }
    }
    
    for(int i = 0;i < vertices; i++)
    cout << dist[i] << " ";
    cout << endl;

    return 0;
}