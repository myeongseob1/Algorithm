#include <iostream>

using namespace std;

int n,answer;
int map[101][101];
bool visit[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int max_map;
int min_map = 987654321;

void dfs(int x,int y,int num){
	visit[x][y] = true;
	for(int k=0;k<4;k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<n){
			if(!visit[nx][ny]&&map[nx][ny]>=num){
				visit[nx][ny] = true;
				dfs(nx,ny,num);
			}
		}
	}
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			max_map = max(max_map,map[i][j]);
			min_map = min(min_map,map[i][j]);
		}
	}
	
	for(int t = min_map-1; t<=max_map+1;t++){
		int rslt = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!visit[i][j]&&map[i][j]>=t){
					dfs(i,j,t);
					rslt++;
				}
			}
		}
		cout<<rslt<<"\n"; 
		answer = max(answer,rslt);
		rslt = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				visit[i][j] = false;				
			}
		}

	}
	cout<<answer<<"\n";
	return 0;
}
