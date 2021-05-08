#include <bits/stdc++.h>
#define ll long long
using namespace std;

class cmp
{
public:
	bool operator()(pair<ll,ll> p1, pair<ll,ll> p2){
		return p1.second < p2.second;
	}	
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll L,P;
		pair<ll,ll> dist_fuel[n];
		for(int i=0;i<n;i++)
			cin>>dist_fuel[i].first>>dist_fuel[i].second;

		cin>>L>>P;

		for(int i=0;i<n;i++)
			dist_fuel[i].first = L - dist_fuel[i].first;

		sort(dist_fuel,dist_fuel+n);
		priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, cmp> heap;

		ll ans = 0, curr_ind = 0, prev_stop = 0;
		while(L > 0){
			if(P >= L)
				break;
			while(curr_ind < n and (dist_fuel[curr_ind].first - prev_stop) <= P){
				heap.push(dist_fuel[curr_ind]);
				curr_ind++;
			}
			if(heap.empty()){
				ans = -1;
				break;
			}

			auto stop = heap.top();
			heap.pop();
			ans++;
			P -= (stop.first - prev_stop);
			P += stop.second;
			L -= (stop.first - prev_stop);
			prev_stop = stop.first;
			// cout<<"stop: ";
			// cout<<stop.first<<" "<<stop.second<<endl;
			// cout<<"curr dist, fuel: ";
			// cout<<L<<" "<<P<<endl;
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}