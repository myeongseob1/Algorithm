#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
int n,m;
void dfs(int iter){
	if(iter==m){
		for(int i=0;i<m;i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		a.push_back(i);
		dfs(iter+1);
		a.pop_back();
	}
}

int main(void){
	cin>>n>>m;
	dfs(0);
	
	return 0;
}
