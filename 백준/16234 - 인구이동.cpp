#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int answer;
int n,l,r;
int map[51][51];
bool visit[51][51];
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0}; 
bool ending = false;
void init(){
	for(int i=0;i<51;i++){
		for(int j=0;j<51;j++){
			visit[i][j] = false;
		}
	}
	ending = false;
}
bool ending_game(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x = i;
			int y = j;
			for(int k=0;k<4;k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx>=0&&nx<n&&ny>=0&&ny<n){
					if(abs(map[nx][ny]-map[x][y])>=l&&abs(map[nx][ny]-map[x][y])<=r){
						return false;
					}
					
				}
			}
		}
	}
	return true;
}
void bfs(int i,int j){
	queue<pair<int,int> >  q;
	vector<pair<int,int> > p;
	q.push(make_pair(i,j));
	p.push_back(make_pair(i,j));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<n){
				if(abs(map[nx][ny]-map[x][y])>=l&&abs(map[nx][ny]-map[x][y])<=r&&visit[nx][ny]==false){
					visit[nx][ny] = true;
					p.push_back(make_pair(nx,ny));
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	if(p.size()>1){
		ending = true;
		int sum = 0;
		for(int i=0;i<p.size();i++){
			sum += map[p[i].first][p[i].second];
		}
		for(int i=0;i<p.size();i++){
			map[p[i].first][p[i].second] = sum/p.size();
		}
	}
	
}

int main(void){
	cin>>n>>l>>r;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	while(1){
		init();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(visit[i][j]==false){
					visit[i][j] = true;
					bfs(i,j);
				}
			}
		}
		if(ending==true){
			answer++;
		}
		if(ending_game()==true){
			break;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
