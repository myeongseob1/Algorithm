#include <iostream>
#include <queue>

using namespace std;
int n,m,k;
char a[1001][1001];
int d[1001][1001][11];
int answer = 2147000000;
struct wall{
	int x,y,crush;
};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	queue<wall> wa;
	wa.push({0,0,0});
	d[0][0][0] = 1;
	while(!wa.empty()){
		int x = wa.front().x;
		int y = wa.front().y;
		int z = wa.front().crush;
		wa.pop();
		if(x==n-1&&y==m-1&&z==k){
			answer = d[x][y][z];
			break;
		}
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m){
				if(d[nx][ny][z]==0&&a[nx][ny]=='0'){
					d[nx][ny][z] = d[x][y][z]+1;
					wa.push({nx,ny,z});
				}
				if(a[nx][ny]=='1'&&d[nx][ny][z+1]==0&&z<k){
					d[nx][ny][z+1] = d[x][y][z]+1;
					wa.push({nx,ny,z+1});
				}
			}
		}
	}
//	cout<<d[n-1][m-1][2];
//	for(int i=0;i<=k;i++){
//		answer = min(answer,d[n-1][m-1][k]);
//	}
	cout<<answer<<"\n";
	return 0;
}
