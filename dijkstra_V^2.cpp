#include<bits/stdc++.h>
using namespace std;
#define INF 10e9;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<pair<int,int>>graph[vertices+1];
    for(int i = 0;i < edges; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }

    int dist[vertices+1];
    bool sptSet[vertices+1];
    for(int i = 0; i<=vertices; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    int src;
    cin >> src;
    dist[src] = 0;

    for(int i = 1;i < vertices; i++)
    {
        int min_dis = INT_MAX;
        int u;
        for(int j = 0; j < vertices; j++)
        {
            if(!sptSet[j] && min_dis >= dist[j])
            {
                min_dis = dist[j];
                u = j;
            }
        }
        sptSet[u] = true;

        for(auto v:graph[u])
        {
            if(!sptSet[v.first] && dist[u]!=INT_MAX && (dist[u] + v.second < dist[v.first]))
                dist[v.first] = dist[u] + v.second;
        }
    }

    for(int i = 0; i<vertices; i++)
    cout << dist[i] << " ";
    cout << endl;
    return 0;
}

// Testcase
// 9 14
// 0 1 4
// 0 7 8
// 1 7 11
// 1 2 8
// 7 8 7
// 7 6 1
// 2 8 2
// 8 6 6
// 2 3 7
// 2 5 4
// 6 5 2
// 3 5 14
// 3 4 9
// 4 5 10
// 0
