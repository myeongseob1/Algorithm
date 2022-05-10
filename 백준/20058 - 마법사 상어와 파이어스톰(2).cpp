#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int dx[4] = {0,1, -1,0};
int dy[4] = {1,0, 0,-1};
int n,q,size_m;
int map[200][200];
int near[200][200];
bool visit[200][200];
int ans;

int ans2;
void init(){
	for(int i=0;i<size_m;i++){
		for(int j=0;j<size_m;j++){
			near[i][j] = 0;
		}
	}

}

void melt(){
	for(int i=0;i<size_m;i++){
		for(int j=0;j<size_m;j++){
			int x = i;
			int y = j;
			if(map[x][y]>0){
				for(int k=0;k<4;k++){
					int nx = x+dx[k];
					int ny = y+dy[k];
					if(nx>=0&&nx<size_m&&ny>=0&&ny<size_m){
						if(map[nx][ny]>0){
							near[i][j]++;
						}
					}
				}
			}
		}
	}
	for(int i=0;i<size_m;i++){
		for(int j=0;j<size_m;j++){
			if(near[i][j]<3){
				if(map[i][j]>0){
					map[i][j]--;
				}
			}
		}
	}
}

void bfs(){
	for(int i=0;i<size_m;i++){
		for(int j=0;j<size_m;j++){
			visit[i][j] = false;
		}
	}
	for(int i=0;i<size_m;i++){
		for(int j=0;j<size_m;j++){
			if(map[i][j]>0&&visit[i][j]==false){
				int sz = 1;
				queue<pair<int,int> > q;
				q.push(make_pair(i,j));
				visit[i][j] = true;
				while(!q.empty()){
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for(int k=0;k<4;k++){
						int nx = x+dx[k];
						int ny = y+dy[k];
						if(nx>=0&&nx<size_m&&ny>=0&&ny<size_m){
							if(visit[nx][ny]==false&&map[nx][ny]>0){
								visit[nx][ny] = true;
								sz++;
								q.push(make_pair(nx,ny));
							}
						}
					}
				}
				ans2 = max(ans2,sz);
			}
		}
	}
}

int main(void){
	cin>>n>>q;
	size_m = pow(2,n);
	for(int i=0;i<size_m;i++){
		for(int j=0;j<size_m;j++){
			cin>>map[i][j];
		}
	}
	for(int ii=0;ii<q;ii++){
		int stage;
		cin>>stage;
		int tmp_map[65][65];
		int idx_x = 0;
		int idx_y = 0;
		init();
		for(int i=0; i<size_m; i+=pow(2,stage)){
			for(int j=0; j<size_m; j+=pow(2,stage)){
				idx_x = i;
				idx_y = j;
				for(int k=j;k<j+pow(2,stage);k++){
					for(int t=i+pow(2,stage)-1;t>=0;t--){
						tmp_map[idx_x][idx_y] = map[t][k];
						idx_y++;	
					}
					idx_x++;
					idx_y = j;
				}
			}
		}
	
		for(int i=0;i<size_m;i++){
			for(int j=0;j<size_m;j++){
				map[i][j] = tmp_map[i][j];
			}
		}

		melt();
	}
	bfs();
	for(int i=0;i<size_m;i++){
		for(int j=0;j<size_m;j++){
			ans += map[i][j];
		}
	}
	cout<<ans<<"\n";
	cout<<ans2<<"\n";
	return 0;
}
