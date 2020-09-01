#include <iostream>

using namespace std;

int a[17][17];
int dp[17][17][3];
int n;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	dp[0][1][0] = 1;
	for(int i=0;i<n;i++){
		for(int j=2;j<n;j++){
			if(a[i][j]==0){
				if(j-1>=0) dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
				if(i-1>=0) dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
				if(i-1>=0&&j-1>=0){
					if(a[i-1][j]==0&&a[i][j-1]==0){
						dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
					}
				} 
			}
		}
	}
	cout<<dp[n-1][n-1][0]+dp[n-1][n-1][1]+dp[n-1][n-1][2]<<"\n";
	return 0;
}
