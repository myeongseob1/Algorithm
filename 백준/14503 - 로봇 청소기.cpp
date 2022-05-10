#include <iostream>

using namespace std;
int n,m,r,c,dir;
int map[51][51];// 0: ºóÄ­ 1: º® 2: Ã»¼Ò 
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int answer;

int left_rotate(int dir){
	return (dir+3)%4;
}

int back_rotate(int dir){
	return (dir+2)%4;
}

int main(void){
	cin>>n>>m;
	cin>>r>>c>>dir;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	int now_r = r;
	int now_c = c;
	int now_dir = dir;
	int rotate_cnt = 0;
	while(1){
		if(map[now_r][now_c]==0){
			map[now_r][now_c] = 2;		
		}
		int n_dir = left_rotate(now_dir);
		int n_r = now_r + dx[n_dir];
		int n_c = now_c + dy[n_dir];
		if(map[n_r][n_c]==0){
			now_r = n_r;
			now_c = n_c;
			now_dir = n_dir;
			rotate_cnt = 0;
			continue;
		}
		else if(map[n_r][n_c]!=0){
			rotate_cnt++;
			now_dir = n_dir;
			if(rotate_cnt==4){
				int back_dir = back_rotate(now_dir);
				int back_r = now_r + dx[back_dir];
				int back_c = now_c + dy[back_dir];
				rotate_cnt = 0;
				if(map[back_r][back_c] == 2){
					now_r = back_r;
					now_c = back_c;
					continue;
				}
				if(map[back_r][back_c] == 1){
					break;
				}
			}
			
		}		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==2) answer++;
		}
	}
	cout<<answer<<"\n";
	
	return 0;
}
