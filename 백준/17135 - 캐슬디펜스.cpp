#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n,m,d;
int a[16][16];
int visit[16][16];
int dx[4] = {0,-1,0};
int dy[4] = {-1,0,1};
int result = 0;
vector<pair<int,int> > warrior;
int man_dist(int ax,int ay,int bx,int by){
	return abs(ax-bx)+abs(ay-by);
}
void init(){
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			visit[i][j] = 0;
		}
	}
}
void dfs(int iter,int num){
	if(num==3){
		int answer = 0;
		int temp_map[16][16];
		copy(&a[0][0],&a[15][15],&temp_map[0][0]);
		while(1){
			vector<pair<int,int> > juk;
			for(int i=0;i<3;i++){
			init();
			queue<pair<int,int> > dist;
			dist.push(warrior[i]);
			while(!dist.empty()){
				int x = dist.front().first;
				int y = dist.front().second;
				bool end_it = false;
				dist.pop();
					for(int k=0;k<3;k++){
						int nx = x+dx[k];
						int ny = y+dy[k];
						if(nx>=0&&nx<n&&ny>=0&&ny<m&&man_dist(nx,ny,warrior[i].first,warrior[i].second)<=d){
							if(visit[nx][ny]==0&&a[nx][ny]==0){
								visit[nx][ny] = 1;
								dist.push(make_pair(nx,ny));
							}
							if(visit[nx][ny]==0&&a[nx][ny]==1){
								juk.push_back(make_pair(nx,ny));
								end_it = true;
								break;	
							}
						}
					}
					if(end_it==true){
						break;
					}		
				}
			}
			for(int i=0;i<juk.size();i++){
				if(a[juk[i].first][juk[i].second]==1){
					answer++;
				}
				a[juk[i].first][juk[i].second] = 0;			
			}
			for(int i=n-1;i>0;i--){
				for(int j=0;j<m;j++){
					a[i][j] = a[i-1][j];
				}
			}
			for(int i=0;i<m;i++){
				a[0][i] = 0;
			}
			bool juk_n = false;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(a[i][j]==1){
						juk_n = true;
					}
				}
			}
			if(juk_n==false){
				break;
			}		
		}
		if(result<answer){
			result = answer;
		}

		copy(&temp_map[0][0],&temp_map[15][15],&a[0][0]);
		return;
	}
	if(iter>=m){
		return;
	}
	warrior.push_back(make_pair(n,iter));
	dfs(iter+1,num+1);
	warrior.pop_back();
	dfs(iter+1,num);
}

int main(void){
	cin>>n>>m>>d;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	dfs(0,0);
	cout<<result<<"\n";
	return 0;
}
