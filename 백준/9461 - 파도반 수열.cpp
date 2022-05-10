#include <iostream>

using namespace std;

long long int dp[101];
int n;
int main(void){
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for(int i=4;i<=100;i++){
		dp[i] = dp[i-3]+dp[i-2];
	}

	cin>>n;
	
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		cout<<dp[a]<<"\n";
	}
	return 0;
} 
