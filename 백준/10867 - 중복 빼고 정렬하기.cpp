#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> ve;

int main(void){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);	

	cin>>n;	
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		ve.push_back(t);
	}
	sort(ve.begin(),ve.end());
	ve.erase(unique(ve.begin(),ve.end()),ve.end());
	for(int i=0;i<ve.size();i++){
		cout<<ve[i]<<" ";
	}
	return 0;
}
