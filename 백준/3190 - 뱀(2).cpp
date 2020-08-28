#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n,k,t;
int a[101][101];
int dir_c[101][2];
struct snake{
	int x,y;
};
deque<snake> sn;
int main(void){
	cin>>n>>k;
	for(int i=0;i<k;i++){
		int a_x,a_y;
		cin>>a_x>>a_y;
		a[a_x][a_y] = 1;
	}
	cin>>t;
	for(int i=0;i<t;i++){
		//1: ¿ÞÂÊÀ¸·Î ¹Ù²Þ 2: ¿À¸¥ÂÊÀ¸·Î ¹Ù²Þ 
		int a_t; char a_d;
		cin>>a_t>>a_d;
		dir_c[i][0] = a_t;
		if(a_d=='D'){
			dir_c[i][1] = 2;
		}
		else{
			dir_c[i][1] = 1;
		}
	}
	int time = 0;
	sn.push_back({1,1});
	int direction = 0;
	while(1){
		time++;
		int n_d = direction;
		int nx = sn.front().x + dx[n_d];
		int ny = sn.front().y + dy[n_d];
		bool die = false;
		if(nx<=0||nx>n||ny<=0||ny>n){
			break;
		} 
		for(int i=0;i<sn.size();i++){
			if(sn[i].x==nx&&sn[i].y==ny){
				die = true;
			}
		}
		if(die==true){
			break;
		}
		sn.push_front({nx,ny});
		if(a[nx][ny]==1){
			a[nx][ny] = 0;
		}
		else if(a[nx][ny]==0){
			sn.pop_back();
		}
		for(int i=0;i<t;i++){
			if(dir_c[i][0]==time){
				if(dir_c[i][1]==1){
					direction--;
					if(direction==-1){
						direction=3;
					}
				}
				else{
					direction = (direction+1)%4;
				}
			}
		}

	}
	cout<<time<<"\n"; 
	return 0;
}
