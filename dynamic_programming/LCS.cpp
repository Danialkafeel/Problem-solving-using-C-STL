#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	int n,m;
	n = a.size();
	m = b.size();

	int dp[n+1][m+1];

	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
 	}
	for(int i=0;i<=m;i++){
		dp[0][i] = 0;
 	}

 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=m;j++){
 			if(a[i-1] == b[j-1]){
 				dp[i][j] = dp[i-1][j-1] + 1;
 			}
 			else{
 				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
 			}
 		}
 	}
 	for(int i=0;i<=n;i++){
 		for (int j = 0; j <= m; ++j){
 			cout<<dp[i][j]<<" ";
 		}
 		cout<<endl;
 	}
	string ans = "";
 	int i = n;
 	int j = m;
 	while(i > 0 and j > 0){
 		if(dp[i][j] == dp[i-1][j]){
 			i--;
 		}
 		else if(dp[i][j] == dp[i][j-1])
 			j--;
 		else{
 			ans += a[i-1];
 			i--; j--;
 		}
 	}
 	string ans2(ans.rbegin(), ans.rend());
 	cout<<dp[n][m]<<" "<<ans2<<endl;
	return 0;
}