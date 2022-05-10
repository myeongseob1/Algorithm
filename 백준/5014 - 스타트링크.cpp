#include <iostream>
#include <queue>

using namespace std;

int f,s,g,u,d;
bool visit[1000001];
int dist[1000001];
int main(void){
	cin>>f>>s>>g>>u>>d;
	queue<int> q;
	q.push(s);
	visit[s] = true;
	
	while(!q.empty()){
		int x = q.front();
		if(x==g) break;
		q.pop();
		int nx = x + u;
		if(nx <= f){
			if(!visit[nx]){
				dist[nx] = dist[x] + 1;
				visit[nx] = true;
				q.push(nx);
			}
		}
		
		nx = x - d;
		if(nx >= 1){
			if(!visit[nx]){
				dist[nx] = dist[x] + 1;
				visit[nx] = true;
				q.push(nx);
			}
		}

	}
	if(visit[g]==false){
		cout<<"use the stairs"<<"\n";
		return 0;
	} 
	cout<<dist[g]<<"\n";
	return 0;
}
