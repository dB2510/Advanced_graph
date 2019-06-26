#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void dfs(vector<int>*edges, int start, unordered_set<int>*component, bool *visited)
{
    visited[start]=true;
    component->insert(start);
    for(auto i:edges[start])
    {
        // int next=edges[start][i];
        if(!visited[i])
        {
            dfs(edges,i,component,visited);
        }
    }
}


unordered_set<unordered_set<int>*>* getcompo(int n, vector<int>*edges)
{
    bool visited[n+1];
    for(int i=0;i<=n;i++)
    visited[i]=false;
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            unordered_set<int>*component = new unordered_set<int>();
            dfs(edges,i,component,visited);
            output->insert(component);
        }
    }
    return output;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/home/dhruv/Desktop/input.txt", "r", stdin);
    freopen("/home/dhruv/Desktop/output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        m=n-1;
        vector<int>edges[n+1];
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        unordered_set<unordered_set<int>*>*components = getcompo(n, edges);
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
	return 0;
}

