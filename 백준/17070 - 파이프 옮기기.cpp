#include <iostream>
#include <vector>

using namespace std;
int n;
int a[17][17];
int ans;
int dx[3] = {0,1,1};
int dy[3] = {1,0,1};
void dfs(int x,int y,int dir){
	if(x==n-1&&y==n-1){
		ans++;
		return;
	}
	for(int k=0;k<3;k++){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(k==2&&(a[x+1][y]==1||a[x][y+1]==1)) continue;
		if(dir+k==1) continue;
		if(nx>=0&&nx<n&&ny>=0&&ny<n){
			if(a[nx][ny]!=1){
				dfs(nx,ny,k);
			}
		}
	}
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	dfs(0,1,0);
	cout<<ans<<"\n";
	return 0;
}
