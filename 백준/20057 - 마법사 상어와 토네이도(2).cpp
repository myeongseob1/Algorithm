#include <iostream>

using namespace std;

int n;
int map[501][501];
int answer;
int dx[4] = { 0,1,0,-1};
int dy[4] = {-1,0,1, 0};
int tx[4][9] = {{ 0,-1, 1,-2,-1,1,2,-1,1},{2, 1,1, 0, 0,0,0,-1,-1},{0,-1,1,-2,-1,1,2,-1, 1},{-2,-1,-1, 0, 0,0,0, 1,1}};
int ty[4][9] = {{-2,-1,-1, 0, 0,0,0, 1,1},{0,-1,1,-2,-1,1,2,-1, 1},{2, 1,1, 0, 0,0,0,-1,-1},{ 0,-1, 1,-2,-1,1,2,-1,1}};
int px[9] = {5,10,10,2,7,7,2,1,1};
int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>map[i][j];
		}
	}
	int x = (n/2) + 1;
	int y = (n/2) + 1;
	int dir = 0;
	for(int i=1;i<n*n;i++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		int tmp = map[nx][ny];
		for(int k=0;k<9;k++){
			int f_x = nx + tx[dir][k];
			int f_y = ny + ty[dir][k];
			int total = ( px[k] * map[nx][ny] ) / 100 ;
			if(f_x>=1&&f_x<=n&&f_y>=1&&f_y<=n){
				map[f_x][f_y] += total;
				tmp -= total;		
			}else{
				answer += total;
				tmp -= total;
			}
		}
		if(nx+dx[dir]>=1&&nx+dx[dir]<=n&&ny+dy[dir]>=1&&ny+dy[dir]<=n){
			map[nx+dx[dir]][ny+dy[dir]] += tmp;		
		}else{
			answer += tmp;
		}
		map[nx][ny] = 0;
		x = nx;
		y = ny;
		for(int j=1;j<=n;j++){
			if(i==j*j || i == j*j + j){
				dir = (dir+1) % 4;
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
