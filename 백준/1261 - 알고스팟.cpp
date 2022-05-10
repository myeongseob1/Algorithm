#include <iostream>
#include <deque>
#include <vector>

using namespace std;
int n,m;
string map[101];
int dist[101][101];
bool visit[101][101]; 

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	
	deque<pair<int,int> > q;
	q.push_back(make_pair(0,0));
	visit[0][0] = true;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for(int k=0;k<4;k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(visit[nx][ny]==false&&map[nx][ny]=='0'){
					dist[nx][ny] = dist[x][y];
					visit[nx][ny] = true;
					q.push_front(make_pair(nx,ny));
				}
				else if(visit[nx][ny]==false&&map[nx][ny]=='1'){
					dist[nx][ny] = dist[x][y] + 1;
					visit[nx][ny] = true;
					q.push_back(make_pair(nx,ny));
				}
			}
		}
	}
	cout<<dist[n-1][m-1]<<"\n";
	return 0;
}
