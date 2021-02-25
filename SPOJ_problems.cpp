#include<bits/stdc++.h>
#define ll long long
using namespace std;
int BALIFE(int* arr, int n){
	int cumm[n];
	cumm[0] = arr[0];
	for(int i=1;i<n;i++)
		cumm[i] = arr[i] + cumm[i-1];
	int jobs = cumm[n-1]/n;
	if((1.0*cumm[n-1]/n) != jobs)
		return -1;
	int rounds = 0;
	for(int i=0;i<n-1;i++){
		int rounds_with_curr_split = abs((jobs*(i+1)) - cumm[i]);
		// cout<<"i = "<<i<<":"<<rounds_with_curr_split<<endl;
		rounds = max(rounds,rounds_with_curr_split);
	}
	return rounds;
}
int DEFKIN(int x[],int y[],int w, int h,int n){
	if(n == 0){
		return w*h;
	}
	sort(x,x+n);
	sort(y,y+n);
	vector<int> dx,dy;
	// dx.push_back(x[0]-1);
	// dy.push_back(y[0]-1);
	for(int i=1;i<n;i++){
		dx.push_back(x[i]-x[i-1]-1);
		dy.push_back(y[i]-y[i-1]-1);
	}
	// dx.push_back(w-x[n-1]);
	// dy.push_back(h-y[n-1]);
	return (*max_element(dx.begin(),dx.end()))*(*max_element(dy.begin(),dy.end()));
}
void EXPEDI(){
	class comp
	{
	public:
		bool operator()(pair<int,int> p1, pair<int,int> p2){
			return p1.second > p2.second;
		}		
	};
	int t;
	cin>>t;
	while(t--){
		ll n,l,p;
		cin>>n;
		pair<int,int> dist_fuel[n];
		for(int i=0;i<n;i++)
			cin>>dist_fuel[i].first>>dist_fuel[i].second;
		cin>>l>>p;
		for(int i=0;i<n;i++)
			dist_fuel[i].first = l - dist_fuel[i].first;
		sort(dist_fuel,dist_fuel+n);
		// for(int i=0;i<n;i++)
		// 	cout<<dist_fuel[i].first<<":"<<dist_fuel[i].second<<endl;
		priority_queue<pair<int,int>,vector<pair<int,int>>, comp> heap;
		if(dist_fuel[0].first > p){
			cout<<"-1\n";
			continue;
		}
		// heap.push(dist_fuel[0]);
		int ind = 0, ans = 0, prev = 0;
		bool flag = false;
		while(l>0){
			// cout<<"p,l = "<<p<<" "<<l<<endl;
			while(ind < n and p >= (dist_fuel[ind].first - prev)){
				ind++;
				heap.push(dist_fuel[ind]);
			}
			if(heap.empty()){
				flag = true;
				cout<<"-1\n";
				break;
			}
			auto next_station = heap.top();
			heap.pop();
			prev = next_station.first;
			l -= next_station.first;
			p += next_station.second;
			ans++;
			ind++;
		}
		if(not flag)
			cout<<ans<<endl;
	}
}

int main(){
	// int n;
	// cin>>n;
	// while(n != -1){
	// 	int arr[n];
	// 	for(int i=0;i<n;i++)
	// 		cin>>arr[i];
	// 	cout<<BALIFE(arr,n)<<endl;
	// 	cin>>n;
	// }
	int t=1;
	// cin>>t;
	while(t--){
		int w,h, n;
		// cin>>w>>h;
		cin>>n;
		int x[n], y[n];
		for(int i=0;i<n;i++)
			cin>>x[i]>>y[i];
		cout<<DEFKIN(x,y,w,h,n)<<endl;
	}
	// EXPEDI();
}