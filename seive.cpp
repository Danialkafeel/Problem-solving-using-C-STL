#include<iostream>
#include<vector>
#define ll long long
using namespace std;
vector<ll> primes;

ll max_size = 10000000;
bool arr[10000001] = {0};

void seive(){
	for(ll i=3;i<=max_size;i+=2){
		arr[i] = 1;
	}
	arr[2] = 1;
	primes.push_back(2);
	for(ll i=3;i<=max_size;i++){
		if(arr[i]){
			primes.push_back(i);
			for(ll j = i*i;j<=max_size;j+=i){
				arr[j] = 0;
			}
		}
	}
}

void candy(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<primes[n-1]<<endl;
	}
}
void pmo(){
	int cnt[1000001];
	cnt[0] = arr[0];
	for(int i=1;i<1000001;i++)
		cnt[i] = cnt[i-1]+arr[i];
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<cnt[b]-cnt[a]+arr[a]<<endl;
	}	
}

int main() {
	primes.clear();
	seive();
	// candy();
	pmo();
	return 0;
}