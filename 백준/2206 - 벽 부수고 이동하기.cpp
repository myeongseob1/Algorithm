#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
using namespace std;
int n,m;
int a[1001][1001];
int d[1001][1001][2];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void){
	cin>>n>>m;
	int min = 2002;
	bool bbush = true;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&a[i][j]);
		}
	}
			
	queue<tuple<int,int,int> > q;
	q.push(make_tuple(0,0,0));
	d[0][0][0] = 1;
	while(!q.empty()){
		int x,y,z;
		tie(x,y,z) = q.front(); 
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(a[nx][ny]==0&&d[nx][ny][z]==0){
				if(nx>=0&&nx<n&&ny>=0&&ny<m){
					q.push(make_tuple(nx,ny,z));
					d[nx][ny][z] = d[x][y][z] +1;	
				}
			}
			if(z==0&& a[nx][ny]==1&&d[nx][ny][z+1]==0){
				q.push(make_tuple(nx,ny,z+1));
				d[nx][ny][z+1] = d[x][y][z] +1;
			}		
			
		}
	}
	cout<<d[n-1][m-1][0]<<"\n";
	cout<<d[n-1][m-1][1]<<"\n";
} 
