#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v,e,answer;
vector<pair<int,pair<int,int> > > ve;
int parent[10001];

int find(int x){
	if(parent[x]==x) return x;
	else return parent[x] = find(parent[x]);
}

bool same_parent(int a,int b){
	a = find(a);
	b = find(b);
	if(a==b) return true;
	else return false;
}

void union_node(int a,int b){
		a = find(a);
		b = find(b);
		if(a!=b) parent[b] = a;
}

int main(void){
	cin>>v>>e;
	for(int i=0;i<e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ve.push_back(make_pair(c,make_pair(a,b)));
	}
	sort(ve.begin(),ve.end());
	for(int i=1;i<=v;i++){
		parent[i] = i;
	}
	for(int i=0;i<e;i++){
		if(!same_parent(ve[i].second.first,ve[i].second.second)){
			union_node(ve[i].second.first,ve[i].second.second);
			answer += ve[i].first;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
