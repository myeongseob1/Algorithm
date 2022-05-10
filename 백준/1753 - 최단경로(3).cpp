#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int v,e,k;
int dist[20001];
vector<pair<int,int> > ve[20001];
int main(void){
	cin>>v>>e;
	cin>>k;
	for(int i=0;i<e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ve[a].push_back(make_pair(b,c));
	}
	for(int i=1;i<=v;i++){
		dist[i] = 987654321;
	}
	dist[k] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push(make_pair(0,k));
	while(!pq.empty()){
		int x_dist = pq.top().first;
		int per = pq.top().second;
		pq.pop();
		for(int k=0;k<ve[per].size();k++){
			int n_dist = ve[per][k].second;
			int n_per = ve[per][k].first;
			if(n_dist + x_dist < dist[n_per]){
				dist[n_per] = n_dist + x_dist;
				pq.push(make_pair(n_dist+x_dist,n_per));
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
