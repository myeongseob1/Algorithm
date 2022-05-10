#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,pair<int,int> > > ve;
int v,e,answer;
int parent[10001];

int find(int x){
	if(parent[x]==x) return x;
	else return parent[x] = find(parent[x]);
}

void Union(int x,int y){
	x = find(x);
	y = find(y);
	
	if(x != y) parent[y] = x;
}

bool sameparent(int x,int y){
	x = find(x);
	y = find(y);
	
	if(x==y) return true;
	else return false;
}

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	cin>>v>>e;
 	for(int i=0;i<e;i++){
 		int from,to,cost;
 		cin>>from>>to>>cost;
 		ve.push_back(make_pair(cost,make_pair(from,to)));
	}
	sort(ve.begin(),ve.end());
	for(int i=1;i<=v;i++){
		parent[i] = i;
	}
	for(int i=0;i<e;i++){
		if(sameparent(ve[i].second.first,ve[i].second.second)==false){
			Union(ve[i].second.first,ve[i].second.second);
			answer += ve[i].first;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
