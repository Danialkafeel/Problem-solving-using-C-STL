#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp[101][101];
int mixtures(int* arr, int n){
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			dp[i][j] = -1;
			if(i == j)
				dp[i][i] = 0;
		}
	}
	int cum_sum[n];
	cum_sum[0] = arr[0];
	for(int i=1;i<n;i++)
		cum_sum[i] = cum_sum[i-1] + arr[i];

	int jj = 0;
	while(jj++ < n){
		for(int i=0,j=jj; (i<n and j<n); i++, j++){
			int temp = INT_MAX;
			for(int k = i;k<j;k++){
				int cost = ((cum_sum[k]-cum_sum[i] + arr[i])%100) * ((cum_sum[j]-cum_sum[k+1] + arr[k+1])%100);
				temp = min(temp,dp[i][k]+dp[k+1][j] + cost);
			}
			dp[i][j] = temp;
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return dp[0][n-1];
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<mixtures(arr,n)<<endl;
	return 0;
}