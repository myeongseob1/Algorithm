#include <iostream>
#include <vector>
using namespace std;

vector<int> comp[101];
int n,m;
bool visit[101];
int answer;

void dfs(int st){
	visit[st] = true;
	for(int i=0;i<comp[st].size();i++){
		int x = comp[st][i];
		if(visit[x]==false){
			dfs(x);
		}
	}
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		comp[a].push_back(b);
		comp[b].push_back(a);
	}
	dfs(1);
	for(int i=2;i<=n;i++){
		if(visit[i]==true) answer++;
	}
	cout<<answer<<"\n";
	return 0;
}
