#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1}; 
int n,m;
string map[101];
bool visit[101][101];
int dist[101][101];
queue<pair<int,int> > q;

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	q.push(make_pair(0,0));
	visit[0][0] = true;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(visit[nx][ny]==false&&map[nx][ny]=='1'){
					q.push(make_pair(nx,ny));
					visit[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}
	}
	cout<<dist[n-1][m-1]+1<<"\n";
	return 0;
}
