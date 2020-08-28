#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n,m,start_i,start_j,end_i,end_j;
char a[51][51];
int river[51][51];
int animal[51][51];
queue<pair<int,int> > water;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%s",a[i]);
		for(int j=0;j<m;j++){
			if(a[i][j]=='S'){
				start_i = i;
				start_j = j;
			}
			else if(a[i][j]=='D'){
				end_i = i;
				end_j = j;
			}
			else if(a[i][j]=='*'){
				water.push(make_pair(i,j));
			}
		}
	}
	while(!water.empty()){
		int x = water.front().first;
		int y = water.front().second;
		water.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(a[nx][ny]=='.'&&river[nx][ny]==0){
					river[nx][ny] = river[x][y]+1;
					water.push(make_pair(nx,ny));
				}
			}
		}
	}
	queue<pair<int,int> > q;
	q.push(make_pair(start_i,start_j));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k]; 
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(animal[nx][ny]==0&&(a[nx][ny]=='.'||a[nx][ny]=='D')){
					if(river[nx][ny]==0){
						animal[nx][ny] = animal[x][y] +1;
						q.push(make_pair(nx,ny));
					}else{
						if(river[nx][ny]>animal[x][y]+1){
							animal[nx][ny] = animal[x][y] +1;
							q.push(make_pair(nx,ny));
						}
					}
				}
			}
		}
	}
	
	if(animal[end_i][end_j]!=0){
		cout<<animal[end_i][end_j]<<"\n";
	}
	else{
		cout<<"KAKTUS"<<"\n";
	}
	
	return 0;
}
