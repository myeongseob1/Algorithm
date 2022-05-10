#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> 
using namespace std;

struct shark{
	int x,y,size,eat;
};

struct fish{
	int x,y,size,dist;
};

int n;
int map[21][21];
int dist[21][21];
bool visit[21][21];
shark sh;
int answer;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void init(){
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			dist[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

bool compare(fish a, fish b){
	if(a.dist==b.dist){
		if(a.x==b.x){
			return a.y<b.y;		
		}
		return a.x<b.x;
	}
	return a.dist<b.dist;
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			if(map[i][j]==9){
				sh.x = i;
				sh.y = j;
				map[i][j] = 0;
			}
		}
	}
	sh.size = 2;
	sh.eat = 0;
	while(1){
		init();
		vector<fish> tank;
		queue<pair<int,int> > q;
		q.push(make_pair(sh.x,sh.y));
		visit[sh.x][sh.y] = true;
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx>=0&&nx<n&&ny>=0&&ny<n){
					if(map[nx][ny]<=sh.size&&visit[nx][ny]==false){
						dist[nx][ny] = dist[x][y] + 1;
						visit[nx][ny] = true;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j]>=1&&map[i][j]<=6){
					if(map[i][j]<sh.size&&visit[i][j]==true){
						fish tmp;
						tmp.x = i;
						tmp.y = j;
						tmp.dist = dist[i][j];
						tmp.size = map[i][j];
						tank.push_back(tmp);
					}
				}			
			}
		}
		if(tank.empty()==true){
			break;
		}
		if(tank.size()>1){
			sort(tank.begin(),tank.end(),compare);		
		}
		sh.x = tank[0].x;
		sh.y = tank[0].y;
		map[tank[0].x][tank[0].y] = 0;
		sh.eat += 1;
		if(sh.eat==sh.size){
			sh.size++;
			sh.eat=0;
		}
		answer += tank[0].dist;
	}
	cout<<answer<<"\n";
	return 0;
}
