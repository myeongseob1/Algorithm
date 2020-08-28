#include <iostream>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<pair<int,int> > p;
int answer;
int start;

int main(void){
	int p;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>p;
			start = 10*start+ p; 
		}
	}
	dfs(p[0].first,p[0].second);
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			if(a[i][j]!=3*i+j+1){
				answer = -1;
			}
		}
	}
	if(a[2][2]!=0){
		answer = -1;
	}
	cout<<answer<<"\n";
	return 0;
}
