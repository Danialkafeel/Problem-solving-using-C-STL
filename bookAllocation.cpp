#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[],int n,int mid, int m){
	int curr = 0,studs=0;
	for(int i=0;i<n;i++){
		if(curr+arr[i] <= mid){
			curr += arr[i];
		}
		else{
			curr = arr[i];
			studs++;
			if(studs >= m){
				return 0;
			}
		}
	}
	return 1;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int msum = accumulate(arr,arr+n,0);
		int s = arr[n-1], e = msum,ans=-1;
		while(s<=e){
			int mid = (s+e)/2;
			if(isPossible(arr,n,mid,m)){
				e = mid-1;
				ans = mid;
			}
			else{
				s = mid+1;
			}
		}
		cout<<ans<<endl;
	}
}