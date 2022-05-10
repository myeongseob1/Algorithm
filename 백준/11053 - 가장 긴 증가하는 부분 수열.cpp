#include <iostream>

using namespace std;
int n;
int lan[1001];
int dp[1001];
int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lan[i];
	}
	for(int i=1;i<=n;i++){
		dp[i] = 1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(lan[i]>lan[j]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	int answer = 0;
	for(int i=1;i<=n;i++){
		answer = max(answer,dp[i]);
	}
	cout<<answer<<"\n";
	return 0;
}
