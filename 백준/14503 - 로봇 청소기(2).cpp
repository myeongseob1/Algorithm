#include <iostream>

using namespace std;

int n,m,r,c,dir;//dir이 0:북쪽(위) 1:동-> 2: 남 3:서<- 
int a[51][51];
int d[51][51];
int dx[4] = {-1,0,1, 0};
int dy[4] = {0, 1,0,-1};
int answer;
int left_turn(int direction){
	return (direction+3)%4;
}

int back_turn(int direction){
	return (direction+2)%4;
}

int main(void){
	cin>>n>>m;
	cin>>r>>c>>dir;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]== 1) d[i][j] = 1;
		}
	}
	int x = r;
	int y = c;
	int direction = dir;
	bool back_wh = false;
	int left = 0;
	while(1){
		if(back_wh==false){
			d[x][y] = 2;		
		}
		else{
			back_wh = false;
		}
		
		int nx = x+dx[left_turn(direction)];
		int ny = y+dy[left_turn(direction)];
		
		if(d[nx][ny]==0){
			x = nx;
			y = ny;
			direction = left_turn(direction);
			left=0;
			continue;
		}
		else{
			nx = x+dx[back_turn(direction)];
			ny = y+dy[back_turn(direction)];

			if(left==4&&d[nx][ny]!=1){
				back_wh = true;
				x = nx;
				y = ny;
				left = 0; 
				continue;
			}
			if(left==4&&d[nx][ny]==1){	
				break;
			}
			left++;
			direction = left_turn(direction);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(d[i][j]==2){
				answer++;
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
