#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int d[100][100];
int a[100][100];
bool check[100][100];
int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void bfs(){
	queue<pair<int,int> > q;
	check[0][0]=true; q.push(make_pair(0,0));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(check[nx][ny]==false&&a[nx][ny]==1){
					check[nx][ny] = true; q.push(make_pair(nx,ny));
					d[nx][ny] = d[x][y]+1;		
				}	
					
			} 
		}
	}
}


int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&a[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			bfs();
		}
	}
	cout<<d[n-1][m-1]+1<<"\n";
	
	return 0;
}
