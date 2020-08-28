#include <iostream>

using namespace std;
int n;
long long int dp[100001][4];
int main(void){
	cin>>n;
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		for(int j=4;j<=a;j++){
			dp[j][1] = (dp[j-1][2] + dp[j-1][3])%1000000009;
			dp[j][2] = (dp[j-2][1] + dp[j-2][3])%1000000009;
			dp[j][3] = (dp[j-3][1] + dp[j-3][2])%1000000009;
		}
		cout<<(dp[a][1]+dp[a][2]+dp[a][3])%1000000009<<"\n";
	}
	
	return 0;
}
