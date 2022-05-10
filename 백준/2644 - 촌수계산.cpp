#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> ve[101];
int n,a,b,m;
int dist[101];
bool visit[101];

int main(void){
	cin>>n>>a>>b>>m;
	for(int i=0;i<m;i++){
		int p,q;
		cin>>p>>q;
		ve[p].push_back(q);
		ve[q].push_back(p);
	}	
	queue<int> q;
	q.push(a);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int k=0;k<ve[x].size();k++){
			int nx = ve[x][k];
			if(!visit[nx]){
				dist[nx] = dist[x] + 1;
				visit[nx] = true;
				q.push(nx);
			}
		}
	}
	if(dist[b]==0){
		dist[b] = -1;
	} 
	cout<<dist[b]<<"\n";
	return 0;
} 
