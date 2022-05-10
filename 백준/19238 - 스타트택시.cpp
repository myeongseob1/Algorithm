#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct guest{
	int distance;
	int st_x;
	int st_y;
	int ar_x;
	int ar_y;
	
};
pair<int,int> car;
int dx[4] = {1,0, 0,-1};
int dy[4] = {0,1,-1, 0};

int n,m,oil;
int map[21][21];
int dist[21][21];
int dist2[21][21];
bool visit[21][21];
bool visit2[21][21];

void init(){
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			dist[i][j] = 0;
			dist2[i][j] = 0;
			visit[i][j] = false;
			visit2[i][j] = false;
		}
	}
}

bool compare(guest x,guest y){
	if(x.distance==y.distance){
		if(x.st_x==y.st_x){
			return x.st_y < y.st_y;
		}
		return x.st_x < y.st_x;
	}
	return x.distance < y.distance; // 작은순서대로 
}

int main(void){
	cin>>n>>m>>oil;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	cin>>car.first>>car.second;
	car.first--;
	car.second--;
	vector<guest> gu;
	for(int i=0;i<m;i++){
		guest tmp;
		cin>>tmp.st_x>>tmp.st_y>>tmp.ar_x>>tmp.ar_y;
		tmp.st_x--;
		tmp.st_y--;
		tmp.ar_x--;
		tmp.ar_y--; 
		gu.push_back(tmp);
	}
	while(1){
		init();
		queue<pair<int,int> > q;
		q.push(make_pair(car.first,car.second));
		visit[car.first][car.second] = true;
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx>=0&&nx<n&&ny>=0&&ny<n){
					if(dist[nx][ny]==0&&map[nx][ny]!=1&&visit[nx][ny]==false){
						dist[nx][ny] = dist[x][y]+1;
						visit[nx][ny] = true;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
		
		for(int i=0;i<gu.size();i++){
			gu[i].distance = dist[gu[i].st_x][gu[i].st_y];
		}
		sort(gu.begin(),gu.end(),compare);
		if(visit[gu[0].st_x][gu[0].st_y]==false){
			cout<<-1<<"\n";
			return 0;			
		}
		oil -= gu[0].distance;
		if(oil<=0){
			cout<<-1<<"\n";
			return 0;
		}
		queue<pair<int,int> > q2;
		q2.push(make_pair(gu[0].st_x,gu[0].st_y));
		visit2[gu[0].st_x][gu[0].st_y] = true;
		while(!q2.empty()){
			int x = q2.front().first;
			int y = q2.front().second;
			q2.pop();
			for(int k=0;k<4;k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx>=0&&nx<n&&ny>=0&&ny<n){
					if(dist2[nx][ny]==0&&map[nx][ny]!=1&&visit2[nx][ny]==false){
						dist2[nx][ny] = dist2[x][y] +1;
						visit2[nx][ny] = true;
						q2.push(make_pair(nx,ny));
					}	
				}
			}
		}
		oil -= dist2[gu[0].ar_x][gu[0].ar_y];
		if(visit2[gu[0].ar_x][gu[0].ar_y]==false){
			cout<<-1<<"\n";
			return 0;			
		}

		if(oil<0){
			cout<<-1<<"\n";
			return 0;
		}
		oil += dist2[gu[0].ar_x][gu[0].ar_y] * 2;
		car.first = gu[0].ar_x;
		car.second = gu[0].ar_y;
		gu.erase(gu.begin());
		if(gu.empty()==true){
			break;
		}
	}
	cout<<oil<<"\n";
	return 0;
}
