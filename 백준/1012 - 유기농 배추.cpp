#include <iostream>

using namespace std;

int map[51][51];
bool visit[51][51];
int test_case;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,m,k;
int cnt;

void init(){
	for(int i=0;i<51;i++){
		for(int j=0;j<51;j++){
			map[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

void dfs(int x,int y,int c){
	visit[x][y] = true;
	for(int k=0;k<4;k++){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
			if(visit[nx][ny]==false&&map[nx][ny]==1){
				dfs(nx,ny,c);
			}
		}
	}
}

int main(void){
	cin>>test_case;
	for(int iii=0;iii<test_case;iii++){
		init();
		cin>>n>>m>>k;
		for(int i=0;i<k;i++){
			int a,b;
			cin>>a>>b;
			map[a][b] = 1;
		}
		int c = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(visit[i][j]==false&&map[i][j]==1){
					dfs(i,j,++c);
				}
			}
		}
		cout<<c<<"\n";
	}
	return 0;
}
