#include <bits/stdc++.h>
#define ll long long
using namespace std;

class graph
{
	int n;
	int **adj_mat;
public:
	graph(int n){
		this->n = n;
		adj_mat = new int*[n];
		for(int i=0;i<n;i++){
			adj_mat[i] = new int[n];
			for(int j=0;j<n;j++)
				adj_mat[i][j] = INT_MAX;
		}
	}
	void addEdge(int u, int v, int wt){
		adj_mat[u][v] = wt;
		adj_mat[v][u] = wt;
	}
	int** floyd_warshall(){
		int** ans = new int*[n];
		for(int i=0;i<n;i++){
			ans[i] = new int[n];
			for(int j=0;j<n;j++){
				if(i == j)
					ans[i][j] = 0;
				else
					ans[i][j] = adj_mat[i][j];
			}
		}
		for(int k = 0;k<n;k++){
			for(int i=0;i<n;i++){
				if(i == k)
					continue;
				for(int j=0;j<n;j++){
					if(j == k)
						continue;
					if(ans[i][k] != INT_MAX and ans[k][j] != INT_MAX and (ans[i][k]+ans[k][j]) < ans[i][j])
						ans[i][j] = ans[i][k]+ans[k][j];
				}
			}
		}
		// 	Could also do 1 more time to detect -ve weight cycles.
		return ans;
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
		int** ans = g.floyd_warshall();

		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++)
		// 		cout<<ans[i][j]<<" ";
		// 	cout<<endl;
		// }


		for(int i=0;i<n;i++){
			if(i == source-1)
				continue;
			if(ans[source-1][i] == INT_MAX)
				cout<<"-1 ";
			else
				cout<<ans[source-1][i]<<" ";
		}
		cout<<endl;
	}	
	return 0;
}