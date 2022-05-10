#include <iostream>

using namespace std;
int n,k;
int w[101];
int v[101];
int dp[101][100011];
int main(void){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>v[i];		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			dp[i][j] = dp[i-1][j];
			if(j-w[i]>=0) dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
		}
	}
	cout<<dp[n][k]<<"\n";
	return 0;
}
