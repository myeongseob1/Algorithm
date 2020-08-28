#include <iostream>

using namespace std;
int t,n;
int main(void){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int a[2][100001];
		int dp[2][100001];

		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		dp[0][0] = a[0][0];
		dp[1][0] = a[1][0];
		
		dp[0][1] = dp[1][0] + a[1][1];
		dp[1][1] = dp[0][0] + a[0][1];
		
		for(int i=1;i<=n-1;i++){
			dp[0][i] = max(dp[1][i-1] + a[0][i],dp[0][i-2] + a[0][i] );
			dp[0][i] = max(dp[0][i],dp[1][i-2] + a[0][i]);
			dp[1][i] = max(dp[0][i-1] + a[1][i],dp[1][i-2] + a[1][i] );
			dp[1][i] = max(dp[1][i],dp[0][i-2] + a[1][i] );
 
		}
		cout<<max(dp[0][n-1],dp[1][n-1])<<"\n";		
	}
	
	return 0;
}
