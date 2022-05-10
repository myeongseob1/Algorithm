#include <iostream>

using namespace std;

long long int triangle[501][501];
long long int dp[501][501];
int n;

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<i+1;j++){
			cin>>triangle[i][j];
		}
	}
	dp[0][0] = triangle[0][0];
	dp[1][0] = triangle[0][0] + triangle[1][0];
	dp[1][1] = triangle[0][0] + triangle[1][1];
	
	for(int i=2;i<n;i++){
		dp[i][0] = dp[i-1][0] + triangle[i][0];
		for(int j=1;j<i+1;j++){
			dp[i][j] = max(dp[i-1][j] + triangle[i][j],dp[i-1][j-1] + triangle[i][j]);
		}
	}
	long long int answer = 0;
	for(int i=0;i<n;i++){
		answer = max(dp[n-1][i],answer);
	}
	cout<<answer<<"\n";
	
	return 0;
}
