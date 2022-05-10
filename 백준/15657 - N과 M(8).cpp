#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> ve;
vector<int> ve2;
bool visit[9];
void dfs(int iter,int start){
	if(iter==m){
		for(int i=0;i<m;i++){
			cout<<ve2[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=start;i<n;i++){
		ve2.push_back(ve[i]);
		dfs(iter+1,i);
		ve2.pop_back();
	}
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		ve.push_back(a);
	}
	sort(ve.begin(),ve.end());
	dfs(0,0);
	return 0;
}
