#include <iostream>

using namespace std;
string a,b;
int dp[1001][1001];
string answer = "";
int main(void){
	cin>>a>>b;
	for(int i=1;i<=a.size();i++){
		for(int j=1;j<=b.size();j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				answer.push_back(a[i-1]);
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[a.size()][b.size()]<<"\n"<<answer<<"\n";
	return 0;
}
