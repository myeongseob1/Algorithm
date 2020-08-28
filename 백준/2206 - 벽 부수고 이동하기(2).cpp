#include <iostream>
#include <queue>

using namespace std;

struct tuple_a{
	int x,y,z;
};

int n,m;
char a[1001][1001];
int d[1001][1001][2];
int answer = -1;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int main(void){
	cin>>n>>m;
	queue<tuple_a> q;
	for(int i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	d[0][0][0] = 1;
	q.push({0,0,0});
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(d[nx][ny][z]==0&&a[nx][ny]=='0'){
					d[nx][ny][z] = d[x][y][z] +1;
					q.push({nx,ny,z});
				}
				if(z==0&&d[nx][ny][z+1]==0&&a[nx][ny]=='1'){
					d[nx][ny][z+1] = d[x][y][z] +1;
					q.push({nx,ny,z+1});
				}
			}
		}
	}
	if(d[n-1][m-1][0]==0&&d[n-1][m-1][1]==0) cout<<-1<<"\n";
	else if(d[n-1][m-1][0]==0) cout<<d[n-1][m-1][1]<<"\n";
	else if(d[n-1][m-1][1]==0) cout<<d[n-1][m-1][0]<<"\n";
	else cout<<min(d[n-1][m-1][0],d[n-1][m-1][1])<<"\n";
	return 0;
}
