#include <iostream>
#include <queue>
#include <set>
#include <stack>
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
			
	}
}
void median_in_a_stream(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int arr[n];
		priority_queue<int> left_heap;
		priority_queue<int,vector<int>, greater<int>> right_heap;
		cin>>arr[0];
		int median = arr[0];
		cout<<median<<" ";
		left_heap.push(arr[0]);
		for (int i = 1; i < n; ++i){
			cin>>arr[i];
			if(arr[i] < median){
				if(left_heap.size() > right_heap.size()){
					right_heap.push(left_heap.top());
					left_heap.pop();
					left_heap.push(arr[i]);
					median = 1.0*(left_heap.top()+right_heap.top())/2;
				}
				else{
					left_heap.push(arr[i]);
					if(left_heap.size() == right_heap.size())
						median = 1.0*(left_heap.top()+right_heap.top())/2;
					else
						median = left_heap.top();
				}
			}
			else{
				if(left_heap.size() < right_heap.size()){
					left_heap.push(right_heap.top());
					right_heap.pop();
					right_heap.push(arr[i]);
					median = 1.0*(left_heap.top()+right_heap.top())/2;
				}
				else{
					right_heap.push(arr[i]);
					if(left_heap.size() == right_heap.size())
						median = 1.0*(left_heap.top()+right_heap.top())/2;
					else
						median = right_heap.top();
				}
			}
			cout<<median<<" ";
		}
		cout<<"\n";
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

	// k_mostFrequent_running_stream();
	median_in_a_stream();
	return 0;
}