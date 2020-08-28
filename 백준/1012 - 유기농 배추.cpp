#include <iostream>
#include <algorithm>

using namespace std;
int n,m,k;
int a[51][51],d[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(int x,int y,int c){
	d[x][y] = c;
	for(int t=0;t<4;t++){
		int nx = x+dx[t];
		int ny = y+dy[t];
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
			if(a[nx][ny]==1&&d[nx][ny]==0){
				dfs(nx,ny,c);
			}
		}
	}
	
}

void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a[i][j] = 0;
			d[i][j] = 0;
		}
	}
}

int iter;
int main(void){
	cin>>iter;
	for(int p=0;p<iter;p++){
		init();
		cin>>n>>m>>k;
		for(int i=0;i<k;i++){
			int x,y;
			cin>>x>>y;
			a[x][y] = 1;
		}
		int aa =0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==1&&d[i][j]==0){
					dfs(i,j,++aa);
				}
			}
		}
		cout<<aa<<"\n";		
	}
	return 0;
}
