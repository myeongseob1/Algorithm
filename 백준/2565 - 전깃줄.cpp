#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int> > elec;
int dp[101];
int n;

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		elec.push_back(make_pair(a,b));
		dp[i] = 1;
	}
	sort(elec.begin(),elec.end());
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(elec[i].second>elec[j].second){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	int answer = 0;
	for(int i=0;i<n;i++){
		answer = max(answer,dp[i]);
	}
	cout<<n-answer<<"\n";
	return 0;
}
