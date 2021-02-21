#include <iostream>
#include <map>
#include <queue>
#include <climits>
#include <string.h>
#include <algorithm>
#include <sstream>
using namespace std;
class node
{
public:
	int data;
	node* left,*right;
	node(int d=0):data(d){
		left = NULL;
		right = NULL;
	}
};
node* buildTree(){
	int d;
	cin>>d;
	if(d == -1)
		return NULL;
	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}
node *build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}
node* insertinBST(node* root,int val){
	if(root == NULL){
		node* n = new node(val);
		return n;
	}
	if(root->data < val){
		root->right = insertinBST(root->right,val);
		return root;
	}
	root->left = insertinBST(root->left,val);
	return root;
}
node* deleteInBST(node* root,int val){
	if(root == NULL)
		return NULL;
	if(root->data < val){
		root->right = deleteInBST(root->right,val);
		return root;
	}
	if(root->data > val){
		root->left = deleteInBST(root->left,val);
		return root;
	}
	// root->data == val
	if(root->left == NULL and root->right == NULL){
		delete root;
		return NULL;
	}
	if(root->left == NULL){
		node* temp = root->right;
		delete root;
		return temp;
	}
	if(root->right == NULL){
		node* temp = root->left;
		delete root;
		return temp;
	}
	// Both children
	node* inorder_succ = root->right;
	while(inorder_succ->left != NULL){
		inorder_succ = inorder_succ->left;
	}
	root->data = inorder_succ->data;
	root->right = deleteInBST(root->right,inorder_succ->data);
	return root;
}
void printPre(node* root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	printPre(root->left);
	printPre(root->right);
}
void bottom_view_util(node* root,int pos,map<int,int> &mp){
	if(root == NULL)
		return;
	mp[pos] = root->data;
	// cout<<pos<<":"<<root->data<<endl;
	bottom_view_util(root->left,pos-1,mp);
	bottom_view_util(root->right,pos+1,mp);
}
void bottom_view(node* root){
	map<int,int> mp;
	bottom_view_util(root,0,mp);
	for(auto itr:mp)
		cout<<itr.second<<" ";
	cout<<endl;
}
void top_view_util(node* root,int pos,map<int,int> &mp){
	if(root == NULL)
		return;
	top_view_util(root->left,pos-1,mp);
	top_view_util(root->right,pos+1,mp);
	mp[pos] = root->data;
}
void top_view(node* root){
	map<int,int> mp;
	top_view_util(root,0,mp);
	for(auto itr:mp)
		cout<<itr.second<<" ";
	cout<<endl;
}
void left_view_util(node* root,int depth, map<int,int> &mp){
	if(root == NULL)
		return;
	mp[depth] = root->data;
	left_view_util(root->right,depth+1,mp);
	left_view_util(root->left,depth+1,mp);
}
void left_view(node* root){
	map<int,int> mp;
	left_view_util(root,0,mp);
	for(auto itr:mp)
		cout<<itr.second<<" ";
	cout<<endl;
}
void right_view_util(node* root,int depth, map<int,int> &mp){
	if(root == NULL)
		return;
	mp[depth] = root->data;
	right_view_util(root->left,depth+1,mp);
	right_view_util(root->right,depth+1,mp);
}
void right_view(node* root){
	map<int,int> mp;
	right_view_util(root,0,mp);
	for(auto itr:mp)
		cout<<itr.second<<" ";
	cout<<endl;
}

int height(node* root){
	if(root == NULL)
		return 0;
	if(root->left == NULL and root->right == NULL)
		return 1;
	return max(height(root->left),height(root->right))+1;
}

void LvlOrder(node* root){
	if(root == NULL)
		return;
	queue<pair<node*,int>> q;
	q.push({root,0});
	int curr= 0;
	while(!q.empty()){
		auto temp = q.front();
		q.pop();
		if(curr != temp.second){
			cout<<endl;
			curr= temp.second;
		}
		cout<<temp.first->data<<" ";
		if(temp.first->left)
			q.push({temp.first->left,curr+1});
		if(temp.first->right)
			q.push({temp.first->right,curr+1});
	}
	cout<<endl;
}
int diameter(node* root){
	if(root == NULL)
		return 0;
	return 1+height(root->left) + height(root->right);
}

