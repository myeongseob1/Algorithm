#include <iostream>
#include <vector>

using namespace std;
int dx[4] = {1,0, 0,-1};
int dy[4] = {0,1,-1, 0};
int n,k;
vector<int> horse[13][13];
int map[13][13];
int dir[11];
bool movee[11];
int stage1 =1;
//0:흰색 1:빨간색 2:파란색
//턴이 1000보다 크거나 게임종료 안되면 -1
 
int main(void){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<k;i++){
		int a,b,c;
		cin>>a>>b>>c;
		horse[a-1][b-1].push_back(i+1);
		dir[i+1] = c%4;
	}
	while(1){
		for(int ii=1;ii<=k;ii++){
			movee[ii] = false;
		}
		bool end_game = false;
		for(int ii=1;ii<=k;ii++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(horse[i][j].size()>0){
						for(int k=0;k<horse[i][j].size();k++){
							if(horse[i][j][k]==ii&&movee[ii]==false){
								int x = i;
								int y = j;
								int p_dir = dir[ii];
								int idx = k;
								int nx = x + dx[p_dir];
								int ny = y + dy[p_dir];
								movee[ii] = true;
								
								if(map[nx][ny]==2||nx<0||nx>n-1||ny<0||ny>n-1){
									dir[ii] = 3-dir[ii];
									p_dir = dir[ii];
									nx = x + dx[p_dir];
									ny = y + dy[p_dir];
									if(map[nx][ny]==2||nx<0||nx>n-1||ny<0||ny>n-1){
										break;
									}
								}
								if(map[nx][ny]==0){
									for(int kk=idx;kk<horse[i][j].size();kk++){
										int mo = horse[i][j][kk];
										horse[nx][ny].push_back(mo);
										horse[i][j].erase(horse[i][j].begin()+kk);
										kk--;
									}								
								}
								if(map[nx][ny]==1){
									for(int kk=idx;kk<horse[i][j].size();kk++){
										int mo = horse[i][j][horse[i][j].size()-1];
										horse[nx][ny].push_back(mo);
										horse[i][j].pop_back();
										kk--;
									}								
								
								}
							}
						}
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(horse[i][j].size()>=4){
						end_game = true;
						break;
					}
				}
			}
			if(end_game==true) break;
		}
		if(end_game==true) break;
		stage1++;
		if(stage1>=1000){
			stage1 = -1;
			break;
		}
	}
	cout<<stage1<<"\n";
	return 0;
}
