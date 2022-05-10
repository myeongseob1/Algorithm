#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> ve;
int ye; 
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		ve.push_back(t);
	}
	cin>>ye;
	int sm = 0;
	int idx = 0;
	sort(ve.begin(),ve.end());
	for(int i=0;i<ve.size();i++){
		sm += ve[i];
	}
	for(int i=0;i<ve.size();i++){
		if(ye/ve.size()>=ve[i]){
			idx = i;
		}
	}

	if(ye>=sm){
		cout<<ve[ve.size()-1]<<"\n";
		return 0;
	}
	for(int i=0;i<=idx;i++){
		ye -= ve[i];
	}
	cout<<ye/(n-idx-1)<<"\n";
	return 0;
}
