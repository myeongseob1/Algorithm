#include <iostream>
#include <deque>

using namespace std;



int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int a[101][101];
int d[101][101];
int n,m;
int answer;
int main(void){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&a[i][j]);		
		}
	}
	deque<pair<int,int> > q;
	q.push_back(make_pair(0,0));
	d[0][0] = 1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(d[nx][ny]==0&&a[nx][ny]==0){
					d[nx][ny] = d[x][y];
					q.push_front(make_pair(nx,ny));
				}
				else if(d[nx][ny]==0&&a[nx][ny]==1){
					d[nx][ny] = d[x][y]+1;
					q.push_back(make_pair(nx,ny));
				}
			}
		}
	}

	cout<<d[n-1][m-1]-1<<"\n";
	return 0;
}
