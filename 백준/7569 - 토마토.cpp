#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

typedef struct point{
	int x;
	int y;
	int z;
}point;

int a[101][101][101];
int d[101][101][101];

int main(void){
	int m,n,l;
	point t;
	int answer=0;
	queue<point> q;
	cin>>m>>n>>l;
	for(int k=0;k<l;k++){
		for(int j=0;j<n;j++){
			for(int i=0;i<m;i++){
				cin>>a[i][j][k];
				t.x = i; t.y = j; t.z = k;
				if(a[i][j][k]==1){
					q.push(t);
					d[i][j][k]++;
				}  
				if(a[i][j][k]==-1) d[i][j][k] = -1;
			}
		}
	}
	
	
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		for(int i=0;i<6;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			int nz = z+dz[i];
			if(nx>=0&&nx<m&&ny>=0&&ny<n&&nz>=0&&nz<l){
				if(d[nx][ny][nz]==0&&a[nx][ny][nz]==0){
					point tmp;
					tmp.x = nx; tmp.y = ny; tmp.z = nz;
					q.push(tmp);
					d[nx][ny][nz] = d[x][y][z]+1;
				}
			}
		}
	}
	
	for(int k=0;k<l;k++){
		for(int j=0;j<n;j++){
			for(int i=0;i<m;i++){
				if(d[i][j][k]>answer){
					answer = d[i][j][k] -1;
				}
			}
		}
	}

	for(int k=0;k<l;k++){
		for(int j=0;j<n;j++){
			for(int i=0;i<m;i++){
				if(d[i][j][k]==0){
					answer = -1;	
				}
			}
		}
	}

	cout<<answer<<"\n";
	return 0;
}
