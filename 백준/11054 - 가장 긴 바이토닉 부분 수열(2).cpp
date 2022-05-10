#include <iostream>
#include <vector>

using namespace std;

int n,answer;
vector<int> ve;
int dp1[1001];
int dp2[1001];
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		ve.push_back(t);
	}
	for(int i=0;i<n;i++){
		dp1[i] = 1;
		dp2[i] = 1;
	}
	for(int i=1;i<ve.size();i++){
		for(int j=0;j<i;j++){
			if(ve[i]>ve[j]){
				dp1[i] = max(dp1[j]+1,dp1[i]);
			}

		}
	}
	int t = ve.size()-1;
	for(int i=1;i<ve.size();i++){
		for(int j=0;j<i;j++){
			if(ve[t-i]>ve[t-j]){
				dp2[t-i] = max(dp2[t-j]+1,dp2[t-i]);
			}

		}
	}

	for(int i=0;i<n;i++){
		answer = max(answer,dp1[i]+dp2[i]);
	}
	cout<<answer-1<<"\n";
	return 0;
}
