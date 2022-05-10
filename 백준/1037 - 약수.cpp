#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> ve;
int answer;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		ve.push_back(t);
	}
	sort(ve.begin(),ve.end());
	
	cout<<ve.front() * ve.back()<<"\n";
	return 0;
}
