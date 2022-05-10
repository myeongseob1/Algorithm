#include <iostream>
#include <vector> 
using namespace std;
int n,m,x,y,k;
int map[21][21];
int order[1001];
int dice[7];
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};
vector<int> answer;
int main(void){
	cin>>n>>m>>x>>y>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<k;i++){
		cin>>order[i];
		int nx = x+dx[order[i]];
		int ny = y+dy[order[i]];
		
		if(nx<0||nx>n-1||ny<0||ny>m-1) continue;
		if(order[i]==1){
			int tmp = dice[1];
			int tmp2 = dice[6];
			dice[1] = dice[4];
			dice[6] = dice[3];
			dice[4] = tmp2;
			dice[3] = tmp;
			if(map[nx][ny]==0){
				map[nx][ny] = dice[6];
			}else{
				dice[6] = map[nx][ny];
				map[nx][ny] = 0;
			}
		}else if(order[i]==2){
			int tmp = dice[1];
			int tmp2 = dice[6];
			dice[1] = dice[3];
			dice[6] = dice[4];
			dice[4] = tmp;
			dice[3] = tmp2;
			if(map[nx][ny]==0){
				map[nx][ny] = dice[6];
			}else{
				dice[6] = map[nx][ny];
				map[nx][ny] = 0;
			}
			
		}else if(order[i]==3){
			int tmp = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = tmp;
			if(map[nx][ny]==0){
				map[nx][ny] = dice[6];
			}else{
				dice[6] = map[nx][ny];
				map[nx][ny] = 0;
			}
			
		}else if(order[i]==4){
			int tmp = dice[5];
			int tmp2 = dice[1];
			int tmp3 = dice[2];
			dice[2] = dice[6];
			dice[1] = tmp3;
			dice[5] = tmp2;
			dice[6] = tmp;
			if(map[nx][ny]==0){
				map[nx][ny] = dice[6];
			}else{
				dice[6] = map[nx][ny];
				map[nx][ny] = 0;

			}
			
		}
		x = nx;
		y = ny;
		answer.push_back(dice[1]);
	}
	for(int i=0;i<answer.size();i++){
		cout<<answer[i]<<"\n";
	}
	return 0;
}
