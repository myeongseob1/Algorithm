#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n,l,r;
int a[51][51];
int visited[51][51];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int minus_abs(int p, int q){
	if(p-q>0) return p-q;
	else return q-p;
}
void bfs(int s,int t,int c){
	queue<pair<int,int> > q;
	q.push(make_pair(s,t));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<n){
				if(minus_abs(a[x][y],a[nx][ny])>=l&&minus_abs(a[x][y],a[nx][ny]<=r)&&visited[nx][ny]!=0){
					visited[nx][ny] = c;
					q.push(make_pair(nx,ny));
				}
			}
		}		
	}
}
int main(void){
	cin>>n>>l>>r;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			bfs(i,j,1);
		}
	}
	cout<<"\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<visited[i][j]<<" ";
		}
		cout<<"\n";
	}	
	return 0;
}
