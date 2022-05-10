#include <iostream>

using namespace std;
int n;
long long int dp[1000001];
int main(void){
	cin>>n;
	for(int i=2;i<=n;i++){
		dp[i] = 98765432112;
	}
	for(int i=2;i<=n;i++){
		if(i%3==0){
			dp[i] = min(dp[i],dp[i/3] + 1);
		}
		if(i%2==0){
			dp[i] = min(dp[i],dp[i/2] + 1);			
		}
		dp[i] = min(dp[i],dp[i-1]+1);					
	}
	cout<<dp[n]<<"\n";
	return 0;
}
