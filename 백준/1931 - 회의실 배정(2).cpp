#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int> > ve;

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		ve.push_back(make_pair(b,a));
	}
	sort(ve.begin(),ve.end());
	int answer = 1;
	int hyun = ve[0].first;
	for(int i=1;i<ve.size();i++){
		if(hyun<=ve[i].second){
			answer++;
			hyun = ve[i].first;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
