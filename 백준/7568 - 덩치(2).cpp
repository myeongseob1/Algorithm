#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int> > ve;
int n;
int rankl[51];
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		ve.push_back(make_pair(a,b));
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(ve[i].first>ve[j].first&&ve[i].second>ve[j].second&&i!=j){
				rankl[j]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<rankl[i]+1<<" ";
	}
	return 0;
}
