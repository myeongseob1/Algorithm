#include <iostream>
#include <cmath>
using namespace std;

int map[6][6];
bool vis[6][6];
bool usenum[1000000];
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int answer;

void init(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			vis[i][j] = false;
		}
	}
}

void dfs(int x,int y,int depth,int num){
	if(depth==5){
		int fnum= num + map[x][y];
		usenum[fnum] = true;
		return;
	}
	vis[x][y] = true;
	for(int k=0;k<4;k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx>=0&&nx<5&&ny>=0&&ny<5){
			dfs(nx,ny,depth+1,num+(map[x][y]*pow(10,5-depth)));
		}
	}
}

int main(void){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			dfs(i,j,0,0);
			init();
		}
	}
	for(int i=0;i<1000000;i++){
		if(usenum[i]) answer++;
	}
	cout<<answer<<"\n";
	return 0;
}
