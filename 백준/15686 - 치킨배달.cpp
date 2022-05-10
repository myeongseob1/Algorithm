#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n,m;
int map[51][51];
vector<pair<int,int> > chicken;
vector<pair<int,int> > it;
vector<pair<int,int> > house;

int answer = 987654321;
void dfs(int iter,int pick){
	if(pick==m){
		int result = 0;
		for(int i=0;i<house.size();i++){
			int dist = 987654321;
			for(int j=0;j<it.size();j++){
				dist = min(dist,abs(it[j].first-house[i].first)+abs(it[j].second-house[i].second));
			}
			result += dist;
			dist = 987654321;
		}
		answer = min(answer,result);
		return;
	}
	if(iter>chicken.size()-1) return;
	it.push_back(chicken[iter]);
	dfs(iter+1,pick+1);
	it.pop_back();
	dfs(iter+1,pick);	
}
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			if(map[i][j]==2){
				chicken.push_back(make_pair(i,j));
				
			}
			if(map[i][j]==1){
				house.push_back(make_pair(i,j));
			}
		}
	}
	dfs(0,0);
	cout<<answer<<"\n";
	return 0;
}
