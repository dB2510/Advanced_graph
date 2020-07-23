#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>graph;

bool dfs(int s,int parent, bool visited[])
{
    visited[s]=true;
    for(auto i:graph[s])
    {
        if(!visited[i])
        {
            if(dfs(i,s,visited))
            return true;
        }

        else if(i != parent)
        {
            return true;
        }

    }
    return false;
}

int main()
{
    int vertices,edges;
    cin >> vertices >> edges;

    graph = vector<vector<int>>(vertices+1);
    bool visited[vertices+1];
    for (int i = 0; i <= vertices; i++)
        visited[i]=false;
    

    for(int i = 0;i < edges; i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(dfs(1,-1,visited))
    cout << "Cycle is present" << endl;
    else 
    cout << "Cycle is not present" << endl;

    return 0;
}