#include <iostream>

using namespace std;
int n;
int dp[31];
int main(void){
	cin>>n;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	dp[4] = 9;
	for(int i=5;i<=n;i++){
		dp[i] = 4*dp[i-4] + 6*dp[i-2];
	}
	cout<<dp[n]<<"\n";
	return 0;
} 
