#include <iostream>
#include <algorithm>
using namespace std;

int n,m,l;
int map[101][101];
bool visit[101][101];
int max_de[10001];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int idx;
int cnt;
void dfs(int x,int y){
	visit[x][y] = true;
	for(int k=0;k<4;k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
			if(visit[nx][ny]==false && map[nx][ny] == 0){
				dfs(nx,ny);
				cnt++;
			}	
		}
	}
}

int main(void){
	cin>>m>>n>>l;
	for(int i=0;i<l;i++){
		int st_x,st_y,e_x,e_y;
		cin>>st_x>>st_y>>e_x>>e_y;
		for(int x = st_x;x<e_x;x++){
			for(int y = st_y;y<e_y;y++){
				map[x][y] = 1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visit[i][j]==false && map[i][j] == 0){
				cnt = 1;				
				dfs(i,j);
				max_de[idx] = cnt; 
				idx++;
			}
		}
	}
	sort(max_de,max_de + idx);
	cout<<idx<<"\n";
	
	for(int i=0;i<idx;i++){
		cout<<max_de[i]<<" ";
	}
	return 0;
}
