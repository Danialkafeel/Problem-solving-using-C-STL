#include<bits/stdc++.h>
#include<climits>
#define ll long long
using namespace std;

string minimum_length_substring(string s1, string s2){
	if(s2.size() > s1.size()){
		cout<<"No String\n";
		return "-1";
	}
	int freq[256] = {0};
	for(char ch:s2){
		freq[ch]++;
	}
	int ans = INT_MAX;
	int cnt = 0, start = 0, start_ans = -1;
	int curr_freq[256] = {0};
	for(int i=0;i<s1.size();i++){
		curr_freq[s1[i]]++;
		if(freq[s1[i]] > 0 and curr_freq[s1[i]] <= freq[s1[i]])
			cnt++;
		if(cnt == s2.size()){		// All chars occurred.
			// Shrinking the window.
			while(freq[s1[start]] == 0 or freq[s1[start]] < curr_freq[s1[start]]){
				curr_freq[s1[start]]--;
				start++;
			}
			if(i-start+1 < ans){
				ans = i-start+1;
				start_ans = start;
			}
		}
	}
	if(ans == INT_MAX){
		cout<<"No String\n";
		return "-1";
	}
	return s1.substr(start_ans,ans);
}
ll subarrays_with_distinct_elements(ll* arr, ll n){
	ll mod = 1000000007, ans = 0;
	ll l,r;
	l = r = 0;
	unordered_map<ll,int> mp;
	for(;r<n;r++){
		if(mp.find(arr[r]) == mp.end() or mp[arr[r]] == 0){
			cout<<"Inserting "<<arr[r]<<endl;
			mp[arr[r]] = 1;
		}
		else{
			ll len = r-l;
			cout<<"l,r = "<<l<<" "<<r<<endl;
			ll temp = (len * (len+1))%mod;
			temp = temp/2;
			// cout<<"temp = "<<temp<<endl;
			ans = (ans + temp)%mod;
			mp[arr[l]]--;
			l++;
			mp[arr[r]]++;
		}
	}
	cout<<"yo\n";
	for(;l<n;l++){
		ll len = n - l;
		cout<<"len = "<<len<<endl;
		ll temp = (len * (len+1))%mod;
		temp = temp/2;
		// cout<<"temp = "<<temp<<endl;
		ans = (ans + temp)%mod;
	}
	return ans;
}
int main() {
	// string s1, s2;
	// getline(cin,s1);
	// getline(cin,s2);
	// string ans = minimum_length_substring(s1,s2);
	// if(ans != "-1"){
	// 	cout<<ans<<endl;
	// }
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	cout<<subarrays_with_distinct_elements(arr,n)<<endl;
	return 0;
}