#include <iostream>

using namespace std;

int dp[1001][1001];
int n,m;
string map[1001];
int answer;
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i-1][j-1]=='1'){
				dp[i][j] = 1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]!=0){
				dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) +1;
			}
			answer = max(dp[i][j],answer);
		}
	}	

	cout<<answer*answer<<"\n";
	return 0;
}
