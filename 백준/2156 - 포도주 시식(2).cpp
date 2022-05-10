#include <iostream>

using namespace std;
int dp[10001];
int drink[10001];
int n;
int answer;
int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>drink[i];
	}
	dp[1] = drink[1];
	dp[2] = drink[1] + drink[2];
	for(int i=3;i<=n;i++){
		dp[i] = max(dp[i-1],dp[i-3]+drink[i-1]+drink[i]);
		dp[i] = max(dp[i],dp[i-2]+drink[i]);
	}
	cout<<dp[n]<<"\n";
	return 0;
}
