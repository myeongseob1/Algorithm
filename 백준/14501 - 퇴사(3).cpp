#include <iostream>

using namespace std;
int n;
int answer = 0;
int plan[16][2];
int dp[16];
int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>plan[i][0]>>plan[i][1];
	}
	for(int i=n;i>=1;i--){
		if(plan[i][0]+i>n+1){
			dp[i] = dp[i+1];
			continue;
		}
		dp[i] = max(plan[i][1]+dp[i+plan[i][0]],dp[i+1]);
	}
	cout<<dp[1]<<"\n";
	return 0;
}
