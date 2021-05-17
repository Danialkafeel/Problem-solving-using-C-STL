#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp[200][200][200];

void LCS3(string s1, string s2, string s3){
	for(int i=0;i<=s1.size();i++){
		for(int j=0;j<=s2.size();j++){
			for(int k = 0;k <= s3.size();k++){
				if(i==0 or j==0 or k==0)
					dp[i][j][k] = 0;
				else{
					if(s1[i-1] == s2[j-1] and s2[j-1] == s3[k-1]){
						// cout<<"i,j,k = "<<i<<" "<<j<<" "<<k<<endl;
						dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
					}
					else
						dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k], dp[i][j][k-1]));
				}
			}
		}
	}
}

int main(){
	string s1, s2, s3;
	cin>>s1>>s2>>s3;

	// int** dp;
	// dp = new int**[s1.size()+1];
	// for(int i=0;i<s1.size()+1;i++){
	// 	dp[i] = new int*[s2.size()+1];
	// 	for(int j=0;j<s2.size();j++)
	// 		dp[i][j] = new int[s3.size()+1];
	// }

	LCS3(s1,s2,s3);
	// cout<<"yo\n";
	// cout<<sizeof(dp[0])/sizeof(int)<<endl;
	cout<<dp[s1.size()][s2.size()][s3.size()]<<endl;
	return 0;
}