#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int c[n], l[n];
		for(int i=0; i<n;i++)
			cin>>c[i];
		for(int i=0; i<n;i++)
			cin>>l[i];

		ll ans = 0;
		int last = 0;
		for(int i=1;i<n;i++){
			cout<<"last = "<<last<<endl;
			ans += l[i-1]*c[last];
			if(c[i] < c[last]){
				last = i;
			}
			cout<<"ans = "<<ans<<endl;
		}
		ans += c[last]*l[n-1];
		cout<<ans<<endl;
	}
	return 0;
}	