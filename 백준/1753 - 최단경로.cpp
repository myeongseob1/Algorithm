#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int v,e,start;
vector<pair<int,int> > ve[20001];
int dist[20001];
int main(void){
	cin>>v>>e>>start;
	for(int i=0;i<e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ve[a].push_back(make_pair(b,c));
		
	}
	for(int i=1;i<=v;i++){
		dist[i] = 987654321;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push(make_pair(0,start));
	dist[start] = 0;
	while(!pq.empty()){
		int x = pq.top().second;
		int dis = pq.top().first;
		pq.pop();
		for(int k=0;k<ve[x].size();k++){
			int n_x = ve[x][k].first;
			int n_dist = ve[x][k].second; 
			if( dist[n_x] > n_dist + dis  ){
				dist[n_x] = n_dist + dis;
				pq.push(make_pair(dist[n_x],n_x));
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
