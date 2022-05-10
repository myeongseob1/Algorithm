#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int p[9];
void dfs(int iter){
	if(iter==m){
		for(int i=0;i<m;i++){
			cout<<p[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=0;i<n;i++){
		p[iter] = i+1;
		dfs(iter+1);
	}
}
int main(void){
	cin>>n>>m;

	dfs(0);
	return 0;
}
