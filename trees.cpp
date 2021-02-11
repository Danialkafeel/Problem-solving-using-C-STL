#include <iostream>
#include <map>
#include <queue>
#include <climits>
#include <string.h>
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

node* buildBalancedBST(node* root,int* arr,int l, int r){
	if(l>r)
		return NULL;
	int mid = (l+r)/2;
	root = new node(arr[mid]);
	root->left = buildBalancedBST(root->left,arr,l,mid-1);
	root->right = buildBalancedBST(root->right,arr,mid+1,r);
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
node* buildTree_from_lvlTraversal(int* arr, int ind = 1){
	cout<<"ind = "<<ind<<"\n";
	cout<<arr[ind]<<endl;
	if(arr[ind] == -1)
		return NULL;
	node* root = new node(arr[ind]);
	root->left = buildTree_from_lvlTraversal(arr, 2*ind);
	root->right = buildTree_from_lvlTraversal(arr, 2*ind+1);
	return root;
}
int arr[10000002];
int main() {
	int i=1;
	string line;
	getline(cin,line);
	cout<<line.size()<<" "<<line[line.size()-1]<<endl;
	char* ptr = strtok((char*)line.c_str()," ");
	while(ptr != NULL){
		arr[i++] = stoi((string)ptr);
		ptr = strtok(NULL," ");
	}
	node * root = buildTree_from_lvlTraversal(arr);
	printPre(root);
	cout<<endl;
	bottom_view(root);
	return 0;
}

/*

8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1


5    
1 2 3 4 5
3 1 2 4 5
*/