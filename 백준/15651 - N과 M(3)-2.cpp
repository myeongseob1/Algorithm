#include <iostream>

using namespace std;

int n,m;
int num[9];

void dfs(int iter){
	if(iter==m){
		for(int i=0;i<m;i++){
			cout<<num[i]<<" ";
		}		
		cout<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		num[iter] = i;
		dfs(iter+1);
	}
	
}

int main(void){
	cin>>n>>m;
	dfs(0);
	return 0;
}
