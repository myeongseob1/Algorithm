#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int a[1000][1000];
int d[1000][1000];
bool check[1000][1000];
int n,m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int> > q;
void bfs(){
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(a[nx][ny]==0&&d[nx][ny]==-1){
					q.push(make_pair(nx,ny));
					d[nx][ny] = d[x][y] +1;					
				}
			}
		}
	}
}

int main(void){
	cin>>m>>n;
	int max = -200;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			d[i][j] = -1;
			if(a[i][j]==1){
				q.push(make_pair(i,j));
				d[i][j]=0;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==1) bfs();
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(max<d[i][j]) max = d[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==0&&d[i][j]==-1){
				max = -1;
			}
		}
	}
	cout<<max<<"\n";
	
	return 0;
}
