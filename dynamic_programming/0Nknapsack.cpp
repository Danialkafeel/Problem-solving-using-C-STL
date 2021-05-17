#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ** dp;

int KS_helper(int n, int cap, vector<int> &wt, vector<int> &val){
	if(dp[n][cap] != -1)
		return dp[n][cap];
	if(cap < wt[n-1])
		return dp[n][cap] = KS_helper(n-1,cap,wt,val);
	return dp[n][cap] = max(val[n-1]+KS_helper(n-1,cap-wt[n-1], wt, val), KS_helper(n-1,cap, wt, val));
}
void KS(int n,int cap, vector<int> &wt, vector<int> &val){
	for(int i=0;i<n;i++){
		for(int j=0;j<(cap/wt[i]);j++){
			wt.push_back(wt[i]);
			val.push_back(val[i]);
		}
	}
	// cout<<"yo";
	// cout<<wt.size()<<endl;

	dp = new int*[wt.size()+1];
	for(int i=0; i<=wt.size(); i++){
		dp[i] = new int[cap+1];
		for(int j=0;j<=cap;j++){
			if(i == 0 or j==0)
				dp[i][j] = 0;
			else
				dp[i][j] = -1;
		}
	}
	KS_helper(wt.size(),cap, wt, val);
}


int optimizedKS(int n,int cap, vector<int> &wt, vector<int> &val){
	int DP[cap+1];
	DP[0] = 0;
	for(int i=1;i<=cap;i++){
		DP[i] = -1;
		for(int j=0; j<n; j++){
			if(i-wt[j] >= 0){
				DP[i] = max(DP[i], val[j] + DP[i-wt[j]]);
			}
		}
	}
	return DP[cap];
}

int main(){
	int n,cap;
	cin>>n>>cap;
	vector<int> wt(n), val(n);
	for(int i=0; i<n; i++){
		cin>>wt[i];
	}
	for(int i=0; i<n; i++){
		cin>>val[i];
	}

	// KS(n,cap,wt,val);
	// cout<<dp[wt.size()][cap]<<endl;

	cout<<optimizedKS(n,cap,wt,val)<<endl;

	return 0;
}