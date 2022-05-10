#include <iostream>
#include <vector>
using namespace std;
int dp[1002][1002];
string dp2[1002][1002];
int main(void){
	string a,b;
	cin>>a>>b;
	for(int i=1;i<=a.size();i++){
		for(int j=1;j<=b.size();j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1] +1;
				dp2[i][j] = dp2[i-1][j-1];
				dp2[i][j].push_back(a[i-1]);
			}else{
				if(dp[i-1][j]>dp[i][j-1]){
					dp[i][j] = dp[i-1][j];
					dp2[i][j] = dp2[i-1][j]; 				
				}else{
					dp[i][j] = dp[i][j-1];
					dp2[i][j] = dp2[i][j-1]; 									
				}
			}
		}
	}
	for(int i=1;i<=a.size();i++){
		for(int j=1;j<=b.size();j++){
			cout<<dp2[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<dp[a.size()][b.size()]<<"\n"<<dp2[a.size()][b.size()];
	return 0;
}
