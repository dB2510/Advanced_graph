#include<bits/stdc++.h>
using namespace std;

// Only valid for Directed Acyclic Graph
// Topological Sort is a linear ordering of vertices such that
// for every edges u to v, u comes before v in the ordering

vector<vector<int>>graph;

void dfs(int s, bool *visited, stack<int>&st)
{
    visited[s] = true;
    for(auto i:graph[s])
    {
        if(!visited[i])
        {
            dfs(i, visited, st);
        }
    }
    st.push(s);
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    
    graph = vector<vector<int>>(vertices);
    
    bool visited[vertices];
    for(int i = 0;i < vertices; i++)
    visited[i] = false;

    for(int i = 0;i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    stack<int>st;
    
    for(int i = 0;i < vertices;i++)
    {
        if(!visited[i])
        dfs(i,visited,st);
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

// Testcase
// 6 6
// 5 2
// 5 0
// 4 0
// 4 1
// 2 3
// 3 1