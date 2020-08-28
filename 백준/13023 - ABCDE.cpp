#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check[2001];
vector<int> a[2001];
void dfs(int start){
	check[start]++;
	for(int i=0;i<a[start].size();i++){
		int y = a[start][i];
		if(check[y]==0){
			dfs(y);
		}
	}
}

int main(void){
	int n,m,p,q;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>p>>q;
		a[p].push_back(q);
		a[q].push_back(p);
	}
	for(int i=0;i<n;i++){
		check[i] = 0;
	}
	for(int i =0;i<n;i++){
		dfs(i);		
	}

	for(int i=0;i<n;i++){
		cout<<check[i]<<" ";
	}		

	
	return 0;
}
