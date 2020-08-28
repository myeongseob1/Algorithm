#include <iostream>
#include <queue>

using namespace std;
int n,m;
int a[51][51];
int d[51][51];
int dx[8] = {-1,1,0,0,1,-1,1,-1};
int dy[8] = {0,0,1,-1,-1,1,1,-1};
int answer =0;
int main(void){
	queue<pair<int,int> > q;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]==1) q.push(make_pair(i,j));
		}
	}
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<8;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(d[nx][ny]==0&&a[nx][ny]==0){
					d[nx][ny] = d[x][y] +1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(answer<d[i][j]){
				answer = d[i][j];
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
