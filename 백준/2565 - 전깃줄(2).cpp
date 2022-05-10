#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int> > ve;
int n,answer;
int dp[101];

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		ve.push_back(make_pair(a,b));
	}	
	sort(ve.begin(),ve.end());
	for(int i=0;i<ve.size();i++){
		dp[i] = 1;
	}
	for(int i=1;i<ve.size();i++){
		for(int j=0;j<i;j++){
			if(ve[i].second>ve[j].second){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	for(int i=0;i<n;i++){
		answer = max(answer,dp[i]);
	}
	cout<<n-answer<<"\n";
	return 0;
}
