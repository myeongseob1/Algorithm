#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int answer;
int a[9][9];
int d[9][9];
int n,m;
vector<pair<int,int> > ve;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void init(queue<pair<int,int> > &q){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==2) q.push(make_pair(i,j));
			d[i][j] = 0;
		}
	}

}

void dfs(int wall){
	if(wall==3){
		int tmp[9][9];
		copy(&a[0][0],&a[8][8],&tmp[0][0]);
		queue<pair<int,int> > q;
		int mid = 0;
		init(q);
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx>=0&&nx<n&&ny>=0&&ny<m){
					if(d[nx][ny]==0&&a[nx][ny]==0){
						a[nx][ny] = 2;
						d[nx][ny] = 1;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==0){
					mid++;
				}
			}
		}
		answer = max(answer,mid);
		copy(&tmp[0][0],&tmp[8][8],&a[0][0]);
	}
	if(wall>3){
		return;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==0){
				a[i][j] = 1;
				dfs(wall+1);
				a[i][j] = 0;
			}
		}
	}

}

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	dfs(0);			
	cout<<answer<<"\n";
	return 0;
}
