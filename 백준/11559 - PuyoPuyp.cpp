#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

string map[13];
int res[13][7];
bool visit[13][7];
int answer;
void init(){
	for(int i=0;i<13;i++){
		for(int j=0;j<7;j++){
			visit[i][j] = false;
			res[i][j] = 0;
		}
	}
}

bool bfs(int x,int y){
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	vector<pair<int,int> > ve;
	ve.push_back(make_pair(x,y));
	visit[x][y] = true;
	res[x][y] = 1;
	while(!q.empty()){
		int x_ = q.front().first;
		int y_ = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x_ +dx[k];
			int ny = y_ +dy[k];
			if(nx>=0&&nx<12&&ny>=0&&ny<6){
				if(visit[nx][ny]==false&&map[nx][ny]==map[x_][y_]){
					visit[nx][ny] = true;
					q.push(make_pair(nx,ny));
					ve.push_back(make_pair(nx,ny));
				}
			}
		}
	}
	if(ve.size()>=4){
		for(int i=0;i<ve.size();i++){
			map[ve[i].first][ve[i].second] = '.';
		}
		return true;
	}
	return false;
	
}

int main(void){
	for(int i=0;i<12;i++){
		cin>>map[i];	
	}
	
	while(1){
		bool end_game = true;
		init();
		for(int i=0;i<12;i++){
			for(int j=0;j<6;j++){
				if(visit[i][j]==false&&map[i][j]!='.'){
					if(bfs(i,j)==true){
						end_game = false;
					}
				}
			}
		}
		cout<<"\n";
		for(int i=0;i<12;i++){
			for(int j=0;j<6;j++){
				cout<<map[i][j]<<" ";
			}
			cout<<"\n";
		}

		if(end_game==true){
			break;
		}else{
			for(int t=0;t<11;t++)
			for(int i=12;i>=1;i--){
				for(int j=0;j<6;j++){
					if(map[i][j]=='.'&&map[i-1][j]!='.'){
						map[i][j] = map[i-1][j];
						map[i-1][j] = '.';
					}
				}
			}
		cout<<"\n";
		for(int i=0;i<12;i++){
			for(int j=0;j<6;j++){
				cout<<map[i][j]<<" ";
			}
			cout<<"\n";
		}

			answer++;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
