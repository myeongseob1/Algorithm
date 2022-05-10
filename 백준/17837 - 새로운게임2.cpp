#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int n,k;
int map[13][13];
vector<int> ho[13][13];
int dir[11];
int main(void){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<k;i++){
		int a,b,c;
		cin>>a>>b>>c;
		dir[i+1] = c%4;
		ho[a][b].push_back(i+1);
		
	}
	int stage = 1;
	while(1){
		bool end_game = false;
		for(int ii=1;ii<=k;ii++){
			bool turn = false;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k=0;k<ho[i][j].size();k++){
						if(ho[i][j][k]==ii){
							int nx = i + dx[dir[ii]];
							int ny = j + dy[dir[ii]];
							if(nx<1||nx>n||ny<1||ny>n||map[nx][ny]==2){
								dir[ii] = 3 - dir[ii];
								nx = i + dx[dir[ii]];
								ny = j + dy[dir[ii]];
								if(nx<1||nx>n||ny<1||ny>n||map[nx][ny]==2){
									turn = true;
									break;
								}
								if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
									if(map[nx][ny]==1){
										for(int t = k;t<ho[i][j].size();t++){
											int tmp = ho[i][j][ho[i][j].size()-1];
											ho[i][j].pop_back();
											ho[nx][ny].push_back(tmp);
											t--;
										}
										turn = true;
										break;
									}
									if(map[nx][ny]==0){
										for(int t = k;t<ho[i][j].size();t++){
											int tmp = ho[i][j][t];
											ho[i][j].erase(ho[i][j].begin()+t);
											ho[nx][ny].push_back(tmp);
											t--;
										}
										turn = true;
										break;
										
									}
								}
							}else{
								if(map[nx][ny]==1){
									for(int t = k;t<ho[i][j].size();t++){
										int tmp = ho[i][j][ho[i][j].size()-1];
										ho[i][j].pop_back();
										ho[nx][ny].push_back(tmp);
										t--;
									}
									turn = true;
									break;
								}
								if(map[nx][ny]==0){
									for(int t = k;t<ho[i][j].size();t++){
										int tmp = ho[i][j][t];
										ho[i][j].erase(ho[i][j].begin()+t);
										ho[nx][ny].push_back(tmp);
										t--;
									}
									turn = true;
									break;				
								}										
							}
					
							
						}
					}
					if(turn==true) break;
				}
				if(turn == true) break;
			}
			for(int a=1;a<=n;a++){
				for(int b=1;b<=n;b++){
					if(ho[a][b].size()>=4){
						end_game = true;
					}
				}
			}
			if(end_game==true){
				break;
			}
		}

		if(stage>1000){
			stage = -1;
			break;
		}
		if(end_game==true){
			break;
		}else{
			stage++;
		}

	}
	cout<<stage<<"\n";
	return 0;
}
