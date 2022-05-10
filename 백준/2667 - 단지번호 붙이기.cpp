#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

string map[26];
int n,t;
bool visit[26][26];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<int> ve;
void dfs(int x,int y,int num){
	visit[x][y] = true;
	t++;
	for(int k=0;k<4;k++){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<n){
			if(!visit[nx][ny]&&map[nx][ny]=='1'){
				dfs(nx,ny,num);
			}
		}	
	}	
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	int cnt = 0;
	int num = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]=='1'&&!visit[i][j]){
				dfs(i,j,++num);
				ve.push_back(t);
				t = 0;			
				cnt++;
			}
		}
	}
	sort(ve.begin(),ve.end());
	cout<<cnt<<"\n";
	for(int i=0;i<ve.size();i++){
		cout<<ve[i]<<"\n";
	}
	return 0;
}
