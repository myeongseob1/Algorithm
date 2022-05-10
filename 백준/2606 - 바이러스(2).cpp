#include <iostream>
#include <vector> 
using namespace std;
int n,m,answer;
vector<int> connect[101];
bool visit[101];
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
		int a,b;
		cin>>a>>b;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
	dfs(1);
	for(int i=2;i<=n;i++){
		if(visit[i]){
			answer++;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
