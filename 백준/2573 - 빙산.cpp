#include <iostream>
#include <queue>

using namespace std;

int n,m;
int map[301][301],cont[301][301];
bool visit[301][301];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int max_map;
int answer;
bool jdge(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]!=0){
				return false;
			}
		}
	}
	return true;
}
void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visit[i][j] = false;
			cont[i][j] = 0;
		}
	}
}

void dfs(int x,int y){
	visit[x][y] = true;
	for(int k=0;k<4;k++){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
			if(!visit[nx][ny]&&map[nx][ny]!=0){
				dfs(nx,ny);
			}
		}
	}
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			max_map = max(max_map,map[i][j]);
		}
	}
	bool flag = false;
	int t = 1;
	while(1){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				for(int k=0;k<4;k++){
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(nx>=0&&nx<n&&ny>=0&&ny<m){
						if(map[nx][ny]==0&&map[i][j]!=0){
							cont[i][j]++;
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]-cont[i][j]<0){
					map[i][j] = 0;
				}
				else{
					map[i][j] -= cont[i][j];
				}
			}
		}		

		int cnt = 0;
		init();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(!visit[i][j]&&map[i][j]!=0){
					dfs(i,j);
					cnt++;
				}
			}
		}
		if(cnt>1){
			answer = t;
			flag = true;
			break;
		}
		t++;
		if(jdge()) break;
	}
	if(flag) cout<<answer<<"\n";
	else cout<<0<<"\n";
	return 0;
}
