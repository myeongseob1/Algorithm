#include <iostream>
#include <deque>

using namespace std;

int dir[11];
int chess[13][13];
deque<int> horse[13][13];
int dx[4] = {1,0, 0,-1};
int dy[4] = {0,1,-1, 0};
int answer;
int n,k;

int back_dir(int dir){
	return 3-dir;
}

int main(void){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>chess[i][j];
		}
	}
	for(int i=0;i<k;i++){
		int a,b,c;
		cin>>a>>b>>c;
		horse[a][b].push_back(i+1);
		dir[i+1] = c%4;
	}
	while(1){
		bool game_end = false;
		for(int ii=1;ii<=k;ii++){
			bool move = false;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int p=0;p<horse[i][j].size();p++){
						if(horse[i][j][p]==ii){
							int nx = i + dx[dir[ii]];
							int ny = j + dy[dir[ii]];
							if(chess[nx][ny]==2||(nx<1||ny<1||nx>n||ny>n)){
								nx = i + dx[back_dir(dir[ii])];
								ny = j + dy[back_dir(dir[ii])]; 
								dir[ii] = back_dir(dir[ii]);						
								if(chess[nx][ny]==2||(nx<1||ny<1||nx>n||ny>n)){
									move = true;
									break;
								}
								if(chess[nx][ny]==0){
									for(int t=p;t<horse[i][j].size();t++){
										int save = horse[i][j][t];
										horse[i][j].erase(horse[i][j].begin()+t);
										horse[nx][ny].push_back(save);
										t--;
									}
									move = true;
									break;
								}
								if(chess[nx][ny]==1){
									for(int t=p;t<horse[i][j].size();t++){
										int save = horse[i][j][horse[i][j].size()-1];
										horse[i][j].pop_back();
										horse[nx][ny].push_back(save);
										t--;
									}
									move = true;
									break;
								}
							}
							if(chess[nx][ny]==0){
								for(int t=p;t<horse[i][j].size();t++){
									int save = horse[i][j][t];
									horse[i][j].erase(horse[i][j].begin()+t);
									horse[nx][ny].push_back(save);
									t--;
								}
								move = true;
								break;	
							}
							if(chess[nx][ny]==1){
								for(int t=p;t<horse[i][j].size();t++){
									int save = horse[i][j][horse[i][j].size()-1];
									horse[i][j].pop_back();
									horse[nx][ny].push_back(save);
									t--;
								}
								move = true;
								break;
							}
						}
					}
					if(move == true) break;	
				}
				if(move == true) break;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(horse[i][j].size()>=4){
						game_end = true;
					}
				}
			}		
		}
		answer++;
		if(game_end==true){
			break;
		}
		if(answer>1000){
			answer = -1;
			break;
		}
	}
	cout<<answer<<"\n"; 
	return 0;
}
