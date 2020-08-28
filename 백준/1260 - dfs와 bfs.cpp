#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
bool check[1001];
vector<int> a[1001];
void dfs(int x){
	check[x] = true;
	cout<<x<<" ";
	for(int i=0;i<a[x].size();i++){
		int y = a[x][i];
		if(check[y]==false){
			dfs(y);
		}
	}
}
void bfs(int t){
	queue<int> q;
	check[t] = true; q.push(t);
	while(!q.empty()){
		int x = q.front(); q.pop();
		cout<<x<<" ";
		for(int i=0;i<a[x].size();i++){
			int y = a[x][i];
			if(check[y]==false){
				check[y] = true; q.push(y);
			}
		}
	}
}


int main(void){
	int n,m,start,p,q;
	cin>>n>>m>>start;
	for(int i=0;i<m;i++){
		cin>>p>>q;
		a[p].push_back(q);
		a[q].push_back(p);
	}
	
	for(int i=1;i<=n;i++){
		check[i] = false;
		sort(a[i].begin(),a[i].end());
	}
	dfs(start);
	for(int i=0;i<=n;i++){
		check[i] = false;
	}
	cout<<"\n";
	bfs(start);
	return 0;
}
