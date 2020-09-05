#include <iostream>

using namespace std;
int a[501][501];
int visit[501][501];
int n,m;
int answer;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
void dfs(int x,int y,int iter,int sum){
	if(iter==4){
		answer = max(answer,sum);
		return;
	}
	for(int k=0;k<4;k++){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<m&&visit[nx][ny]==0){
			visit[nx][ny] = 1;
			dfs(nx,ny,iter+1,sum+a[nx][ny]);
			visit[nx][ny] = 0;
		}
	}
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visit[i][j] = 1;
			dfs(i,j,0,0);
			visit[i][j] = 0;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i+2<n&&j+1<m){
				answer = max(answer,a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]+a[i+1][j]);
				answer = max(answer,a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j]);
			}
			if(i+1<n&&j+2<m){
				answer = max(answer,a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]);
				answer = max(answer,a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]);

			}
			
		}
	}
	
	cout<<answer<<"\n";
	return 0;	
} 
