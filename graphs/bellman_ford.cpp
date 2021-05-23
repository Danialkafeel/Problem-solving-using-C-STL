#include <bits/stdc++.h>
#define ll long long
using namespace std;

class graph
{
	int n;
	vector<vector<int>> edgelist;
public:
	graph(int n){
		this->n = n;
	}
	void addEdge(int u, int v, int wt){
		edgelist.push_back({u,v,wt});
		edgelist.push_back({v,u,wt});
	}
	int* bellman_ford(int source){
		int* dists = new int[n];

		for(int i=0;i<n;i++)
			dists[i] = INT_MAX;

		dists[source] = 0;
		for(int i=0;i<n-1;i++){
			bool flag = 0;
			for(auto edge: edgelist){
				if(dists[edge[0]]!= INT_MAX and dists[edge[0]] + edge[2] < dists[edge[1]]){
					flag = 1;
					dists[edge[1]] = dists[edge[0]] + edge[2];
				}
			}
			if(flag == 0)
				break;
		}
		for(auto edge: edgelist){
			if(dists[edge[0]]!= INT_MAX and dists[edge[0]] + edge[2] < dists[edge[1]]){
				cout<<"Negative weight cycle found\n";
				return NULL;
			}
		}
		return dists;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		graph g(n);
		while(m--){
			int u,v,wt;
			cin>>u>>v>>wt;
			g.addEdge(u-1,v-1,wt);
		}
		int source;
		cin>>source;
		int * ans = g.bellman_ford(source-1);
		for(int i=0;i<n;i++){
			if(i == source-1)
				continue;
			if(ans[i] == INT_MAX)
				cout<<"-1 ";
			else
				cout<<ans[i]<<" ";
		}
		cout<<endl;
	}	
	return 0;
}