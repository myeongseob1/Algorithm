#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,v;
vector<int> ve[1001];
bool visit[1001];

void dfs(int start){
	cout<<start<<" ";
	visit[start] = true;
	for(int i=0;i<ve[start].size();i++){
		int nx = ve[start][i];
		if(visit[nx]==false){
			dfs(nx);
		}
	}
}

int main(void){
	cin>>n>>m>>v;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		ve[a].push_back(b);
		ve[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(ve[i].size() > 1){
			sort(ve[i].begin(),ve[i].end());
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
		for(int i=0;i<ve[x].size();i++){
			int nx = ve[x][i];
			if(visit[nx]==false){
				visit[nx] = true;
				q.push(nx);
			}
		}
	}
	cout<<"\n";
	return 0;
} 
