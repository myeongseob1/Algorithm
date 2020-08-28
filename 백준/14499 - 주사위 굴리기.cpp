#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;
int n,m,x,y,k;
int a[21][21];
int dice[7];
int order[1001];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0}; 
vector<int> answer;
int main(void){
	cin>>n>>m>>x>>y>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<k;i++){
		cin>>order[i];
	}
	for(int i=1;i<=6;i++){
		dice[i] = 0;
	}
	int nx,ny;
	for(int i=0;i<k;i++){
		nx = x + dx[order[i]-1];
		ny = y + dy[order[i]-1];		
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
			int tmp,tmp2;
			x = nx;
			y = ny;
			switch(order[i]){
				case 1:
					tmp = dice[2];
					dice[2] = dice[5];
					dice[5] = dice[4];
					dice[4] = dice[6];
					dice[6] = tmp;
					if(a[nx][ny]==0) a[nx][ny] = dice[4];
					else{
						dice[4] = a[nx][ny];
						a[nx][ny] = 0;
					} 					
					answer.push_back(dice[2]);
					break;
	 			case 2:
				 	tmp = dice[2], tmp2 = dice[4];
	 				dice[2] = dice[6];
 					dice[6] = tmp2;
 					dice[4] = dice[5];
 					dice[5] = tmp;
					if(a[nx][ny]==0) a[nx][ny] = dice[4];
					else{
						dice[4] = a[nx][ny];
						a[nx][ny] = 0;
					} 					
 					answer.push_back(dice[2]);
 					break;
				case 3:
					tmp = dice[4];
					dice[4] = dice[1];
					dice[1] = dice[2];
					dice[2] = dice[3];
					dice[3] = tmp;
					if(a[nx][ny]==0) a[nx][ny] = dice[4];
					else{
						dice[4] = a[nx][ny];
						a[nx][ny] = 0;
					} 					
					answer.push_back(dice[2]);
					break;
				case 4:
					tmp = dice[1]; tmp2 = dice[3];
					dice[1] = dice[4];
					dice[3] = dice[2];
					dice[2] = tmp;
					dice[4] = tmp2;
					if(a[nx][ny]==0) a[nx][ny] = dice[4];
					else{
						dice[4] = a[nx][ny];
						a[nx][ny] = 0;
					} 					
					answer.push_back(dice[2]);				
					break;
			}
		}
		else{
			nx = x;
			ny = y;
		}
	}
	for(int i=0;i<answer.size();i++){
		cout<<answer[i]<<"\n";
	}
	return 0;
}
