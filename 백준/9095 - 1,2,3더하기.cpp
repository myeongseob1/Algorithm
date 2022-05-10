#include <iostream> 

using namespace std;

int dp[12];
int n;
int main(void){
	cin>>n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i=4;i<=11;i++){
		dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
	}
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		cout<<dp[t]<<"\n";
	}
	
	return 0;
}
