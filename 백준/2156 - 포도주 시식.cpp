#include <iostream>

using namespace std;

long long int dp[10001];
long long int cup[10001];
int n;

int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cup[i];
	}
	dp[0] = 0;
	dp[1] = cup[1];
	dp[2] = cup[1]+cup[2]; 
	for(int i=3;i<=n;i++){
		dp[i] = max(dp[i-3]+cup[i-1]+cup[i],dp[i-1]);
		dp[i] = max(dp[i],dp[i-2]+cup[i]);
	}
	cout<<dp[n]<<"\n";
	return 0;
}

