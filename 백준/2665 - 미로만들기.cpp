#include <iostream>
#include <queue>

using namespace std;

string map[51];
int n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool visit[51][51];
int dist[51][51];
int answer;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	deque<pair<int,int> > dq;
	dq.push_back(make_pair(0,0));
	visit[0][0] = true;
	while(!dq.empty()){
		int x = dq.front().first;
		int y = dq.front().second;
		if(x==n-1&&y==n-1){
			break;
		}
		dq.pop_front();
		for(int k=0;k<4;k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<n){
				if(!visit[nx][ny]&&map[nx][ny]=='1'){
					visit[nx][ny] = true;
					dist[nx][ny] = dist[x][y];
					dq.push_front(make_pair(nx,ny));
				}
				else if(!visit[nx][ny]&&map[nx][ny]=='0'){
					visit[nx][ny] = true;	 
					dist[nx][ny] = dist[x][y] + 1;
					dq.push_back(make_pair(nx,ny));
				}
			}
		}
	}
	cout<<dist[n-1][n-1]<<"\n";
	return 0;
}
