#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define fi(i,a,n) for(int i = a; i < n; i++)
#define fd(i,a,n) for(int i = a; i > n; i--)
#define fv(i,a) for(auto i:a)
#define pb push_back
#define mp make_pair

int find(int v,int parent[])
{
	if(parent[v]!=v)
		parent[v]=find(parent[v],parent);
	return parent[v];
}

void make_set(int v,int *parent,int *rank)
{
	parent[v]=v;
	rank[v]=0;
}

void union_set(int a,int b,int *parent,int *rank,vector<pair<int,int>>&toremove)
{
	int aroot=find(a,parent);
	int broot=find(b,parent);
	if(aroot==broot)
	{
		toremove.pb(mp(a,b));
		return;
	}
	a=aroot;
	b=broot;
	if(rank[a]<rank[b])
		parent[a]=b;
	else if(rank[a]>rank[b])
		parent[b]=a;
	else
	{
		parent[b]=a;
		rank[a]++;
	}
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int t=1;
//cin>>t;
while(t--)
{
	int n;
	cin>>n;
	int parent[n+1];
	int rank[n+1];
	fi(i,1,n+1)
	make_set(i,parent,rank);
	vector<pair<int,int>>toremove;
	fi(i,0,n-1)
	{
		int u,v;
		cin>>u>>v;
		union_set(u,v,parent,rank,toremove);
	}
	// fv(i,toremove)
	// cout<<i.first<<" "<<i.second<<endl;
	vector<pair<int,int>>toadd;
	fi(i,2,n+1)
	{
		if(find(1,parent)!=find(i,parent))
		{
			toadd.pb(mp(1,i));
			union_set(1,i,parent,rank,toremove);
		}
	}
	// fi(i,1,n+1)
	// cout<<find(i,parent)<<endl;
	cout<<min(toadd.size(),toremove.size())<<endl;
	for(int i=0;i<min(toadd.size(),toremove.size());i++)
	{
		cout<<toremove[i].first<<" "<<toremove[i].second<<" "<<toadd[i].first<<" "<<toadd[i].second<<endl;
	}
}
return 0;
}
