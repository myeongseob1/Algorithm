#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int a[1001][1001];
int d[1001][1001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main(void){
	int n,m;
	int answer = -1000;
	queue<pair<int,int> > q;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			d[i][j] = -1;
			
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==1){
				q.push(make_pair(i,j));
				d[i][j]++;
			}
		}
	}
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<m&&ny>=0&&ny<n){
				if(a[nx][ny]==0&&d[nx][ny]==-1){
					q.push(make_pair(nx,ny));
					d[nx][ny] = d[x][y] +1;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(answer<=d[i][j]){
				answer = d[i][j];
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==0&&d[i][j]==-1){
				answer = -1;
			}
		}
	}
	cout<<answer<<"\n";	
	return 0;
}
