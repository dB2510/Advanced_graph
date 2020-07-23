#include<bits/stdc++.h>
using namespace std;

// Algorithm paradigm: Dynamic Programming

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<int>edgelist[edges];

    for(int i = 0;i < edges; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edgelist[i].push_back(u);
        edgelist[i].push_back(v);
        edgelist[i].push_back(w);
    }

    int dist[vertices];
    for(int i = 0;i < vertices;i++)
    dist[i] = INT_MAX;

    int src;
    cin >> src;
    dist[src] = 0;

    for(int edges_done = 1; edges_done < vertices - 1; edges_done++ )
    {
        for(int i = 0; i<edges; i++)
        {
            int x = edgelist[i][0],y = edgelist[i][1], weight = edgelist[i][2];
            if(dist[x] != INT_MAX && dist[x] + weight < dist[y])
                dist[y] = dist[x] + weight;
        }
    }

    bool cyclic = false;
    for(int i = 0; i<edges; i++)
    {
        int x = edgelist[i][0],y = edgelist[i][1], weight = edgelist[i][2];
        if(dist[x] != INT_MAX && dist[x] + weight < dist[y])
        {
            cyclic = true;
        }
    }
    if(cyclic)
    cout << "Negtive cycle present" << endl;
    else
    {
        for(int i = 0; i < vertices; i++)
        cout << dist[i] << " ";
        cout << endl;
    }
    
    return 0;
}

// Testcase:
// 5 8
// 0 1 -1
// 0 2 4 
// 1 2 3
// 1 3 2  
// 1 4 2 
// 3 2 5  
// 3 1 1
// 4 3 -3
// 0