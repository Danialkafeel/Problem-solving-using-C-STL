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
	r = 1;
	unordered_map<ll,int> mp;
	mp[arr[0]]++;
	for(l=0;l<n;l++){
		while(r<n and (mp.find(arr[r]) == mp.end() or mp[arr[r]]==0)){
			mp[arr[r]]++;
			r++;
		}
		ll window = r-l;
		ans += ((window*(window+1))/2)%mod;
		mp[arr[l]]--;
	}
	return ans;
}

class node_trie
{
public:
	bool terminal;
	char data;
	map<char,node_trie*> children;
	node_trie(char d):data(d){
		terminal = false;
	}
};

void insert_in_trie(node_trie *root, string str, int n){
	if(n == 0){
		return;
	}
	node_trie* temp = root;
	for(int i=0;i<n;i++){
		if(temp->children.count(str[i])){
			temp = temp->children[str[i]];
		}
		else{
			temp->children[str[i]] = new node_trie(str[i]);
			temp = temp->children[str[i]];
		}
	}
	temp->terminal = true;
}

node_trie* last_matching_node_in_trie(node_trie* root, string str){
	node_trie* tt = NULL;
	if(str.size() == 0){
		return (tt);
	}
	node_trie* temp = root;
	for(int i=0;i<str.size();i++){
		if(temp->children.count(str[i])){
			temp = temp->children[str[i]];
		}
		else{
			return (tt);
		}
	}
	return temp;
}
void preorder_in_trie(string s, node_trie* root){
	if(root == NULL)
		return;
	if(root->terminal)
		cout<<s+root->data<<endl;
	for(auto p: root->children){
		preorder_in_trie(s+root->data, p.second);
	}
}

void dictionary(int n){
	node_trie* root = new node_trie('\0');
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		insert_in_trie(root,str,str.size());
	}
	int q;
	cin>>q;
	while(q--){
		string str;
		cin>>str;
		node_trie* last_matching_node = last_matching_node_in_trie(root,str);
		if(last_matching_node == NULL){
			cout<<"No suggestions\n";
			insert_in_trie(root, str, str.size());
		}
		else
			preorder_in_trie(str.substr(0,str.size()-1),last_matching_node);
	}
}

int main() {
	int n;
	cin>>n;
	dictionary(n);
	return 0;
}