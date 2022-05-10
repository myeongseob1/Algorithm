#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ve;
int dp[1001];
int answer;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		ve.push_back(t);
	}
	for(int i=0;i<ve.size();i++){
		dp[i] = 1;
	}
	for(int i=1;i<ve.size();i++){
		for(int j=0;j<i;j++){
			if(ve[i]>ve[j]){
				dp[i] = max(dp[j] + 1,dp[i]);
			}
		}
	}
	for(int i=1;i<ve.size();i++){
		answer = max(answer,dp[i]);
	}
	cout<<answer<<"\n";
	return 0;
} 
