#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool visit[101][101];
int n,m,k;
int c,t;
vector<int> answer;

void dfs(int x,int y){
	t++;
	visit[x][y] = true;
	for(int k=0;k<4;k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
			if(!visit[nx][ny]&&map[nx][ny]==0){
				dfs(nx,ny);
			}
		}		
	}
} 

int main(void){
	cin>>n>>m>>k;
	for(int i=0;i<k;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int i=b;i<d;i++){
			for(int j=a;j<c;j++){
				map[i][j] = 1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==0&&visit[i][j]==false){
				dfs(i,j);
				c++;
				answer.push_back(t);
				t = 0;
			}
		}
	}
	sort(answer.begin(),answer.end());
	cout<<c<<"\n";
	for(int i=0;i<answer.size();i++){
		cout<<answer[i]<<" ";
	}
	return 0;
}
