#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[101][101];
int d[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int answer  = -2000;
void dfs(int x,int y,int c){
	d[x][y] = c;
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<n){
			if(d[nx][ny]==0){
				dfs(nx,ny,c);
			}
		}
	}
	
}

int main(void){
	cin>>n;
	int c = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			
		}
	}
	for(int k=0;k<=101;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]<=k){
					d[i][j] = -1;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(d[i][j]==0&&a[i][j]>k){
					dfs(i,j,++c);
				}
			}
		}
		if(c>answer){
			answer = c;
		}
		c = 0; 
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				d[i][j] = 0;	
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
