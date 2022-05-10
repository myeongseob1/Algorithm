#include <iostream>
#include <queue>
using namespace std;
int n;
int dist[1001];
bool visit[1001];
int map[1001];
queue<int> q;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	q.push(0);
	visit[0] = true; 
	while(!q.empty()){
		int x = q.front();
		q.pop();
		
		for(int k=1;k<=map[x];k++){
			int nx = x + k;
			if(nx<n){
				if(!visit[nx]){
					visit[nx] = true;
					dist[nx] = dist[x] + 1;
					if(map[nx]!=0){
						q.push(nx);					
					}	
				}
			}
				
		}
	}
	if(dist[n-1]==0&&n!=1){
		dist[n-1] = -1;
	}
	cout<<dist[n-1]<<"\n";
	return 0;
}
