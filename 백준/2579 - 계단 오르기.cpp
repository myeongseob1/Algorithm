#include <iostream>

using namespace std;

long long int dp[301][2];
long long int stair[301];
int n;

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>stair[i];
	}	
	dp[0][0] = stair[0];
	dp[1][0] = stair[1];
	dp[1][1] = stair[0] + stair[1]; 
	for(int i=2;i<n;i++){
		dp[i][0] = max(dp[i-2][0],dp[i-2][1]) + stair[i];
		dp[i][1] = dp[i-1][0] + stair[i];
		
	}
	cout<<max(dp[n-1][0],dp[n-1][1])<<"\n";
	return 0;
}
