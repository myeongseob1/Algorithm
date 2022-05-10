#include <iostream>
#include <queue>

using namespace std;
bool visit[200];
int ladder[200];
int dist[200];
queue<int> q;
int n,m;
int main(void){
	cin>>n>>m;
	for(int i=0;i<n+m;i++){
		int a,b;
		cin>>a>>b;
		ladder[a] = b;
	}
	q.push(1);
	visit[1] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int k=1;k<=6;k++){
			int nx = x + k;
				if(nx>0&&nx<=100){
					if(ladder[nx]!=0){
						nx = ladder[nx];
					}
					if(visit[nx]==true) continue;
					visit[nx] = true;
					dist[nx] = dist[x] + 1;
					q.push(nx);
			}
			
		}
	}
	cout<<dist[100]<<"\n";
	return 0;
}
