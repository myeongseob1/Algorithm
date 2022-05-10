#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int map[10][10];
bool visit[10][10];

int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

int n,m;
int ans;

void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visit[i][j] = false;
		}
	}
}

void dfs(int iter){
	if(iter==3){
		int tmp_map[10][10];
		copy(&map[0][0],&map[9][0],&tmp_map[0][0]);
		queue<pair<int,int> > q;
		init();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]==2){
					q.push(make_pair(i,j));
				}
			}
		}
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx>=0&&nx<n&&ny>=0&&ny<m){
					if(visit[nx][ny]==false&&tmp_map[nx][ny]==0){
						visit[nx][ny] = true;
						tmp_map[nx][ny] = 2;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
		int res = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(tmp_map[i][j]==0){
					res++;
				}
			}
		}
		ans = max(res,ans);
		return;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==0){
				map[i][j] = 1;
				dfs(iter+1);
				map[i][j] = 0;
			}
		}
	}
} 
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	dfs(0);
	cout<<ans<<"\n";
	return 0;
}
