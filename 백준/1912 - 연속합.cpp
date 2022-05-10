#include <iostream>

using namespace std;

long long int dp[100001];
long long int num[100001];
int n;

int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}	
	long long int answer = -9999999999;
	for(int i=1;i<=n;i++){
		dp[i] = max(dp[i-1]+num[i],num[i]);
		answer = max(answer,dp[i]);
	}
	cout<<answer<<"\n";
	return 0;
}
