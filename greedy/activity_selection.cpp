#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
	return p1.second < p2.second;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		pair<int,int> arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i].first>>arr[i].second;
		}
		sort(arr,arr+n,cmp);
		int last = 0;
		int ans = 1;
		for(int i=1;i<n;i++){
			if(arr[i].first >= arr[last].second){
				ans++;
				last = i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}