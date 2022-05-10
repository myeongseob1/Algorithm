#include <iostream>
#include <vector>

using namespace std;

lo n,answer = -987654321;
vector<int> ve;
long long dp[100001];
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		ve.push_back(t);
	}
	for(int i=0;i<n;i++){
		dp[i] = ve[i];
	}
	for(int i=1;i<n;i++){
		dp[i] = max(dp[i-1]+ve[i],ve[i]);
	}
	for(int i=0;i<n;i++){
		answer = max(dp[i],answer);
	}
	cout<<answer<<"\n";
	return 0;
}
