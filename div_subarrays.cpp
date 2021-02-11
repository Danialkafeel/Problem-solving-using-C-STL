#include <iostream>
#define ll long long
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll arr[n],sa[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sa[0] = arr[0]%n;
		for(int i=1;i<n;i++)
			sa[i] = (sa[i-1]+arr[i])%n;
		// for(int i=0;i<n;i++)
		// 	cout<<sa[i]<<" ";
		// cout<<endl;
		int cnt[n]={0};
		for(int i=0;i<n;i++)
			cnt[sa[i]]++;
		// for(int i=0;i<n;i++)
		// 	cout<<cnt[i]<<" ";
		// cout<<endl;
		ll ans = cnt[0];
		for(int i=0;i<n;i++){
			ans += (cnt[i]*(cnt[i]-1)/2);
		}
		cout<<ans<<endl;
	}
	return 0;
}