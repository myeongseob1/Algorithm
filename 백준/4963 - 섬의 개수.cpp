#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[50][50];
int d[50][50];
int answer[2500];
int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,-1,1,1,-1};
int n,m;
void dfs(int x,int y,int c){
	d[x][y] = c;
	for(int k=0;k<8;k++){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx>=0&&ny>=0&&nx<m&&ny<n){
			if(a[nx][ny]==1&&d[nx][ny]==0){
				dfs(nx,ny,c);
			}
		}
	}
}


int main(void){
	while(1){
		cin>>n>>m;
		if(n==0||m==0){
			return 0;
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				d[i][j] = 0;
			}
		}
		int start = 0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]==1&&d[i][j]==0){
					dfs(i,j,++start);
				}
			}
		}
		cout<<start<<"\n";	
		}
	
	return 0;	
}
