#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n,l,r;
int map[51][51];
bool visit[51][51];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int answer;


bool chk(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x = i;
			int y = j;
			for(int k=0;k<4;k++){
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(nx>=0&nx<n&&ny>=0&&ny<n){
					if(abs(map[nx][ny]-map[x][y])>=l&&abs(map[nx][ny]-map[x][y])<=r){
						return true;
					}
				}
			}
		}
	}
	return false;
}

void bfs(int x,int y){
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	visit[x][y] = true;
	vector<pair<int,int> > share;
	share.push_back(make_pair(x,y));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<n){
				if(!visit[nx][ny]&&abs(map[nx][ny]-map[x][y])>=l&&abs(map[nx][ny]-map[x][y])<=r){
					share.push_back(make_pair(nx,ny));
					q.push(make_pair(nx,ny));
					visit[nx][ny] = true;
				}
			}
		}
	}
	if(share.size()>1){
		int t = 0;
		for(int i=0;i<share.size();i++){
			t += map[share[i].first][share[i].second];
		}
		t /= share.size();
		for(int i=0;i<share.size();i++){
			map[share[i].first][share[i].second] = t;
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
		if(!chk()){
			break;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				visit[i][j] = false;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(visit[i][j]==false){
					bfs(i,j);
				}
			}
		}
		answer++;
		
	}
	cout<<answer<<"\n";
	return 0;
}
