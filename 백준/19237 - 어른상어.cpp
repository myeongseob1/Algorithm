#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4] = {0,-1,1, 0};
int dy[4] = {1, 0,0,-1};

struct shark{
	int num,dir;
	bool move;
};

struct smell{
	int co,mok;
};

int n,m,k; 
vector<shark> map[21][21];
smell sm[21][21];
int pr_move[442][4][4];
int tmp_map[21][21];
int move1[442];

bool end_check(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j].size()>0){
				if(map[i][j][0].num>0) return false;
			}
		}
	}
	return true;
}

bool compare(shark a, shark b){
	return a.num<b.num;
}

int main(void){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>tmp_map[i][j];
			if(tmp_map[i][j]!=0){
				shark tmp;
				tmp.num = tmp_map[i][j]-1;
				map[i][j].push_back(tmp);
			}
		}
	}
	for(int i=0;i<m;i++){
		cin>>move1[i];
		move1[i] %= 4;
	}
	for(int ii=0;ii<m;ii++){
		for(int i=1;i<=4;i++){
			for(int j=0;j<4;j++){
				cin>>pr_move[ii][i%4][j];
				pr_move[ii][i%4][j] %= 4;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sm[i][j].co = -1;
			if(map[i][j].size()>0){
				map[i][j][0].dir = move1[map[i][j][0].num];				
			}
		}
	}
	int time = 0;
	while(1){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j].size()>0){
					sm[i][j].co = map[i][j][0].num;
					sm[i][j].mok = k;
				}				
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j].size()>0){
					if(map[i][j][0].move==true) continue;
					int sh_num = map[i][j][0].num;
					int dir = map[i][j][0].dir;
					bool move2 = false;
					for(int k=0;k<4;k++){
						int n_dir = pr_move[sh_num][dir][k];
						int nx1 = i + dx[n_dir];
						int ny1 = j + dy[n_dir];
						if(nx1>=0&&nx1<n&&ny1>=0&&ny1<n){
							if(sm[nx1][ny1].mok==0&&sm[nx1][ny1].co==-1){
								map[i][j][0].dir= n_dir;
								map[i][j][0].move = true;
								map[nx1][ny1].push_back(map[i][j][0]);
								map[i][j].pop_back();
								move2 = true;
								break;
							}
						}
					}
					if(move2==false){
						for(int k=0;k<4;k++){
							int n_dir = pr_move[sh_num][dir][k];
							int nx1 = i + dx[n_dir];
							int ny1 = j + dy[n_dir];
							if(nx1>=0&&nx1<n&&ny1>=0&&ny1<n){
								if(sm[nx1][ny1].co==sh_num){
									map[i][j][0].dir= n_dir;
									map[i][j][0].move = true;
									map[nx1][ny1].push_back(map[i][j][0]);
									map[i][j].pop_back();
									move2 = true;
									break;
								}
							}
						}			
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j].size()>1){
					sort(map[i][j].begin(),map[i][j].end(),compare);
				}
				int sz = map[i][j].size();
				for(int k=0;k<sz-1;k++){
					map[i][j].pop_back();
				}				
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(sm[i][j].mok>0){
					sm[i][j].mok--;
				}
				if(sm[i][j].mok==0){
					sm[i][j].co = -1;
				}
				if(map[i][j].size()>0){
					map[i][j][0].move = false;
				}
			}
		}
		time++;
		if(end_check()==true){
			break;
		}
		if(time>=1000){
			time = -1;
			break;
		}
	}
	cout<<time<<"\n";
	return 0;
}
