#include <iostream>
#include <queue>
#include <algorithm> 
using namespace std;


int map[1001][1001];
int dp[1001][1001];

int n,m;

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			dp[i][j] = map[i][j];
		}
	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i>0 && j>0)dp[i][j] = max(dp[i-1][j-1] + map[i][j] , dp[i][j]);
			if(j>0) dp[i][j] = max(dp[i][j-1] + map[i][j] , dp[i][j]);
			if(i>0)dp[i][j] = max(dp[i-1][j]+map[i][j],dp[i][j]);
		}
	}
	cout<<dp[n-1][m-1]<<"\n";
	return 0;
}
