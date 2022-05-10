#include <iostream>
#include <vector>

using namespace std;
int n;
int rank1[51];
vector<pair<int,int> > v;

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
		rank1[i]++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				if(v[i].first<v[j].first&&v[i].second<v[j].second){
					rank1[i]++;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<rank1[i]<<" ";
	}
	return 0;
}
