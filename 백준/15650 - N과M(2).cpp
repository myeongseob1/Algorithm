#include <iostream>
#include <vector>
using namespace std;

int n,m;
int ve[9];
bool visit[9];
void dfs(int iter,int start){
	if(iter==m){
		for(int i=0;i<m;i++){
			cout<<ve[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=start;i<n;i++){
		if(visit[i]==true){
			continue;
		}
		visit[i] = true;
		ve[iter] = i+1;
		dfs(iter+1,i);
		visit[i] = false;
	}
}

int main(void){
	cin>>n>>m;
	dfs(0,0);
	return 0;
}
