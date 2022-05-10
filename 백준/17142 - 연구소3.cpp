#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
int map[51][51];
bool visit[51][51];
int dist[51][51];

vector<pair<int,int> > virus;
vector<pair<int,int> > active;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int answer = 987654321;
int tmp;
void init(){
	for(int i=0;i<51;i++){
		for(int j=0;j<51;j++){
			visit[i][j] = false;
			dist[i][j] = 0;
		}
	}
	tmp = 0;
}
void dfs(int iter,int num){
	if(num==m){
		init();
		queue<pair<int,int> > q;
		for(int i=0;i<active.size();i++){
			q.push(make_pair(active[i].first,active[i].second));
			visit[active[i].first][active[i].second] = true;
			
		}
		
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(nx>=0&&nx<n&&ny>=0&&ny<n){
					if(visit[nx][ny]==false&&map[nx][ny]!=1){
						visit[nx][ny] = true;
						dist[nx][ny] = dist[x][y] + 1;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
		bool sper = false;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j]==0&&visit[i][j]==true){
					tmp = max(tmp,dist[i][j]);
				}
				if(map[i][j]==0&&visit[i][j]==false){
					sper = true;
				}
			}
		}
		if(sper==false)
		answer = min(answer,tmp);
		return;
	}
	if(iter > virus.size()-1) return;
	active.push_back(virus[iter]);
	dfs(iter+1,num+1);
	active.pop_back();
	dfs(iter+1,num);
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			if(map[i][j]==2){
				virus.push_back(make_pair(i,j));
			}
		}
	}
	dfs(0,0);
	if(answer==987654321){
		answer = -1;
	}
	cout<<answer<<"\n";
	return 0;
}
