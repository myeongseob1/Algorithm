#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
string map[26];
int n;
bool visit[26][26];
int cnt;
void dfs(int x,int y,int c){
	visit[x][y] = true;
	cnt++;
	for(int k=0;k<4;k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<n){
			if(visit[nx][ny]==false&&map[nx][ny]=='1'){
				dfs(nx,ny,c);
			}
		}
	}
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	vector<int> pr;
	int c = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(visit[i][j]==false&&map[i][j]=='1'){
				dfs(i,j,++c);
				pr.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(pr.begin(),pr.end());
	cout<<c<<"\n";
	for(int i=0;i<pr.size();i++){
		cout<<pr[i]<<"\n";
	}	
	return 0;
}
