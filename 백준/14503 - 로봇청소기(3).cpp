#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct clean{
	int x;
	int y;
	int direction;
};

int n,m;
int a[51][51];
int d[51][51];
clean robot;
int answer;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int left_turn(int dir){
	return (dir+3)%4;
}

int back_turn(int dir){
	return (dir+2)%4;
}

int main(void){
	cin>>n>>m;
	cin>>robot.x>>robot.y>>robot.direction;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	while(1){
		if(d[robot.x][robot.y]==0){
			answer++;
			d[robot.x][robot.y]++;
		}
				
		bool check = false;
		for(int i=0;i<4;i++){
			robot.direction = left_turn(robot.direction);
			int nx = robot.x+dx[robot.direction];
			int ny = robot.y+dy[robot.direction];			
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(a[nx][ny]==0&&d[nx][ny]==0){
					check = true;
					robot.x = nx;
					robot.y = ny;
					break;	
				}
			}
			
		}
		if(check==false){
			robot.x = robot.x+dx[back_turn(robot.direction)];
			robot.y = robot.y+dy[back_turn(robot.direction)];
			if(robot.x<0||robot.x>=n||robot.y<0||robot.y>=m||a[robot.x][robot.y]==1){
				break;
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
