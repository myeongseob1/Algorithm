#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[26][26];
int d[26][26];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int answer[577];
int iter;
void dfs(int x,int y,int c){
	d[x][y] = c;
	for(int k=0;k<4;k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(0<=nx&&nx<iter&&0<=ny&&ny<iter){
			if(a[nx][ny]==1&&d[nx][ny]==0){
				dfs(nx,ny,c);				
			}
		}
	}
}

int main(void){

	cin>>iter;
	for(int i=0;i<iter;i++){
		for(int j=0;j<iter;j++){
			scanf("%1d",&a[i][j]);
			d[i][j] = 0;
		}
	}
	int start = 0;
	for(int i=0;i<iter;i++){
		for(int j=0;j<iter;j++){
			if(a[i][j]==1&&d[i][j]==0){
				dfs(i,j,++start);
			}
		}
	}
	for(int i=0;i<iter;i++){
		for(int j=0;j<iter;j++){
			answer[d[i][j]]++;
		}
	}
	cout<<start<<"\n";
	sort(answer+1,answer+start+1);
	for(int i=1;i<start+1;i++){
		cout<<answer[i]<<"\n";
	}	
	return 0;
}
