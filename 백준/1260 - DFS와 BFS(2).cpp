#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,v;
vector<int> pnt[1001];
bool visit[1001];

void dfs(int start){
	visit[start] = true;
	cout<<start<<" ";
	for(int i=0;i<pnt[start].size();i++){
		int nxt = pnt[start][i];
		if(!visit[nxt]){
			dfs(nxt);
		}
	}
}
int main(void){
	cin>>n>>m>>v;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		pnt[a].push_back(b);
		pnt[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(pnt[i].size()>1){
			sort(pnt[i].begin(),pnt[i].end());
		}
	}
	dfs(v);
	cout<<"\n";
	for(int i=1;i<=n;i++){
		visit[i] = false;
	}
	queue<int> q;
	q.push(v);
	visit[v] = true;
	while(!q.empty()){
		int x = q.front();
		cout<<x<<" ";
		q.pop();
		for(int i=0;i<pnt[x].size();i++){
			int nx = pnt[x][i];
			if(!visit[nx]){
				visit[nx] = true;
				q.push(nx);
			}
		}
	}
	cout<<"\n";
	return 0;
}
