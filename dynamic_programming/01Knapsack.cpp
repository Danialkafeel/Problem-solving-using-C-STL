#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1001][1001];

ll KS_TopDown(int n, int c, ll size[], ll value[]){
	if(dp[n][c] != -1)
		return dp[n][c];
	if(size[n-1] > c)
		return dp[n][c] = KS_TopDown(n-1,c,size,value);
	return dp[n][c] = max(value[n-1] + KS_TopDown(n-1,c-size[n-1],size,value), KS_TopDown(n-1,c,size,value));
}

void KS_BottomUp(int n, int c, ll size[], ll value[]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c;j++){
			if(size[i-1] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(value[i-1]+dp[i-1][j-size[i-1]], dp[i-1][j]);
		}
	}
}

int main(){
	int n, capacity;
	cin>>n>>capacity;
	ll size[n], value[n];
	for(int i=0;i<n;i++)
		cin>>size[i];
	for(int i=0;i<n;i++)
		cin>>value[i];
	for(int i=0;i<1001;i++){
		for(int j=0;j<1001;j++){
			dp[i][j] = -1;
			if(i == 0 or j == 0)
				dp[i][j] = 0;
		}
	}

	// KS_TopDown(n,capacity,size,value);
	KS_BottomUp(n,capacity,size,value);

	cout<<"\n----------------------------------\n";
	for(int i=0;i<=n;i++){
		for (int j = 0; j <= capacity; ++j)
			cout<<dp[i][j]<<"\t";
		cout<<endl;
	}

	cout<<dp[n][capacity]<<endl;
	return 0;
}