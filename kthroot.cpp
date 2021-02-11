#include<iostream>
#include<math.h>
#define ll long long
using namespace std;

ll kthroot(ll n,int k){
	ll s = 1, e = n, ans = -1;
	while(s <= e){
		ll mid = (s+e)/2;
		if(pow(mid,k)<= n){
			ans = mid;
			s = mid+1;
		}
		else
			e = mid-1;
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		ll n;
		int k;
		cin>>n>>k;
		ll ans = kthroot(n,k);
		cout<<ans<<endl;
	}
	return 0;
}