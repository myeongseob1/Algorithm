#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int map[9][9];
bool visit[9][9];
int n,m;
vector<pair<int,int> > ve;
int answer;
void make_wall(int iter){
	if(iter==3){
		queue<pair<int,int> > q;
		int cpy_map[9][9];
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cpy_map[i][j] = map[i][j];
				visit[i][j] = false;
			}
		}
		for(int i=0;i<ve.size();i++){
			q.push(ve[i]);
			
		}
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx>=0&&nx<n&&ny>=0&&ny<m){
					if(visit[nx][ny]==false&&cpy_map[nx][ny]==0){
						cpy_map[nx][ny] = 2;
						visit[nx][ny] = true;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
		int rslt = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(cpy_map[i][j]==0){
					rslt++;
				}
			}
		}
		answer = max(answer,rslt);
		
		return;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==0){
				map[i][j] = 1;
				make_wall(iter+1);
				map[i][j] = 0;
			}
		}
	}
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(map[i][j]==2){
				ve.push_back(make_pair(i,j));
			}
		}
	}
	make_wall(0);
	cout<<answer<<"\n";
	return 0;
}
