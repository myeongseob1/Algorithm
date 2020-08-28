#include <iostream>

using namespace std;
long long int dp[1000001];
int n;
int main(void){
	cin>>n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		for(int j=4;j<=t;j++){
			dp[j] = (dp[j-1] + dp[j-2] + dp[j-3])%1000000009;
		}
		cout<<dp[t]<<"\n";
	}
	
	return 0;
}
