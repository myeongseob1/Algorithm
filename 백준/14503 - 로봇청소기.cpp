#include <iostream>

using namespace std;

int dx[4] = {-1,0,1,0};//À§ ¿À ¾Æ ¿Þ 
int dy[4] = {0,1,0,-1};
int map[51][51];
int n,m,r,c,d;
int answer;
int left_turn(int dir){
	if(dir==0) return 3;
	return dir-1;
} 

int back_turn(int dir){
	return (dir+2)%4;
}
int main(void){
	cin>>n>>m>>r>>c>>d;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}	
	int x = r;
	int y = c;
	int dir = d;
	bool back_flag = false;
	while(1){
		if(!back_flag) map[x][y] = 2;
		back_flag = false;
		bool end_clean  = false;
		bool move = false;
		for(int t = 0; t<4;t++){
			int n_dir = left_turn(dir);
			int nx = x + dx[n_dir];
			int ny = y + dy[n_dir];
			if(map[nx][ny]==0){
				x = nx;
				y = ny;
				dir = n_dir;
				move = true;
				break;
			}
			else{
				dir = n_dir;
			}	
		}
		if(!move){
			int n_dir = back_turn(dir);
			int nx = x+dx[n_dir];
			int ny = y+dy[n_dir];
			if(map[nx][ny]==1){
				end_clean = true;
			}
			else{
				x = nx;
				y = ny;
				back_flag = true;
			}
		}
		if(end_clean) break;
			
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==2) answer++;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
