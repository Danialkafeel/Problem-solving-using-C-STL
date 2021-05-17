#include <bits/stdc++.h>
#define ll long long
using namespace std;

class graph
{
public:
	int V;
	unordered_map<int,list<pair<int,int>>> adj;
	graph(int n){
		V = n;
	}

	void addEdge(int u, int v, int weight, bool bidir){
		adj[u].push_back(make_pair(v,weight));
		if(bidir)
			adj[v].push_back(make_pair(u,weight));
	}
	void print(){
		for(auto p: adj){
			cout<<"Node "<<p.first<<" : ";
			for(auto x: p.second){
				cout<<"("<<x.first<<"-"<<x.second<<") , ";
			}
			cout<<endl;
		}
	}
	map<int,int> dijkstra(int starting_node){
		map<int,int> ans;
		for(int i=1;i<=V;i++){
			ans[i] = INT_MAX;
		}
		ans[starting_node] = 0;

		set<pair<int,int>> s;
		s.insert(make_pair(0,starting_node));

		while(!s.empty()){
			// cout<<"s.size() = "<<s.size()<<endl;
			auto finalized_node = *s.begin();
			ans[finalized_node.second] = finalized_node.first;
			// cout<<"finalized_node: "<<finalized_node.second<<": "<<finalized_node.first<<endl;
			s.erase(s.begin());
			for(auto nbr: adj[finalized_node.second]){
				if((finalized_node.first + nbr.second) < ans[nbr.first]){
					auto p = s.find(make_pair(ans[nbr.first], nbr.first));
					if(p == s.end()){
						s.insert(make_pair(finalized_node.first + nbr.second, nbr.first));
						ans[nbr.first] = finalized_node.first + nbr.second;
						// cout<<"1Inserting "<<finalized_node.first + nbr.second<<" : "<< nbr.first<<endl;
					}
					else{
						s.erase(p);
						s.insert(make_pair(finalized_node.first + nbr.second, nbr.first));
						ans[nbr.first] = finalized_node.first + nbr.second;
						// cout<<"2Inserting "<<finalized_node.first + nbr.second<<" : "<< nbr.first<<endl;
					}
				}
			}
		}
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
		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			g.addEdge(u,v,w,true);
		}
		// g.print();
		int s;
		cin>>s;
		auto sssp = g.dijkstra(s);
		for(auto p: sssp){
			if(p.first == s)
				continue;
			if(p.second == INT_MAX)
				cout<<"-1 ";
			else
				cout<<p.second<<" ";
		}
		cout<<endl;
	}
	return 0;
}