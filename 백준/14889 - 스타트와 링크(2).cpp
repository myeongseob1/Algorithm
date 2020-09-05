#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int a[22][22];
vector<int> team;
vector<int> tmp;
int answer = 2147000000;
int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		team.push_back(i);
	}
	for(int i=0;i<team.size()/2;i++){
		tmp.push_back(0);
	}
	for(int i=team.size()/2;i<team.size();i++){
		tmp.push_back(1);
	}	
	do{
		int synergy1 = 0;
		int synergy2 = 0;
		vector<int> start;
		vector<int> link;
		for(int i=0;i<tmp.size();i++){
			if(tmp[i]==0){
				start.push_back(team[i]);
			}
			else{
				link.push_back(team[i]);
			}
		}
		for(int i=0;i<n/2;i++){
			for(int j=i;j<n/2;j++){
				synergy1 += a[start[i]][start[j]];
				synergy1 += a[start[j]][start[i]];
				synergy2 += a[link[i]][link[j]];
				synergy2 += a[link[j]][link[i]];
			}
		}
		answer = min(answer,abs(synergy1-synergy2));
	}while(next_permutation(tmp.begin(),tmp.end()));
	cout<<answer<<"\n";
	return 0;
}
