#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

vector<pair<int,int> > v;
int n;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cout<<v[i].first<<" "<<v[i].second<<"\n";
	}
	
	return 0;
}
