#include <iostream>
#include <queue>
 
using namespace std;

struct axis{
	int x,y,byuk;
};

int map[1001][1001];
int dist[1001][1001][2];
bool visit[1001][1001][2];
int n,m;
int hx,hy;
int ex,ey;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<axis> q;

int main(void){
	cin>>n>>m;
	cin>>hx>>hy;
	cin>>ex>>ey;
	hx--;hy--;ex--;ey--;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	
	visit[hx][hy][0] = true;
	axis tt;
	tt.x = hx;
	tt.y = hy;
	tt.byuk = 0;
	q.push(tt);
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().byuk;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(visit[nx][ny][z]==false && map[nx][ny]==0){
					dist[nx][ny][z] = dist[x][y][z] + 1;
					visit[nx][ny][z] = true;
					axis ttt;
					ttt.x = nx;
					ttt.y = ny;
					ttt.byuk = z;
					q.push(ttt);
				}
				if(visit[nx][ny][z+1]==false&&map[nx][ny]==1 && z==0){
					dist[nx][ny][z+1] = dist[x][y][z] + 1;
					visit[nx][ny][z+1] = true;
					axis ttt;
					ttt.x = nx;
					ttt.y = ny;
					ttt.byuk = z+1;
					q.push(ttt);
				}
			}
		}
	}
	int answer;
	if(visit[ex][ey][0]==false && visit[ex][ey][1]==true){
		answer = dist[n-1][m-1][1];
	}
	if(visit[ex][ey][0]==true && visit[ex][ey][1]==false){
		answer = dist[n-1][m-1][0];
	}
	if(visit[ex][ey][0]==false&&visit[ex][ey][1]==false){
		answer = -1;
	}
	if(visit[ex][ey][0]==true && visit[ex][ey][1]==true){
		answer = min(dist[ex][ey][0],dist[ex][ey][1]);	
	}

	cout<<answer<<"\n";
	return 0;
}
