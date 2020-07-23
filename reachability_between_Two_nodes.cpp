#include<bits/stdc++.h>
using namespace std;

// We are given a directed graph

vector<vector<int>>graph;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    graph = vector<vector<int>>(vertices+1);

    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    bool visited[vertices+1];
    for(int i = 0;i <= vertices; i++)
        visited[i] = false;

    bool isReachable = false;
    queue<int>q;
    int s,d;
    cin >> s >> d;
    q.push(s);
    visited[s]=true;

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto i:graph[v])
        {
            if(!visited[i])
            {
                if(i==d)
                isReachable = true;
                visited[i]=true;
                q.push(i);
            }

        }
    }

    if(isReachable)
    cout << "Path exists" << endl;
    else
    cout << "Path doesn't exists" << endl;

    return 0;
}