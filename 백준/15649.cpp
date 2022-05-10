#include <iostream>
#include <vector>

using namespace std;

int n,m;
bool visit[9];
vector<int> ve;
void dfs(int iter,int start){
	if(iter==m){
		for(int i=0;i<m;i++){
			cout<<ve[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=start;i<=n;i++){
		ve.push_back(i);
		dfs(iter+1,i);
		ve.pop_back();
	}
}

int main(void){
	cin>>n>>m;
	dfs(0,1);
	return 0;
}
