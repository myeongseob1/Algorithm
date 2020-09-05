#include <iostream>

using namespace std;
int n,m;
int a[1001][1001];
int dp[1001][1001];
int answer;
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&a[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i+1][j+1] = a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i-1][j]!=0&&dp[i-1][j-1]!=0&&dp[i][j-1]!=0&&dp[i][j]!=0){
				dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
			}
			answer = max(dp[i][j],answer);
		}
	}
	cout<<answer*answer<<"\n";	
	return 0;
}
