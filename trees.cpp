#include<iostream>
#include<queue>
#include <climits>
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
void printPre(node* root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	printPre(root->left);
	printPre(root->right);
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

int main(){
	// int pre[] = {1,2,3,4,8,5,6,7};
	// int in[] = {3,2,8,4,1,6,7,5};
	// node * root = treeFromIn_Pre(in,pre,0,7);
	node* root = buildTree();
	LvlOrder(root);
	node* root2 = buildTree();
	LvlOrder(root2);
	cout<<isStructurallyIdentical(root,root2)<<endl;
	cout<<"------------\n";
	// cout<<isBST_bottomup(root).isBST<<endl;
	// cout<<isBST_topdown(root)<<endl;

	// int t = -1;
	// rightView(root,t,0);
	// SumReplacement(root);
	// LvlOrder(root);
	// cout<<isBalanced(root)<<endl;
	// cout<<diameter(root)<<endl;
	// printPre(root);
	// cout<<endl;
	// cout<<height(root);
	return 0;
}


/*

8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

*/