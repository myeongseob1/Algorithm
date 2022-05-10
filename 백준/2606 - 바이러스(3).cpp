#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<int> ve[101];
bool visit[101];
int answer;
int main(void){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		ve[a].push_back(b);
		ve[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	visit[1] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int k=0;k<ve[x].size();k++){
			int nx = ve[x][k];
			if(!visit[nx]){
				visit[nx] = true;
				q.push(nx);
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(visit[i]) answer++;
	}
	cout<<answer<<"\n";
	return 0;
}
