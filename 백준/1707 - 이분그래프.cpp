#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int color[20001];
vector<int> list[20001];

void dfs(int start,int c){
	color[start] = c;

	for(int i=0;i<list[start].size();i++){
		int y = list[start][i];
		if(color[y]==0){
			dfs(y,3-c);
		}
	}
}


int main(void){
	int iter,v,e,a,b;
	cin>>iter;
	for(int i=0;i<iter;i++){
		cin>>v>>e;
		for(int j=1;j<=v;j++){
			list[j].clear();
		}
		for(int j=0;j<e;j++){
			cin>>a>>b;
			list[a].push_back(b);
			list[b].push_back(a);
		}
		for(int j=1;j<=v;j++){
			color[j] = 0;
		}
		for(int j=1;j<=v;j++){
			if(color[j]==0){
				dfs(j,1);			
			}	
		}
	
		bool ok = true;
		for(int j=1;j<=v;j++){
			for(int p=0;p<list[j].size();p++){
				int t = list[j][p];
				if(color[j]==color[t]){
					ok = false;
				}
			}
		}
		if(ok==true){
			cout<<"YES"<<"\n";
		}
		else cout<<"NO"<<"\n";
	}
	
	return 0;
}
