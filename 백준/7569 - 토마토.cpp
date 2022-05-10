#include <iostream>
#include <queue>

using namespace std;

struct tomato{
	int x,y,z;
};

int map[101][101][101];
int dist[101][101][101];
bool visit[101][101][101];
int n,m,k;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
queue<tomato> q;

int main(void){
	cin>>m>>n>>k;
	for(int kk=0;kk<k;kk++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>map[i][j][kk];
				if(map[i][j][kk]==1){
					tomato tmp;
					tmp.x = i;
					tmp.y = j;
					tmp.z = kk;
					visit[i][j][kk] =true;
					q.push(tmp);	
				} 
			}
		}		
	}
	while(!q.empty()){
		int xx = q.front().x;
		int yy = q.front().y;
		int zz = q.front().z;
		q.pop();
		for(int kk=0;kk<6;kk++){
			int nx = xx+dx[kk];
			int ny = yy+dy[kk];
			int nz = zz+dz[kk];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&nz>=0&&nz<k){

				if(visit[nx][ny][nz]==false&&map[nx][ny][nz]==0){

					visit[nx][ny][nz] = true;
					dist[nx][ny][nz] = dist[xx][yy][zz] +1;
					tomato tmp2;
					tmp2.x = nx;
					tmp2.y = ny;
					tmp2.z = nz;
					q.push(tmp2);
				}
			}
		}
	}

	bool we = true;
	int answer = 0;
	for(int kk=0;kk<k;kk++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(visit[i][j][kk]==false&&map[i][j][kk]==0){
					we = false;
				}
				answer = max(answer,dist[i][j][kk]);
			}
		}	
	}
	if(we==false) answer = -1;
	cout<<answer<<"\n";
	return 0;
}
