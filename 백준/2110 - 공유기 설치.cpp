#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,c;
vector<int> ve;

int main(void){
	cin>>n>>c;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		ve.push_back(t);
	}
	sort(ve.begin(),ve.end());
	for(int i=0;i<n;i++){
		cout<<ve[i]<<" ";
	}
	return 0;
}
