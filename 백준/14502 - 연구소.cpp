#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int a[8][8];
int d[8][8]; 
int tmp[8][8];
int n,m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int answer;
void bfs(){
	queue<pair<int,int> > q;
	int num =0;
	int afterwall[8][8];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			afterwall[i][j] = tmp[i][j];
			d[i][j] = afterwall[i][j];
			if(d[i][j]==2){
				q.push(make_pair(i,j));
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
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(afterwall[nx][ny]==0&&d[nx][ny]==0){
					q.push(make_pair(nx,ny));
					d[nx][ny] = 2;
				}
				
			}
			
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(d[i][j]==0){
				num++;	
			}
		}
	}
	if(answer<num){
		answer = num;
	}	
}


void makewall(int iter){
	if(iter == 3){
		bfs();
		return;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(tmp[i][j]==0){
				tmp[i][j] = 1;
				makewall(iter+1);
				tmp[i][j] = 0;
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
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==0){
				for (int k = 0; k < n; k++)
					for (int l = 0; l < m; l++)
						tmp[k][l] = a[k][l];

				tmp[i][j] = 1;
				makewall(1);
				tmp[i][j] =0;

				
			}
		}
	}	
	cout<<answer<<"\n";

	return 0;
}
