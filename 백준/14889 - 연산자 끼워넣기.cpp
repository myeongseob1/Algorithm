#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int synergy[21][21];
vector<int> comb;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>synergy[i][j];
		}
	}
	for(int i=0;i<n;i++){
		team.push_back(i);
	}
	for(int i=0;i<n/2;i++){
		comb.push_back(0);
	}
	for(int i=0;i<n/2;i++){
		comb.push_back(1);
	}

	int answer = 987654321;
	do{
		vector<int> team1;
		vector<int> team2;
		for(int i=0;i<comb.size();i++){
			if(comb[i]==0){
				team1.push_back(i);
			}
			else{
				team2.push_back(i);
			}
		}
		int start_score = 0;
		int link_score = 0;
		for(int i=0;i<team1.size();i++){
			for(int j=i;j<team1.size();j++){
				start_score += synergy[team1[i]][team1[j]];
				start_score += synergy[team1[j]][team1[i]];
				link_score += synergy[team2[i]][team2[j]];
				link_score += synergy[team2[j]][team2[i]];

			}
		}
		answer = min(answer,abs(start_score-link_score));
	}while(next_permutation(comb.begin(),comb.end()));
	cout<<answer<<"\n";
	return 0;
}
