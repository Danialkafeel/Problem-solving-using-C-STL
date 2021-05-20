#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		int l = 0, h = 0;
		for(int i=0;i<n/2;i++)
			h += abs(arr[i]- arr[n-i-1]);
		for(int i=0;i<n;i+=2)
			l += abs(arr[i]-arr[i+1]);
		cout<<l<<" "<<h<<endl;
	}
	return 0;
}