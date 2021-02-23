#include<bits/stdc++.h>
using namespace std;
int rounds_LoadBalancing(int* arr, int n){
	int cumm[n];
	cumm[0] = arr[0];
	for(int i=1;i<n;i++)
		cumm[i] = arr[i] + cumm[i-1];
	int jobs = cumm[n-1]/n;
	if((1.0*cumm[n-1]/n) != jobs)
		return -1;
	int rounds = 0;
	for(int i=0;i<n-1;i++){
		int rounds_with_curr_split = abs((jobs*(i+1)) - cumm[i]);
		// cout<<"i = "<<i<<":"<<rounds_with_curr_split<<endl;
		rounds = max(rounds,rounds_with_curr_split);
	}
	return rounds;
}
int defense_kingdom(int x[],int y[],int w, int h,int n){
	if(n == 0){
		return w*h;
	}
	sort(x,x+n);
	sort(y,y+n);
	vector<int> dx,dy;
	dx.push_back(x[0]-1);
	dy.push_back(y[0]-1);
	for(int i=1;i<n;i++){
		dx.push_back(x[i]-x[i-1]-1);
		dy.push_back(y[i]-y[i-1]-1);
	}
	dx.push_back(w-x[n-1]);
	dy.push_back(h-y[n-1]);
	return (*max_element(dx.begin(),dx.end()))*(*max_element(dy.begin(),dy.end()));
}

int main(){
	// int n;
	// cin>>n;
	// while(n != -1){
	// 	int arr[n];
	// 	for(int i=0;i<n;i++)
	// 		cin>>arr[i];
	// 	cout<<rounds_LoadBalancing(arr,n)<<endl;
	// 	cin>>n;
	// }
	int t;
	cin>>t;
	while(t--){
		int w,h, n;
		cin>>w>>h>>n;
		int x[n], y[n];
		for(int i=0;i<n;i++)
			cin>>x[i]>>y[i];
		cout<<defense_kingdom(x,y,w,h,n)<<endl;
	}
}