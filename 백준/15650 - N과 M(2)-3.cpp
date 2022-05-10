#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> ve;
bool visit[9];
void dfs(int iter,int start){
	if(iter==m){
		for(int i=0;i<ve.size();i++){
			cout<<ve[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=start;i<=n;i++){
		if(visit[i]==false){
			ve.push_back(i);
			visit[i] = true;
			dfs(iter+1,i);
			visit[i] = false;
			ve.pop_back();
		}
	}
}

int main(void){
	cin>>n>>m;
	dfs(0,1);
	
	return 0;
}
