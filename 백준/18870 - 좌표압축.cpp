#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> ve;
vector<int> vec;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		ve.push_back(a);
		vec.push_back(a);
	}
	sort(ve.begin(),ve.end());
	ve.erase(unique(ve.begin(),ve.end()),ve.end());	
	for(int i=0;i<vec.size();i++){
		cout<<lower_bound(ve.begin(),ve.end(),vec[i])-ve.begin()<<" ";
	}
	return 0;
}
