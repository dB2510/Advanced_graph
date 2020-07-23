#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>graph;
vector<bool>visited,recstack;

bool dfs(int s)
{
    recstack[s]=true;
    visited[s]=true;
    for(auto i:graph[s])
    {
        if(!visited[i] && dfs(i))
        return true;

        if(recstack[i])
        return true;
    }
    recstack[s]=false;
    return false;
}

int main()
{
    int vertices,edges;
    cin >> vertices >> edges;

    graph = vector<vector<int>>(vertices+1);
    visited = vector<bool>(vertices+1,false);
    recstack = vector<bool>(vertices+1,false);

    for(int i = 0;i < edges; i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    if(dfs(1))
    cout << "Cycle is present" << endl;
    else 
    cout << "Cycle is not present" << endl;

    return 0;
}