int SumReplacement(node* root){
	if(root == NULL)
		return 0;
	if(root->left == NULL and root->right == NULL)
		return root->data;
	int left = SumReplacement(root->left);
	int right = SumReplacement(root->right);
	int data = root->data;
	root->data = left+right;
	return root->data + data;
}
int Balance(node* root){
	if(root == NULL)
		return 0;
	int left = Balance(root->left);
	int right = Balance(root->right);
	if(left == -1 || right == -1)
		return -1;
	if(abs(left-right) > 1){
		return -1;
	}
	return max(left,right)+1;
}
bool isBalanced(node* root){
	return Balance(root) == -1? 0:1;
}
node* treeFromIn_Pre(int* in,int* pre, int s, int e){
	static int i = 0;
	if(s > e)
		return NULL;
	int index = -1;
	for(int j=s;j<=e;j++){
		if(pre[i] == in[j]){
			index = j;
			break;
		}
	}
	node* root = new node(pre[i]);
	i++;
	root->left = treeFromIn_Pre(in,pre,s,index-1);
	root->right = treeFromIn_Pre(in,pre,index+1,e);
	return root;
}
void rightView(node* root,int &max_lvl, int this_lvl){
	if(!root)
		return;
	if(this_lvl > max_lvl){
		cout<<root->data<<" ";
		max_lvl = this_lvl;
	}
	rightView(root->right,max_lvl,this_lvl+1);
	rightView(root->left,max_lvl,this_lvl+1);
}
class pair3{
public:
	int min,max;
	bool isBST;
	pair3(){
		isBST = true;
		min = INT_MAX;
		max = INT_MIN;
	}
	void print(){
		cout<<min<<" "<<max<<" "<<isBST<<endl;
	}
};
pair3 isBST_bottomup(node* root){
	pair3 thisp;
	if(root == NULL)
		return thisp;
	pair3 leftans = isBST_bottomup(root->left);
	if(!leftans.isBST){	
		thisp.isBST = false;
		return thisp;
	}
	pair3 rightans = isBST_bottomup(root->right);
	if(!rightans.isBST){	
		thisp.isBST = false;
		return thisp;
	}
	if(root->data < leftans.max or root->data > rightans.min){
		thisp.isBST = false;
		return thisp;
	}
	thisp.max = max(root->data,max(leftans.max,rightans.max));
	thisp.min = min(root->data,min(leftans.min,rightans.min));
	thisp.isBST = leftans.isBST && rightans.isBST;
	thisp.print();
	return thisp;
}
bool isBST_topdown(node* root, int min = INT_MIN, int max = INT_MAX){
	if (root == NULL)
		return true;
	if(root->data <= max and root->data >= min and isBST_topdown(root->left,min,root->data) and isBST_topdown(root->right,root->data,max))
		return true;
	return false;
}
bool isStructurallyIdentical(node* r1, node * r2){
	if(r1 == NULL and r2 == NULL)
		return true;
	if(r1 == NULL or r2 == NULL)
		return false;
	return isStructurallyIdentical(r1->left,r2->left) and isStructurallyIdentical(r1->right, r2->right);
}

node* buildBSTfromSortedArray(int* arr,int l, int r){
	if(l>r)
		return NULL;
	int mid = (l+r)/2;
	node* root = new node(arr[mid]);
	root->left = buildBSTfromSortedArray(arr,l,mid-1);
	root->right = buildBSTfromSortedArray(arr,mid+1,r);
	return root;
}
node* deleteTree(node* root){
	if(root == NULL)
		return NULL;
	if(root->left == NULL and root->right == NULL){
		delete root;
		return NULL;
	}
	root->left = deleteTree(root->left);
	root->right = deleteTree(root->right);
	delete root;
	return NULL;
}
void printNodesInaRange_BST(node* root,int a, int b){
	if(root == NULL)
		return;
	printNodesInaRange_BST(root->left,a,b);
	if(root->data >=a and root->data <=b)
		cout<<root->data<<" ";
	printNodesInaRange_BST(root->right,a,b);
}
node* buildTree_from_lvlTraversal(vector<int> arr){
	if(arr[0] == -1)
		return NULL;
	int n = arr.size();
	queue<node*> nodeq;
	node* root = new node(arr[0]);
	nodeq.push(root);
	for(int i=1;i<n-1;i+=2){
		node* curr = nodeq.front();
		nodeq.pop();
		if(arr[i] == -1){
			curr->left = NULL;
		}
		else{
			curr->left = new node(arr[i]);
			nodeq.push(curr->left);
		}
		if(arr[i+1] == -1){
			curr->right = NULL;
		}
		else{
			curr->right = new node(arr[i+1]);
			nodeq.push(curr->right);
		}
	}
	return root;
}
void printZigZigLvlOrder(node* root){
	if(root == NULL)
		return;
	queue<pair<node*,int>> q;
	q.push({root,0});
	int curr_lvl = 0;
	vector<int> arr;
	while(!q.empty()){
		auto top = q.front();
		if(curr_lvl != top.second){
			if(curr_lvl%2 == 1)
				reverse(arr.begin(),arr.end());
			for(int i:arr)
				cout<<i<<" ";
			cout<<endl;
			arr.clear();
			curr_lvl = top.second;
		}
		// cout<<top.first->data<<" ";
		arr.push_back(top.first->data);
		q.pop();
		if(top.first->left != NULL)
			q.push({top.first->left,top.second+1});
		if(top.first->right != NULL)
			q.push({top.first->right,top.second+1});
	}
	if(curr_lvl%2 == 1)
		reverse(arr.begin(),arr.end());
	for(int i:arr)
		cout<<i<<" ";
	cout<<endl;
}
void printPreModified(node * root){
	if(root == NULL)
		return;
	if(root->left == NULL)
		cout<<"END => ";
	else
		cout<<root->left->data<<" => ";
	cout<<root->data<<" ";

	if(root->right == NULL)
		cout<<"<= END";
	else
		cout<<"<= "<<root->right->data;
	cout<<endl;
	printPreModified(root->left);
	printPreModified(root->right);
}

