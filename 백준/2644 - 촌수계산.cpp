#include <iostream>
#include <queue>

using namespace std;
int n;
int visit[101];
int dist[101];
vector<int> rel[101];
int main(void){
	int a,b,p,c,d;
	queue<int> q;
	cin>>n;
	cin>>a>>b;
	cin>>p;
	for(int i=0;i<p;i++){
		cin>>c>>d;
		rel[c].push_back(d);
		rel[d].push_back(c);
	}
	q.push(a);
	visit[a] = 1;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i=0;i<rel[t].size();i++){
			if(visit[rel[t][i]]==0){
				visit[rel[t][i]]++;
				dist[rel[t][i]] = dist[t]+1;
				q.push(rel[t][i]);
			}
		}
	}
	if(dist[b]==0){
		cout<<-1<<"\n";
	}
	else
	cout<<dist[b]<<"\n";
	
	return 0;
}
