#include <iostream>
#include <queue>
#define ll long long
using namespace std;
void kthMinimum(){
	ll q,k;
	cin>>q>>k;
	priority_queue<ll> heap;
	while(q--){
		ll n;
		cin>>n;
		if(n==1){
			ll x,y;
			cin>>x>>y;
			if(heap.size() < k)
				heap.push((x*x)+(y*y));
			else{
				if(heap.top() > (x*x)+(y*y)){
					heap.pop();
					heap.push((x*x)+(y*y));
				}
			}
		}
		else{
			cout<<heap.top()<<endl;
		}
	}
}
vector<int> mergeKsortedArrays(int n, int k, int** arr){
	typedef pair<int,pair<int,int>> heap_elem;
	vector<int> ans;
	priority_queue<heap_elem, vector<heap_elem>, greater<heap_elem>> heap;
	for(int i=0;i<k;i++)
		heap.push({arr[i][0],{i,0}});
	while(!heap.empty()){
		ans.push_back(heap.top().first);
		int row = heap.top().second.first;
		int col = heap.top().second.second;
		heap.pop();
		if(col < n-1)
			heap.push({arr[row][col+1],{row,col+1}});
	}
	return ans;
}
void k_mostFrequent_running_stream(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
	}
}
int main(){
	// kthMinimum();
	// int k,n;
	// cin>>k>>n;
	// int* arr[k];
	// for(int i=0;i<k;i++){
	// 	arr[i] = new int[n];
	// 	for(int j=0;j<n;j++)
	// 		cin>>arr[i][j];
	// }
	// vector<int> v = mergeKsortedArrays(n,k,arr);
	// for(auto vv:v)
	// 	cout<<vv<<" ";
	// cout<<endl;

	k_mostFrequent_running_stream();
	return 0;
}