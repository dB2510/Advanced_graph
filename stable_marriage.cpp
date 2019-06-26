#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
#define fi(i,a,n) for(lli i = a; i < n; i++)
#define fd(i,a,n) for(lli i = a; i > n; i--)
#define fv(i,a) for(auto i:a)
#define pb push_back
#define mp make_pair

bool m_or_m1(vector<vector<lli>>prefer,lli N, lli m,lli m1,lli w)
{
	fi(i,0,N)
	{
		if(prefer[w][i]==m1)
			return false;
		if(prefer[w][i]==m)
			return true;
	}
	return false;
}

void couples(vector<vector<lli>>prefer,lli N)
{
	lli wpartner[N];
	bool free[N];
	memset(wpartner,-1,sizeof(wpartner));
	memset(free,false,sizeof(free));
	lli freemen=N;
	while(freemen)
	{
		lli m;
		fi(i,0,N)
		{
			if(!free[i])
			{
				m=i;
				break;
			}
		}
		fi(i,0,N)
		{
			if(!free[m])
			{
				lli w=prefer[m][i]-N;
				if(wpartner[w]==-1)
				{
					wpartner[w]=m;
					freemen--;
					free[m]=true;
				}
				else
				{
					if(m_or_m1(prefer,N,m,wpartner[w],w))
					{
						free[wpartner[w]]=false;
						wpartner[w]=m;
						free[m]=true;
					}
				}
			}
			else
				break;
		}
	}
	fi(i,0,N)
	cout<<i+N<<" "<<wpartner[i]<<endl;
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
lli t=1;
//cin>>t;
while(t--)
{
	int N;
	cin>>N;
	vector<vector<lli>>prefer(2*N);
	fi(i,0,2*N)
	prefer[i]=vector<lli>(N);
	fi(i,0,2*N)
	fi(j,0,N)
	cin>>prefer[i][j];
	couples(prefer,N);
}
return 0;
}
