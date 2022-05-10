#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> connect[2001];
bool visit[2001];
int rslt;
void dfs(int start,int cnt){
	if(cnt==5){
		rslt = 1;
		return;
	}
	visit[start] = true;
	for(int k=0;k<connect[start].size();k++){
		int nx = connect[start][k];
		if(!visit[nx]){
			dfs(nx,cnt+1);
		}
	}
	visit[start] = false;
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
	for(int i=0;i<n;i++){
		if(!visit[i]) dfs(i,1);
	}
	cout<<rslt<<"\n";
	return 0;
} 
