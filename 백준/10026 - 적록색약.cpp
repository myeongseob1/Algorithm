#include <iostream>
#include <queue>

using namespace std;
int a[101][101];
int d[101][101];
int p[101][101]; 
//r:0 g:1 b:2
int n;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(int x,int y,int c){
	d[x][y] = c;
	for(int k=0;k<4;k++){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<n){
			if(a[x][y]==a[nx][ny]&&d[nx][ny]==0){
				dfs(nx,ny,c);
			}
		}
	}
}
int no_sek, sek;
int main(void){
	cin>>n;
	char tmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>tmp;
			switch(tmp){
				case 'R': 
					a[i][j] = 0;
					break;
				case 'G':
					a[i][j] = 1;
					break;
				case 'B':
					a[i][j] = 2;
					break;
			}
		}
	}
	int c = 0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(d[i][j]==0){
				dfs(i,j,++c);	
			}
		}
	}
	no_sek = c;	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==1){
				a[i][j] = 0;	
			}
			d[i][j] = 0;
		}
	}
	c = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(d[i][j]==0){
				dfs(i,j,++c);			
			}
		}
	}
	sek = c;
	cout<<no_sek<<" "<<sek<<"\n";
	return 0;
}
