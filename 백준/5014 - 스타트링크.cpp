#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int f,s,g,u,d;
int dist[1000001];
int main(void){
	cin>>f>>s>>g>>u>>d;
	queue<int> q;
	q.push(s);
	dist[s] = 1;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		int nt = t+u;
		if(nt<=f){
			if(dist[nt]==0){
				q.push(nt);
				dist[nt] = dist[t] + 1;						
			}
		}
		int nt2 = t-d;
		if(nt2>0){
			if(dist[nt2]==0){
				q.push(nt2);
				dist[nt2] = dist[t]+1;		
			}		
		}
	}

	if(dist[g]==0){
		cout<<"use the stairs"<<"\n";
	}
	else cout<<dist[g]-1<<"\n";
	return 0;
}

