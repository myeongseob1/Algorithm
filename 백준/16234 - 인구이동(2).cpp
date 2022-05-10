#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n,l,r;
int map[51][51];
bool visit[51][51];


bool movee = false;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void init(){
	for(int i=0;i<51;i++){
		for(int j=0;j<51;j++){
			visit[i][j] = false;
		}
	}
	movee = false;
}

void bfs(int i,int j){
	queue<pair<int,int> > q;
	vector<pair<int,int> > contry;
	contry.push_back(make_pair(i,j));
	q.push(make_pair(i,j));
	visit[i][j] = true;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<n){
				if(visit[nx][ny]==false&&abs(map[x][y]-map[nx][ny])>=l&&abs(map[x][y]-map[nx][ny])<=r){
					visit[nx][ny] = true;
					contry.push_back(make_pair(nx,ny));
					q.push(make_pair(nx,ny));				
				}
			}
		}
	}
	int summ = 0;
	if(contry.size()>1){
		movee = true;
		for(int i=0;i<contry.size();i++){
			summ += map[contry[i].first][contry[i].second];
		}
		for(int i=0;i<contry.size();i++){
			map[contry[i].first][contry[i].second] = summ/contry.size();
		}
	}
}

int main(void){
	cin>>n>>l>>r;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	int answer = 0;
	while(1){
		init();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(visit[i][j]==false) bfs(i,j);
			}
		}
		if(movee==true){
			answer++;	
		}else{
			break;
		}		
	}
	cout<<answer<<"\n";
	return 0;
}
