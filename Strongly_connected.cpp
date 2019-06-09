#include<bits/stdc++.h>
using namespace std;

void dfs1(int s,vector<int>*graph,bool *visited,stack<int>&v)
{
    visited[s]=true;
    for(auto i:graph[s])
    {
        if(!visited[i])
        {
            dfs1(i,graph,visited,v);
        }
    }
    v.push(s);
}

void dfs2(vector<int>*graph, int start, unordered_set<int>*component, bool *visited)
{
    visited[start]=true;
    component->insert(start);
    for(int i=0;i<graph[start].size();i++)
    {
        int next=graph[start][i];
        if(!visited[next])
        {
            dfs2(graph,next,component,visited);
        }
    }
}

unordered_set<unordered_set<int>*>* getSCC(vector<int>*graph,vector<int>*graphT,int n)
{
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    stack<int>v;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs1(i,graph,visited,v);
        }
    }
    memset(visited,false,sizeof(visited));
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    while(!v.empty())
    {
        if(!visited[v.top()])
        {
            unordered_set<int>*component = new unordered_set<int>();
            dfs2(graphT,v.top(),component,visited);
            output->insert(component);
        }
        else
        {
            v.pop();
        }
    }
    return output;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>graph[n+1];
    vector<int>graphT[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graphT[v].push_back(u);
    }
    unordered_set<unordered_set<int>*>*components = getSCC(graph,graphT,n);
    unordered_set<unordered_set<int>*>::iterator it=components->begin();
    while (it != components->end()) {
	    unordered_set<int>* component = *it;
	    unordered_set<int>::iterator it2 = component->begin();
	    while (it2 != component->end()) {
	        cout<<*it2<<" ";
	   	    it2++;
	    }
	    cout<<endl;
	    delete component;
	    it++;
	}
	delete components;
}
