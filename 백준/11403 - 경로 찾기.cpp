#include <iostream>

using namespace std;

bool visit[101];
int map[101][101];
int answer[101][101];
int n; 
void dfs(int st,int hyun){
	for(int i=1;i<=n;i++){
		if(visit[i]==false&&map[hyun][i]==1){
			visit[i] = true;
			dfs(hyun,i);
		}
	}
}

int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>map[i][j];
			answer[i][j] = map[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			visit[j] = false;
		}
		for(int j=1;j<=n;j++){
			if(map[i][j]==1&&visit[j]==false&&i!=j){
				dfs(i,j);
			}
		}
		for(int j=1;j<=n;j++){
			if(visit[j]==true) answer[i][j] = 1;
			else if(map[i][j]==0&&visit[j]==false) answer[i][j] = 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<answer[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
