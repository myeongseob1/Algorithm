#include <iostream>
#include <vector>
using namespace std;

int n,m;

int num[9];
bool visit[9];

void dfs(int iter){
	if(iter==m){
		for(int i=0;i<m;i++){
			cout<<num[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(visit[i]==true) continue;
		num[iter] = i;
		visit[i] = true;
		dfs(iter+1);
		visit[i] = false;
	}
}

int main(void){
	cin>>n>>m;
	dfs(0);
	return 0;
}
