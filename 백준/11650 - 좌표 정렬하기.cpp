#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int> > ve;
int n;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		ve.push_back(make_pair(b,a));
	}
	sort(ve.begin(),ve.end());
	for(int i=0;i<n;i++){
		cout<<ve[i].second<<" "<<ve[i].first<<"\n";
	}
	return 0;
}
