#include<bits/stdc++.h>
#define ll long long
using namespace std;

class node{
public:
	node *left, *right;
	vector<int> indices;
	void add(int ind){
		indices.push_back(ind);
	}
	bool index_present(int l, int r){
		int s = 0, e = indices.size()-1;
		while(s <= e){
			int mid = (s+e)/2;
			if(indices[mid]>=l and indices[mid] <= r)
				return true;
			else if(indices[mid] < l){
				s = mid + 1;
			}
			else if(indices[mid] > r){
				e = mid - 1;
			}
		}
		return false;
	}
	node(){
		left = right = NULL;
	}
};
void insert_in_trie(node* root, ll x,int ind){
	bool bin[32] = {0};
	int i = 31;
	while(x){
		bin[i--] = x%2;
		x = x>>1;
	}
	node* temp = root;
	for(int i=0;i<32;i++){
		temp->add(ind);
		if(bin[i] == 0){
			if(temp->left == NULL){
				temp->left = new node();
				temp = temp->left;
			}
			else{
				temp = temp->left;
			}
		}
		else if(bin[i] == 1){
			if(temp->right == NULL){
				temp->right = new node();
				temp = temp->right;
			}
			else{
				temp = temp->right;
			}
		}
	}
	temp->add(ind);
}

int main() {
	node* trie_root = new node();
	int q,ind = 1;
	cin>>q;
	while(q--){
		int ch;
		cin>>ch;
		if(ch==0){
			ll x;
			cin>>x;
			insert_in_trie(trie_root,x,ind++);
		}
		else{
			ll l,r,x;
			cin>>l>>r>>x;
			bool bin[32] = {0};
			int i = 31;
			while(x){
				bin[i--] = x%2;
				x = x>>1;
			}
			ll ans = 0;
			node* temp = trie_root;
			for(int i=0;i<32;i++){
				ans = ans<<1;
				if(bin[i] == 0){
					if(temp->right!= NULL and temp->right->index_present(l,r)){
						ans += 1;
						// cout<<"i0 = "<<i<<endl;
						temp = temp->right;
					}
					else{
						temp = temp->left;
					}
				}
				else if(bin[i] == 1){
					if(temp->left!= NULL and temp->left->index_present(l,r)){
						// ans += 1;
						// cout<<"i1 = "<<i<<endl;
						temp = temp->left;
					}
					else{
						ans += 1;
						temp = temp->right;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	// cout<<trie_root->indices.size()<<" "<<trie_root->left->indices.size()<<endl;
	return 0;
}