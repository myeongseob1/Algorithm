#include <iostream>

using namespace std;
int map[501][501];
int n;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int tx[4][10] ={
	{1,-1,-2,-1,1,2,-1,1,0},
	{-1,-1,0,0,0,0,1,1,1,2},
	{-1,1,-2,-1,1,2,-1,1,0},
	{1,1,0,0,0,0,-1,-1,-2}
};
int ty[4][10] ={
	{1,1,0,0,0,0,-1,-1,-2},
	{1,-1,-2,-1,1,2,-1,1,0},
	{-1,-1,0,0,0,0,1,1,2},
	{-1,1,-2,-1,1,2,1,-1,0}
};
int ratio[9] = {1,1,2,7,7,2,10,10,5};
int wheel(int dir){
	return (dir+1)%4;
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	int x = n/2;
	int y = n/2;
	int move_count = 0;
	int answer = 0;
	int dir = 1;
	int tmp = 0;
	for(int i=0;i<n*n-1;i++){
		int n_dir = dir;
		for(int j=1;j<=n;j++){
			if(j*j==i||j*j+j==i){
				n_dir = wheel(dir);
			}
		}

		int n_x = x + dx[dir];
		int n_y = y + dy[dir];
		int amount = map[n_x][n_y];
		int tmp = map[n_x][n_y];
		for(int k=0;k<9;k++){
			int nx = n_x+tx[dir][k];
			int ny = n_y+ty[dir][k];
			int amount2 = (ratio[k] * tmp)/100;
			if(nx>=0&&nx<n&&ny>=0&&ny<n){
				map[nx][ny] += amount2;
			}else{
				answer += amount2;	
			}
			amount -= amount2;
		}
		if(n_x>=0&&n_x<n&&n_y>=0&&n_y<n){
			map[n_x][n_y] += amount;
		}else{
			answer += amount;
		}
		map[n_x][n_y] = 0;
		cout<<"\n";
		for(int ii=0;ii<n;ii++){
			for(int jj=0;jj<n;jj++){
				cout<<map[ii][jj]<<" ";
			}
			cout<<"\n";
		}
		x = n_x;
		y = n_y;

	}
	
	cout<<answer<<"\n";
	return 0;
}
