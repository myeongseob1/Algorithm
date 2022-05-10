#include <iostream>
using namespace std;

int dp[101][101];
long long int vis[101][101];
int n;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>dp[i][j];
		}
	}
	vis[0][0] =1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==n-1&&j==n-1){
				cout<<vis[n-1][n-1]<<"\n";
				return 0;
			}
			if(dp[i][j]!=0&&vis[i][j]!=0){
				int nx = i + dp[i][j];
				int ny = j + dp[i][j];
				if(nx<n){
					vis[nx][j] += vis[i][j]; 
				}
				if(ny<n){
					vis[i][ny] += vis[i][j];
				}
			}
			
		}
	}
	return 0;
}
