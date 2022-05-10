#include <iostream>
#include <vector>
using namespace std;
int r,c,t;
int map[51][51];
int tmp[51][51];
vector<pair<int,int> > air;
int dx[4] = {-1,0,1, 0};
int dy[4] = {0, 1,0,-1};
int answer;
int back_turn(int dir){
	if(dir==0){
		return 3;
	}
	return dir-1;
}
void init(){
	for(int i=0;i<51;i++){
		for(int j=0;j<51;j++){
			tmp[i][j] = 0;
		}
	}
}
int main(void){
	cin>>r>>c>>t;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>map[i][j];
			if(map[i][j]==-1){
				air.push_back(make_pair(i,j));
			}
		}
	}
	for(int ii=0;ii<t;ii++){
		init();
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(map[i][j]>0){
					int am = map[i][j];
					int count = 0;
					for(int k=0;k<4;k++){
						int nx = i + dx[k];
						int ny = j + dy[k];
						if(nx>=0&&nx<r&&ny>=0&&ny<c){
							if(!((nx==air[0].first&&ny==air[0].second)||(nx==air[1].first&&ny==air[1].second))){
								tmp[nx][ny] += am/5;
								count++;
							}
						}
					}
					map[i][j] -= count * (am/5);
				}
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				map[i][j] += tmp[i][j];
			}
		}
		map[air[0].first][air[0].second] = 0;
		map[air[1].first][air[1].second] = 0;

		int x = air[0].first;
		int y = air[0].second;
		int f_dir = 0;
		int dir = 0;
		while(1){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx==air[0].first&&ny==air[0].second){
				map[x][y] = 0;
				break;	
			} 

			if(nx<0||nx>air[0].first||ny<0||ny>c-1){
				dir = (dir+1)%4;
				continue;
			}
			map[x][y] = map[nx][ny];
			x = nx;
			y = ny;			
		}
		map[air[0].first][air[0].second] = 0;
		map[air[1].first][air[1].second] = 0;
		x = air[1].first;
		y = air[1].second;
		f_dir = 2;
		dir = 2;	
		while(1){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx==air[1].first&&ny==air[1].second){
				map[x][y] = 0;
				break;	
			} 

			if(nx<air[1].first||nx>r-1||ny<0||ny>c-1){
				dir = back_turn(dir);
				continue;
			}
			map[x][y] = map[nx][ny];
			x = nx;
			y = ny;			
		}

		map[air[0].first][air[0].second] = 0;
		map[air[1].first][air[1].second] = 0;


	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			answer += map[i][j];
		}
	}

	cout<<answer<<"\n";
	return 0;
}
