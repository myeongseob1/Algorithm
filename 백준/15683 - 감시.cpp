#include <iostream>
#include <vector>

using namespace std;

int n,m;
int map[9][9];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
vector<pair<int,int> > camera;
int answer = 987654321;
void cctv(int x, int y, int dir){
	int x_c = x;
	int y_c = y;
	while(1){
		int nx = x_c + dx[dir];
		int ny = y_c + dy[dir];
		if(nx<0||nx>n-1||ny<0||ny>m-1) break;
		if(map[nx][ny]==6) break;
		if(!(map[nx][ny]==1||map[nx][ny]==2||map[nx][ny]==3||map[nx][ny]==4||map[nx][ny]==5)){
			map[nx][ny] = 9;
		}
		x_c = nx;
		y_c = ny;
	}
}
void dfs(int iter){
	if(iter==camera.size()){
		int result = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]==0){
					result++;
				}
			}
		}
		answer = min(result,answer);
		return;
	}
	if(iter>camera.size()) return;
	int copy_map[9][9];
	if(map[camera[iter].first][camera[iter].second]==1){
		for(int k=0;k<4;k++){
			copy(&map[0][0],&map[9][0],&copy_map[0][0]);
			cctv(camera[iter].first,camera[iter].second,k);
			dfs(iter+1);
			copy(&copy_map[0][0],&copy_map[9][0],&map[0][0]);
		}	
	}
	if(map[camera[iter].first][camera[iter].second]==2){
		for(int k=0;k<2;k++){
			copy(&map[0][0],&map[9][0],&copy_map[0][0]);
			cctv(camera[iter].first,camera[iter].second,k);
			cctv(camera[iter].first,camera[iter].second,(k+2)%4);
			dfs(iter+1);
			copy(&copy_map[0][0],&copy_map[9][0],&map[0][0]);
		}
	}
	if(map[camera[iter].first][camera[iter].second]==3){
		for(int k=0;k<4;k++){
			copy(&map[0][0],&map[9][0],&copy_map[0][0]);
			cctv(camera[iter].first,camera[iter].second,k);
			cctv(camera[iter].first,camera[iter].second,(k+1)%4);
			dfs(iter+1);
			copy(&copy_map[0][0],&copy_map[9][0],&map[0][0]);
		}	
	}
	if(map[camera[iter].first][camera[iter].second]==4){
		for(int k=0;k<4;k++){
			copy(&map[0][0],&map[9][0],&copy_map[0][0]);
			cctv(camera[iter].first,camera[iter].second,k);
			cctv(camera[iter].first,camera[iter].second,(k+1)%4);
			cctv(camera[iter].first,camera[iter].second,(k+2)%4);
			dfs(iter+1);
			copy(&copy_map[0][0],&copy_map[9][0],&map[0][0]);
		}	
	}
	if(map[camera[iter].first][camera[iter].second]==5){
		copy(&map[0][0],&map[9][0],&copy_map[0][0]);
		cctv(camera[iter].first,camera[iter].second,0);
		cctv(camera[iter].first,camera[iter].second,1);
		cctv(camera[iter].first,camera[iter].second,2);
		cctv(camera[iter].first,camera[iter].second,3);
		dfs(iter+1);
		copy(&copy_map[0][0],&copy_map[9][0],&map[0][0]);

	}

}
 
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(map[i][j]!=0&&map[i][j]!=6){
				camera.push_back(make_pair(i,j));
			}
		}
	}
	dfs(0);
	cout<<answer<<"\n";
	return 0;
}
