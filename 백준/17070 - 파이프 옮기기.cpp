#include <iostream>
#include <cmath>
using namespace std;

int n;
int map[17][17];
int dx[3] = {1,1,0};//0:세로 1:대각 2:가로  
int dy[3] = {0,1,1};
int answer;

void dfs(int x,int y,int dir){
	if(x==n-1&&y==n-1){
		answer++;
		return;
	}
	for(int k=0;k<3;k++){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<n){
			if(abs(dir-k)!=2&&map[nx][ny]==0){
				if(k==1){
					if(map[nx-1][ny]==1||map[nx][ny-1]==1) continue;
				}
				dfs(nx,ny,k);
			}
		}
	}
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	dfs(0,1,2);
	cout<<answer<<"\n";
	return 0;
}
