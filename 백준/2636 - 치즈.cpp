#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visit[101][101]; 
int map[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,m;
int answer;
void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visit[i][j] = false;
		}
	}
}
bool end_melt(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==1) return false;
		}
	}
	return true;
}


int main(void){
	cin>>n>>m;
	int chz = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(map[i][j]==1){
				chz++;
			}
		}
	}
	int time = 0;
	while(1){
		init();
		vector<pair<int,int> > ve;
		queue<pair<int,int> > q;
		q.push(make_pair(0,0));
		visit[0][0] = false;
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(nx>=0&&nx<n&&ny>=0&&ny<m){
					if(map[nx][ny]==0&&visit[nx][ny]==false){
						q.push(make_pair(nx,ny));
						visit[nx][ny] = true;
					}
					else if(map[nx][ny]==1&&visit[nx][ny]==false){
						visit[nx][ny] = true;
						ve.push_back(make_pair(nx,ny));
					}
				}
			}
		}
		
		for(int i=0;i<ve.size();i++){
			map[ve[i].first][ve[i].second] = 0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]==1) chz++;
			} 
		}
		if(chz!=0) answer = chz;
		chz = 0;
		time++;
		bool flag = false;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]==1) flag = true;
			}
		}
		if(!flag) break;

	}
	
	cout<<time<<"\n"<<answer<<"\n";
	
	return 0;
}
