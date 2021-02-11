#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first < b.first;
}

void print(pair<int,int> x){
	cout<<"("<<x.first<<","<<x.second<<")";
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int len;
		cin>>len;
		pair<int,int> interv[len];
		for(int i=0;i<len;i++){
			cin>>interv[i].first>>interv[i].second;
		}
		sort(interv,interv+len,cmp);
		stack<pair<int,int>> stk;
		stk.push(interv[0]);
		for(int i=1;i<len;i++){
			pair<int,int> temp = stk.top();
			// print(interv[i]);
			if(interv[i].first>= temp.first && interv[i].first < temp.second){
				// cout<<"Merged ";
				// print(temp);
				// cout<<" with ";
				stk.pop();
				temp.second = min(interv[i].second,temp.second);
				stk.push(temp);
			}
			else{
				stk.push(interv[i]);
				// cout<<"Pushed ";
				// print(interv[i]);
			}
			// cout<<endl;
		}
		cout<<stk.size()<<endl;
	}
	return 0;
}