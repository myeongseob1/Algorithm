#include <iostream>
#include <cmath>
using namespace std;
int dp[50001];
int n;
int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		dp[i] = 9999;
	}
	
	for(int i=1;i<=n;i++){
		if((int)sqrt(i)*sqrt(i)==i){
			dp[i] = 1;
			continue;
		}
		for(int j=sqrt(i);j>=0;j--){
			dp[i] = min(dp[i-j*j] + 1, dp[i]);
		}
	}
	cout<<dp[n]<<"\n";
	return 0;
}
