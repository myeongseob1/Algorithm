#include <iostream>
#include <vector>

using namespace std;

vector<int> connect[1001];
int n,m;
bool visit[1001];
int answer;
void dfs(int start){
	visit[start] = true;
	for(int i=0;i<connect[start].size();i++){
		int nx = connect[start][i];
		if(!visit[nx]){
			dfs(nx);
		}
	}
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		connect[u].push_back(v);
		connect[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			dfs(i);
			answer++;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
