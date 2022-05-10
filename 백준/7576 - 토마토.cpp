#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool visit[1001][1001];
int map[1001][1001];
int dist[1001][1001];
int n,m,answer;
queue<pair<int,int> > q;
int main(void){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(map[i][j]==1){
				q.push(make_pair(i,j));
				visit[i][j] = true;
			}
		}
	}
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(!visit[nx][ny]&&map[nx][ny]==0){
					visit[nx][ny] = true;
					map[nx][ny] = 1;
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			answer = max(answer,dist[i][j]);
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!visit[i][j]&&map[i][j]==0){
				answer = -1;
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
