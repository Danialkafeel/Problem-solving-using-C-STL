#include<iostream>
#include<climits>
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
int main() {
	string s1, s2;
	getline(cin,s1);
	getline(cin,s2);
	string ans = minimum_length_substring(s1,s2);
	if(ans != "-1"){
		cout<<ans<<endl;
	}
	return 0;
}