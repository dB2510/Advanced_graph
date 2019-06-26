#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define fi(i,a,n) for(lli i = a; i < n; i++)
#define fd(i,a,n) for(lli i = a; i > n; i--)
#define fv(i,a) for(auto i:a)
#define pb push_back
#define mp make_pair
#define MAX 1000

lli bfs(vector<vector<lli>>&capacity, vector<lli>graph[], vector<lli>&parent, lli s, lli t, lli v)
{
    fill(parent.begin(),parent.end(), -1);
    parent[s]=-2;
	queue<lli>q;
	q.push(s);
	lli pathflow=INT_MAX;
	while(!q.empty())
	{
		lli cur=q.front();
		q.pop();
		fv(next,graph[cur])
		{
			if(parent[next]==-1 && capacity[cur][next])
			{
				pathflow=min(pathflow,capacity[cur][next]);
				q.push(next);
				parent[next]=cur;
				if(next==t)
					return pathflow;
			}
		}
	}
	return 0;
}

lli max_flow(vector<vector<lli>>&capacity, vector<lli>graph[],lli v, lli s, lli t)
{
	lli pathflow=0;
	lli maxflow=0;
	vector<lli>parent(v+1);
	pathflow=bfs(capacity,graph,parent,s,t,v);
	while(pathflow)
	{
		maxflow+=pathflow;
		lli u=t;
		while(u!=s)
		{
			lli pre=parent[u];
			capacity[pre][u]-=pathflow;
			capacity[u][pre]+=pathflow;
			u=pre;
		}
		pathflow=bfs(capacity,graph,parent,s,t,v);
	}
	return maxflow;
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
lli t;
cin>>t;
while(t--)
{
// 	cout<<"hell";
	lli v,e;
	cin>>v>>e;
	vector<lli>graph[v+1];
	vector<vector<lli>>capacity(v+1);
	fi(i,0,v+1)
	capacity[i]=vector<lli>(v+1,0);
	fi(i,0,e)
	{
		lli u,v,w;
		cin>>u>>v>>w;
		graph[u].pb(v);
		graph[v].pb(u);
		capacity[u][v]+=w;
		capacity[v][u]+=w;
	}
	cout<<max_flow(capacity,graph,v,1,v)<<endl;
}
return 0;
}
