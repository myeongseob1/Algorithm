#include <iostream>

using namespace std;
long long int dp[101][10];
int n;
int main(void){
	cin>>n;
	for(int i=1;i<=9;i++){
		dp[1][i] = 1;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=9;j++){
			if(j-1>=0) dp[i][j] += dp[i-1][j-1];
			if(j+1<=9) dp[i][j] += dp[i-1][j+1];
			dp[i][j] %= 1000000000;
		}
	}
	long long int answer = 0;
	for(int i=0;i<=9;i++){
		answer += dp[n][i];
		answer %= 1000000000;
	}
	cout<<answer<<"\n";
	return 0;
}
