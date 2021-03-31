#include<bits/stdc++.h>
using namespace std;

int min_coinsBU(int* coins, int n,int sum){
	int dp[sum+1];
	dp[0] = 0;
	for(int i=1;i<=sum;i++){
		int mini = INT_MAX;
		for(int j=0;j<n;j++){
			if(i-coins[j] >= 0){
				mini = min(mini,dp[i-coins[j]]);
			}
		}
		dp[i] = mini+1;
		cout<<"dp["<<i<<"] = "<<mini+1<<endl;
	}
	return dp[sum];
}
int min_coinsTD(int *coins,int n,int sum,int dp[]){
	if(sum == 0)
		return 0;
	int mini = INT_MAX;
	cout<<"sum = "<<sum<<endl;
	for(int i=0;i<n;i++){
		if(sum-coins[i] >= 0){
			if(dp[sum-coins[i]] != -1)
				mini = min(mini,dp[sum-coins[i]]);
			else
				mini = min(mini,min_coinsTD(coins,n,sum-coins[i],dp));
		}
	}

	cout<<"dp["<<sum<<"] = "<<mini+1<<endl;
	return dp[sum] = mini+1;
}
void wines_problem(){
	int arr[] = {2,3,5,1,4};
	int n = sizeof(arr)/ sizeof(int);
	int dp[n][n] = {0};
	for(int i=0;i<n;i++)
		dp[i][i] = n*arr[i];
	for(int k = 1;k<n;k++){
		for(int i=0,j=k;i<n and j<n; i++,j++){
			// cout<<"i,j = "<<i<<" "<<j<<endl;
			int year = n-j+i;
			dp[i][j] = max(arr[i]*year+dp[i+1][j], arr[j]*year+dp[i][j-1]);
		}
		// cout<<"--------------------------\n";
	}
	cout<<dp[0][n-1]<<endl;
}

int main(){
	// int coins[] = {1,7,10};
	// int n = sizeof(coins)/ sizeof(int);
	// int sum;
	// cin>>sum;
	// cout<<min_coinsBU(coins,n,sum)<<endl;
	// int dp[sum+1];
	// for(int i=0;i<sum+1;i++)
	// 	dp[i] = -1;
	// cout<<min_coinsTD(coins,n,sum,dp)<<endl;
	wines_problem();
}