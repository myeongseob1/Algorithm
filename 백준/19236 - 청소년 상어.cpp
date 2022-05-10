#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct fish{
	int x,y,num,dir;
	bool die;
};//num이 0일경우 죽은물고기 -1일경우 상어 

int dx[8] = {-1,-1,-1, 0, 1,1,1,0};
int dy[8] = {1 , 0,-1,-1,-1,0,1,1}; 

vector<fish> tank;
int map_num[4][4];
int answer;
bool compare(fish a,fish b){
	return a.num<b.num;
}

void move_fish(){
	for(int i=0;i<tank.size();i++){
		if(tank[i].die==false){
			int dir = tank[i].dir;

			while(1){
				int x = tank[i].x;
				int y = tank[i].y;
				int num = tank[i].num;
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if(nx>=0&&nx<4&&ny>=0&&ny<4){
					if(map_num[nx][ny]==0){
						tank[i].x = nx;
						tank[i].y = ny;
						tank[i].dir= dir;
						swap(map_num[x][y],map_num[nx][ny]);
						break;
					}
					else if(map_num[nx][ny]!=-1){
						tank[i].x = nx;
						tank[i].y = ny;
						tank[i].dir= dir;
						tank[map_num[nx][ny]-1].x = x;
						tank[map_num[nx][ny]-1].y = y;
						swap(map_num[x][y],map_num[nx][ny]);
						break;
						
					}
				}
				dir = (dir+1)%8;
			}
		}
	}
}
void move_shark(int x,int y,int dir,int num){
	vector<fish> tmp_tank = tank;
	int tmp_map[4][4];
	answer = max(answer,num);

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			tmp_map[i][j] = map_num[i][j];
		}
	}
	move_fish();
	for(int i=1;i<=3;i++){
		int nx = x+dx[dir]*i;
		int ny = y+dy[dir]*i;
		if(nx>=0&&nx<4&&ny>=0&&ny<4){
			if(map_num[nx][ny]>0){
				int prev = map_num[x][y];
				int prev2 = map_num[nx][ny];
				int n_num = tank[prev2-1].num;
				int n_dir = tank[prev2-1].dir;
				tank[prev2-1].die = true;
				map_num[x][y] = 0;
				map_num[nx][ny] = -1;
				move_shark(nx,ny,n_dir,num+n_num);
				tank[prev2-1].die = false;
				map_num[x][y] = -1;
				map_num[nx][ny] = prev2;

			}
		}
		else{
			break;	
		}
	}
	tank = tmp_tank;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			map_num[i][j] = tmp_map[i][j];
		}
	}

}

int main(void){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			int a,b;
			cin>>a>>b;
			map_num[i][j] = a;
			fish tmp;
			tmp.num = a;
			tmp.dir = b%8;
			tmp.die = false;
			tmp.x = i;
			tmp.y = j;
			tank.push_back(tmp);
		}
	}
	sort(tank.begin(),tank.end(),compare);
	int direc = tank[map_num[0][0]-1].dir;
	int numb = tank[map_num[0][0]-1].num;
	tank[map_num[0][0]-1].die = true;
	map_num[0][0] = -1;
	move_shark(0,0,direc,numb);
	cout<<answer<<"\n";
	return 0;
}
