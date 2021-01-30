#include <iostream>
#include <stack>
using namespace std;
void stock_span(int arr[], int n){
	stack<int> stk;
	stk.push(0);
	int span[n];
	span[0] = 1;
	for(int i=1;i<n;i++){
		while(!stk.empty() and arr[stk.top()] <= arr[i]){
			stk.pop();
		}
		if(stk.empty()){
			// cout<<i+1<<endl;
			span[i] = i+1;
		}
		else{
			// cout<<i-stk.top()<<endl;
			span[i] = i-stk.top();
		}
		stk.push(i);
	}
	for(int i=0;i<n;i++)
		cout<<span[i]<<" ";
	cout<<"END"<<endl;
}
void histogram(int arr[], int n){
	stack<int> stk;
	stk.push(0);
	int ans = 0,i=1;
	for(;i < n; i++){
		while(!stk.empty() and arr[stk.top()] > arr[i]){
			int popped = stk.top();
			stk.pop();
			if(stk.empty())
				ans = max(ans,arr[popped]*i);
			else
				ans = max(ans,arr[popped]*(i-stk.top()-1));
		}
		stk.push(i);
	}
	while(!stk.empty()){
		int popped = stk.top();
		stk.pop();
		if(stk.empty())
			ans = max(ans,arr[popped]*i);
		else
			ans = max(ans,arr[popped]*(i-stk.top()-1));
	}
	cout<<ans<<endl;
}
void insert_bottom(stack<int>&s,int d){
	if(s.empty()){
		s.push(d);
		return;
	}
	int top = s.top();
	s.pop();
	insert_bottom(s,d);
	s.push(top);
}
void rec_reverse(stack<int>&s){
	if(s.empty())
		return;
	int d = s.top();
	s.pop();
	rec_reverse(s);
	insert_bottom(s,d);
}
int  main(){
	int n;
	cin>>n;
	stack<int> stk;
	for(int i=0;i<n;i++){
		int d;
		cin>>d;
		stk.push(d);
	}
	rec_reverse(stk);
	while(!stk.empty()){
		cout<<stk.top()<<endl;
		stk.pop();
	}
	return 0;
}
