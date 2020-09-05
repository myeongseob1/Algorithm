#include <iostream>

using namespace std;

long long int dp[91];
int n;
int main(void){
	cin>>n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for(int i=3;i<=n;i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	cout<<dp[n]<<"\n";
	return 0;
}
