#include <bits/stdc++.h>
#define ll long long
using namespace std;

class DSU
{
	int n;
	int *rank, *parent;
public:
	DSU(int N){
		n = N;
		rank = new int[n];
		parent = new int[n];
		for(int i=0;i<n;i++){
			rank[i] = 1;
			parent[i] = -1;
		}
	}
	void union_set(int a , int b){
		int s1 = find_set(a);
		int s2 = find_set(b);
		if(s1 != s2){
			if(rank[s1] < rank[s2]){
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else{
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
		// else
		// 	cout<<"Already in the same set\n";
	}
	int find_set(int a){
		if(parent[a] == -1)
			return a;
		return parent[a] = find_set(parent[a]);
	}
	int count_sets(){
		int ans = 0;
		for(int i = 0;i<n;i++)
			if(rank[i] == -1)
				ans++;
		return ans;
	}
	ll find_pair(){
		ll ans = 0;
		for(int i=0;i<n;i++){
			ans += n - rank[find_set(i)];
			// cout<<"ans = "<<ans<<endl;
		}
		ans /= 2;
		// cout<<"ans =="<<ans<<endl;
		return ans;
	}
	void show(){
		cout<<"Parent\n";
		for(int i=0;i<n;i++)
			cout<<parent[i]<<" ";
		cout<<endl;

		cout<<"Rank\n";
		for(int i=0;i<n;i++)
			cout<<rank[i]<<" ";
		cout<<endl;
		
	}
};

int main(){
	int n,m;
	cin>>n>>m;
	DSU my_dsu(n);
	while(m--){
		int a,b;
		cin>>a>>b;
		my_dsu.union_set(a,b);
	}
	// my_dsu.show();

	cout<<my_dsu.find_pair()<<endl;
	return 0;
}