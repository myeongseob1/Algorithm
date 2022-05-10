#include <iostream>
#include <queue>

using namespace std;
vector<pair<int,int> > ve[20001];
int dist[20001];
int v,e,k;
int main(void){
	cin>>v>>e>>k;
	for(int i=0;i<e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ve[a].push_back(make_pair(b,c));
	}
	for(int i=1;i<=v;i++){
		dist[i] = 987654321;
	}
	dist[k] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push(make_pair(0,k));
	while(!pq.empty()){
		int x = pq.top().second;
		int dst = pq.top().first;
		pq.pop();
		for(int i=0;i<ve[x].size();i++){
			int n_x = ve[x][i].first;
			int n_dist = ve[x][i].second;
			if(dst+n_dist < dist[n_x]){
				dist[n_x] = dst+n_dist;
				pq.push(make_pair(n_dist+dst,n_x));
			}
		}
	}
	for(int i=1;i<=v;i++){
		if(dist[i]==987654321){
			cout<<"INF"<<"\n";
			continue;
		}
		cout<<dist[i]<<"\n";
	}
	return 0;
}
