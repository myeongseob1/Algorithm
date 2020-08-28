#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

/*
#(벽): 8  .(길): 0 R(빨간공): 1
B(파란공): 2  O(목적지) : 3
direction - 0:상 1:하 2:좌 3:우 
*/
using namespace std;
char tmp[11][11];
int a[11][11];
int n,m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int,int> > ball;
int r_start_x, r_start_y, b_start_x, b_start_y;
int answer;
vector<int> tt;
int min_a = 15;
int t[10];
bool r_arrive = false;
bool b_arrive = false;
void init(){
	r_arrive = false;
	b_arrive = false;
	answer = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			switch(tmp[i][j]){
				case '#':
					a[i][j] = 8;
					break;
				case '.':
					a[i][j] = 0;
					break;
				case 'R':
					r_start_x = i;
					r_start_y = j;
					a[i][j] = 1;
					break;
				case 'B':
					b_start_x = i;
					b_start_y = j;
					a[i][j] = 2;
					break;
				case 'O':
					a[i][j] = 3;
					break;
			}
		}
	}
}

void move(int direction){
	int r_x = r_start_x, r_y = r_start_y;
	int b_x = b_start_x, b_y = b_start_y;
	while(1){
		int r_nx = r_x +dx[direction];
		int r_ny = r_y +dy[direction];
		int b_nx = b_x +dx[direction];
		int b_ny = b_y +dy[direction];
				
		if(r_nx<0||r_nx>n-1||r_ny<0||r_ny>m-1||b_nx<0||b_nx>n-1||b_ny<0||b_ny>m-1){
			break;
		}
		if(a[r_nx][r_ny]==3){
			r_arrive = true;
			tt.push_back(1);
//			cout<<4<<"\n";
			break;
		}
		if(a[b_nx][b_ny]==3){
			b_arrive = true;
//			cout<<5<<"\n";
			break;
		}
		if(a[r_nx][r_ny]==0){
			a[r_nx][r_ny] = 1;
			a[r_x][r_y] = 0;
			r_x = r_nx;
			r_y = r_ny;
//			cout<<1<<"\n";
		}
		if(a[b_nx][b_ny]==0){
			a[b_nx][b_ny] = 2;
			a[b_x][b_y] = 0;
			b_x = b_nx;
			b_y = b_ny;
//			cout<<2<<"\n";
		}
		if(a[r_nx][r_ny]==8&&a[b_nx][b_ny]==8||a[r_nx][r_ny]==2&&a[b_nx][b_ny]==8||a[r_nx][r_ny]==8&&a[b_nx][b_ny]==1){
			r_start_x = r_x, r_start_y = r_y;
			b_start_x = b_x, b_start_y = b_y;
//			cout<<3<<"\n";
			break;
		}
			
	}
	
} 


int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%s",&tmp[i]);
	}
	init();
	move(2);	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<r_arrive<<"\n";
	cout<<b_arrive<<"\n";

	return 0;
}