void replace_with_sum_of_greater_nodes(node * root, int &sum){
	if(root == NULL)
		return;
	replace_with_sum_of_greater_nodes(root->right,sum);
	sum += root->data;
	root->data = sum;
	replace_with_sum_of_greater_nodes(root->left,sum);
}
class pair_BST{
public:
	int min,max, count;
	bool isBST;
	pair_BST(){
		isBST = true;
		min = INT_MAX;
		max = INT_MIN;
		count = 0;
	}
	void print(){
		cout<<min<<" "<<max<<" "<<isBST<<endl;
	}
};
pair_BST largestBST(node* root){
	pair_BST p;
	if(root == NULL)
		return p;
	pair_BST leftans = largestBST(root->left);
	pair_BST rightans = largestBST(root->right);
	if(leftans.isBST and rightans.isBST and root->data > leftans.max and root->data < rightans.min){
		p.count = rightans.count+leftans.count+1;
		p.isBST = true;
		p.max = max(root->data,max(leftans.max,rightans.max));
		p.min = min(root->data,min(leftans.min,rightans.min));
		return p;
	}
	p.count = max(leftans.count, rightans.count);
	p.isBST = false;
	return p;
}

int count_nodes(node* root){
	if(root == NULL)
		return 0;
	return count_nodes(root->left) + count_nodes(root->right) + 1;
}

void largestBST_bruteforce(node* root, int &ans){
	if(root == NULL)
		return;
	if(isBST_topdown(root)){
		ans = max(ans,count_nodes(root));
		return;
	}
	largestBST_bruteforce(root->left,ans);
	largestBST_bruteforce(root->right,ans);
}

int main() {
	// node* root = build("true");
	// printZigZigLvlOrder(root);
	// if(isBalanced(root))
	// 	cout<<"true\n";
	// else
	// 	cout<<"false\n";

	int n;
	cin>>n;
	int pre[n], in[n];
	for(int i=0;i<n;i++)
		cin>>pre[i];
	for(int i=0;i<n;i++)
		cin>>in[i];
	node* root = treeFromIn_Pre(in,pre,0,n-1);
	// int ans = 0;
	// largestBST_bruteforce(root,ans);
	// cout<<ans<<endl;
	cout<<largestBST(root).count<<endl;

	// int n;
	// cin>>n;
	// int arr[n];
	// for(int i=0;i<n;i++)
	// 	cin>>arr[i];
	// node * bstRoot = buildBSTfromSortedArray(arr,0,n-1);
	// int sum = 0;
	// replace_with_sum_of_greater_nodes(bstRoot, sum);
	// printPre(bstRoot);
	// cout<<endl;

	// int t;
	// cin>>t;
	// while(t--){
	// 	int n,m;
	// 	node* bst = NULL;
	// 	cin>>n;
	// 	while(n--){
	// 		int data;
	// 		cin>>data;
	// 		bst = insertinBST(bst,data);
	// 	}
	// 	// printPre(bst);
	// 	cin>>m;
	// 	while(m--){
	// 		int data;
	// 		cin>>data;
	// 		bst = deleteInBST(bst,data);
	// 	}
	// 	printPre(bst);
	// 	cout<<endl;
	// }

	// string line,inp;
	// getline(cin,line);
	// stringstream X(line);
	// vector<int> arr;
	// while (getline(X, inp, ' ')) { 
 //        arr.push_back(stoi(inp));
 //    }
 //    node* root = buildTree_from_lvlTraversal(arr);
    // LvlOrder(root);
    // printPre(root);
    // cout<<"\n========================\n";
    // bottom_view(root);
    // top_view(root);
    // left_view(root);
    // right_view(root);
	return 0;
}