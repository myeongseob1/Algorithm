#include <iostream>

using namespace std;

int dp[1001];
int num[1001];
int n;

int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		dp[i] = 1;
	}
	for(int i=n;i>=1;i--){
		for(int j=n;j>i;j--){
			if(num[i] > num[j])dp[i] = max(dp[j]+1,dp[i]);
		}
	}
	int answer = 0;
	for(int i=1;i<=n;i++){
		answer = max(answer,dp[i]);
	}
	cout<<answer<<"\n";
	return 0;
}
