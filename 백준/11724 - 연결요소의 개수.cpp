#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list[1001];
bool check[1001];

void dfs(int start){
	check[start] = true;
	for(int i=0;i<list[start].size();i++){
		int y = list[start][i];
		if(check[y]==false){
			dfs(y);
		}
	}
}

int main(void){
	int n,m,p,q,result=0;
	cin>>n>>m;

	for(int i=1;i<=m;i++){
		cin>>p>>q;	
		list[p].push_back(q);
		list[q].push_back(p);
	}
	for(int i=1;i<=n;i++){
		check[i] = false;
	}
	
	for(int i=1;i<=n;i++){
		if(check[i]==false){
			dfs(i);
			result++;			
		}

	}
	cout<<result<<"\n";
	return 0;
}

