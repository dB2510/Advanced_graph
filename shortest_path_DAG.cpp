#include<bits/stdc++.h>
using namespace std;

// We are given Directed Acyclic Graph so the idea 
// is to use the given information and apply Topological
// sort as it only for the Directed Acyclic Graph

vector<vector<pair<int,int>>>graph;

void dfs(int s, bool *visited, stack<int>&st)
{
    visited[s]=true;
    for(auto i:graph[s])
    {
        if(!visited[i.first])
        {
            dfs(i.first,visited,st);
        }
    }
    st.push(s);
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    graph = vector<vector<pair<int,int>>>(vertices);

    bool visited[vertices];
    for(int i = 0; i<vertices; i++)
        visited[i] = false;

    for(int i = 0; i<edges ; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
    }

    stack<int>st;
    for(int i = 0; i<vertices; i++)
    {
        if(!visited[i])
        dfs(i,visited,st);
    }

    int src;
    cin >> src;

    int dist[vertices];
    for(int i = 0; i<vertices ; i++)
    dist[i] = INT_MAX;

    dist[src] = 0;

    while(!st.empty())
    {
        int u = st.top();
        st.pop();

        if(dist[u] != INT_MAX)
        {
            for(auto i:graph[u])
            {
                int v = i.first, w = i.second;
                if(dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int i = 0; i<vertices ;i++)
    (dist[i] == INT_MAX) ? cout << "INF " : cout << dist[i] << " ";

    cout << endl;
    return 0;
}

// Testcase
// 6 9
// 0 1 5 
// 0 2 3 
// 1 3 6 
// 1 2 2 
// 2 4 4 
// 2 5 2 
// 2 3 7 
// 3 4 -1 
// 4 5 -2 
// 1
