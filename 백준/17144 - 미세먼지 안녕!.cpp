#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int r,c,t;
int a[51][51];
int answer;
int p[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dir[51][51];
int tmp[51][51];
void init(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			tmp[i][j] = 0;
			p[i][j] = 0;
			dir[i][j] = 0;
		}
	}
	answer = 0;
}

void clean(){
	for(int i=0;i<r;i++){
			if(p[i][0]==-1){
				tmp[i][0] = -1;
				tmp[i+1][0] = -1;
				for(int k=1;k<c-1;k++){
					tmp[i][k+1] = p[i][k];
					tmp[i+1][k+1] = p[i+1][k];
				}
				for(int k = i-1 ;k>=0;k-- ){
					tmp[k][c-1] = p[k+1][c-1];
				}
				for(int k=c-1;k>=0;k--){
					tmp[0][k-1] = p[0][k];
					tmp[r-1][k-1] = p[r-1][k];
				}
				for(int k=1;k<i;k++){
					tmp[k][0] = p[k-1][0]; 
				}
				for(int k=1;k<i;k++){
					for(int t=1;t<c-1;t++){
						tmp[k][t] = p[k][t];
					}
				}
				for(int k = i+1;k<r;k++){
					tmp[k+1][c-1] = p[k][c-1]; 
				}
				for(int k=r-2;k>i+1;k--){
					tmp[k][0] = p[k+1][0];
				}
				for(int k=i+2;k<r-1;k++){
					for(int t=1;t<c-1;t++){
						tmp[k][t] = p[k][t];
					}
				}
				break;
			}
		}
}

void diffuse(int x,int y){
	int direction =0;
	int d[51][51];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			d[i][j] = 0;
		}
	}
	for(int k=0;k<4;k++){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx>=0&&nx<r&&ny>=0&&ny<c&&a[nx][ny]!=-1){
			direction++;
		}
	}
	dir[x][y] = direction;
	for(int k=0;k<4;k++){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx>=0&&nx<r&&ny>=0&&ny<c&&a[nx][ny]!=-1){
			d[nx][ny] += a[x][y]/5;
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			p[i][j] += d[i][j];
		}
	}

}


int main(void){
	cin>>r>>c>>t;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j];
		}
	}
	
	for(int k=0;k<t;k++){
		init();
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(a[i][j]!=0){
					diffuse(i,j);
				}
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				p[i][j] += a[i][j]-dir[i][j]*(a[i][j]/5);
			}
		}
		clean();

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				a[i][j] = tmp[i][j];
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				answer += tmp[i][j];
			}
		}
				
	}
		
	cout<<answer+2<<"\n";
	return 0;
}
