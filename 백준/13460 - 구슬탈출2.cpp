#include <iostream>
#include <vector>

using namespace std;

int n,m;
char map[11][11];
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};//0:밑 1:<= 2:-> 3: 위 
pair<int,int> red_start;
pair<int,int> blue_start;
int answer = 987654321;
string answer2 = "";
string getDir(int dir){
	if(dir==0){
		return "D";
	}
	else if(dir==1){
		return "L";
	}
	else if(dir==2){
		return "R";
	}
	else if(dir==3){
		return "U";
	}
}
void move_bead(int rx,int ry,int bx,int by,int dir,int score,string nu){
	
	if(score>10){
		return;
	}
	if(rx<=0||rx>n-1||ry<=0||ry>m-1||bx<=0||bx>n-1||by<=0||by>m-1) return;

	int n_rx = rx + dx[dir];
	int n_ry = ry + dy[dir];

	while(1){//빨간구슬 움직이기 
		if(map[n_rx][n_ry]=='.'){
			n_rx += dx[dir];
			n_ry += dy[dir];	
		}
		if(map[n_rx][n_ry]=='O'){
			break;
		}
		if(map[n_rx][n_ry]=='#'){
			n_rx -= dx[dir];
			n_ry -= dy[dir];
			break;
		}
	}

	int n_bx = bx + dx[dir];
	int n_by = by + dy[dir];

	while(1){//파란구슬 움직이기 
		if(map[n_bx][n_by]=='.'){
			n_bx += dx[dir];
			n_by += dy[dir];	
		}
		if(map[n_bx][n_by]=='O'){
			break;
		}
		if(map[n_bx][n_by]=='#'){
			n_bx -= dx[dir];
			n_by -= dy[dir];
			break;
		}
	}
	if(map[n_rx][n_ry]=='O'&&map[n_bx][n_by]=='O'){
		return;
	}
	else if(map[n_rx][n_ry]=='O'){
		if(answer>=score){
			answer2 = nu+getDir(dir);
			answer = min(answer,score);		
		}	
		return;
	}
	else if(map[n_bx][n_by]=='O'){	
		return ;
	}
	if(n_rx==n_bx && n_ry==n_by){
		if(dir==0){
			if(rx>bx){
				n_bx -= dx[dir];
			}
			else{
				n_rx -= dx[dir];
			}	
		}
		else if(dir==1){
			if(ry>by){
				n_ry -= dy[dir];	
			}else{
				n_by -= dy[dir];
			}
		}
		else if(dir==2){
			if(ry<by){
				n_ry -= dy[dir];	
			}else{
				n_by -= dy[dir];
			}
			
		}
		else if(dir==3){
			if(rx<bx){
				n_bx -= dx[dir];
			}
			else{
				n_rx -= dx[dir];
			}	
			
		}
	}


	for(int i=0;i<4;i++){
		if(i+dir==3|| i==dir ) continue;
		move_bead(n_rx,n_ry,n_bx,n_by,i,score+1,nu+getDir(dir));
	}
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%s",&map[i]);
		for(int j=0;j<m;j++){
			if(map[i][j]=='R'){
				red_start.first = i;
				red_start.second = j;
				map[i][j] = '.';
			}
			if(map[i][j]=='B'){
				blue_start.first = i;
				blue_start.second = j;
				map[i][j] = '.';
			}
		}
	}
	for(int k=0;k<4;k++){
		move_bead(red_start.first,red_start.second,blue_start.first,blue_start.second,k,1,"");	
	}
	if(answer==987654321){
		answer = -1;
	}
	cout<<answer<<"\n"<<answer2<<"\n";
	return 0;
}
