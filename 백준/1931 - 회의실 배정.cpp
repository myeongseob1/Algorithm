#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int n;
vector<pair<int,int> > ve;
bool compare(pair<int,int> a, pair<int,int> b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		ve.push_back(make_pair(a,b));
	}
	sort(ve.begin(),ve.end(),compare);
	int answer = 1;
	int hyun = ve[0].second;
	for(int i=1;i<ve.size();i++){
		if(ve[i].first>=hyun){
			hyun = ve[i].second;
			answer++;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
