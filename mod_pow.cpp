#include <iostream>
#define ll long long
using namespace std;

ll mpow(int a,int b, int mod){
	ll ans = 1;
	while(b>0){
		if(b&1){
			ans = (ans*a)%mod;
		}
		a = (a*a)%mod;
		b >>= 1;
	}
	return ans;
}

int main(){
	int a,b,mod;
	cin>>a>>b>>mod;
	cout<<mpow(a,b,mod)<<endl;
	return 0;
}