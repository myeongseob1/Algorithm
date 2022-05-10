#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ve[1001];
int n,m,v;
bool visit[1001];

void dfs(int st){
	visit[st] = true;
	cout<<st<<" ";
	for(int i=0;i<ve[st].size();i++){
		int pt = ve[st][i];
		if(visit[pt]==false){
			dfs(pt);
		}
	}
}

void bfs(int st){
	queue<int> q;
	q.push(st);
	visit[st] = true;
	while(!q.empty()){
		int n_t = q.front();
		q.pop();
		cout<<n_t<<" ";
		for(int i=0;i<ve[n_t].size();i++){
			int pt = ve[n_t][i];
			if(visit[pt]==false){
				q.push(pt);
				visit[pt] = true;
			}
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
		if(ve[i].size()>1)sort(ve[i].begin(),ve[i].end());
	}
	dfs(v);
	cout<<"\n";
	for(int i=0;i<1001;i++){
		visit[i] = false;
	}

	bfs(v);
	
	return 0;
} 
