#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int map[51][51];
bool visit[51][51];
int dist[51][51];
int n,m;
vector<pair<int,int> > vir;
vector<pair<int,int> > activ;
int answer = 987654321;

void init(){
	for(int i=0;i<51;i++){
		for(int j=0;j<51;j++){
			visit[i][j] = false;
			dist[i][j] = 0;
		}
	}
}

void dfs(int iter){
	if(activ.size()==m){
		queue<pair<int,int> > q;
		init();
		for(int i=0;i<activ.size();i++){
			q.push(make_pair(activ[i].first,activ[i].second));
			visit[activ[i].first][activ[i].second] = true;
		}
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(nx>=0&&nx<n&&ny>=0&&ny<n){
					if(map[nx][ny]!=1&&visit[nx][ny]==false){
						visit[nx][ny] = true;
						dist[nx][ny] = dist[x][y] + 1;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
		int rslt = 0;
		bool possible_flag = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j]==0&&visit[i][j]==true) rslt = max(rslt,dist[i][j]);
				if(map[i][j]==0&&visit[i][j]==false) possible_flag = false;
			}
		}
		if(possible_flag) answer = min(answer,rslt);
		return;
	}
	if(iter>vir.size()-1){
		return;
	}
	activ.push_back(vir[iter]);
	dfs(iter+1);
	activ.pop_back();
	dfs(iter+1);
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			if(map[i][j]==2){
				vir.push_back(make_pair(i,j));
			}
		}
	}
	dfs(0); 
	if(answer==987654321){
		answer = -1;
	}
	cout<<answer<<"\n";
	return 0;
}
