#include <iostream>

using namespace std;
int n;
int score[301];
int dp[301][2];
int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>score[i];
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = score[1];
	dp[1][1] = score[1];
	dp[2][0] = score[2];
	dp[2][1] = dp[1][0] + score[2];
	
	for(int i=3;i<=n;i++){
		dp[i][0] = max(dp[i-2][0] +score[i], dp[i-2][1] + score[i]);
		dp[i][1] = dp[i-1][0] + score[i];
	}  
	cout<<max(dp[n][0],dp[n][1])<<"\n";
	return 0;
}
