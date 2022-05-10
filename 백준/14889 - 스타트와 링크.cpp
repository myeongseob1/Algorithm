#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int synergy[21][21];
vector<int> v;

bool visit[21];
int answer = 1000000000;
void init(){
	for(int i=0;i<=n;i++){
		visit[i] = false;
	}
}
void dfs(int iter,int num){
	if(num == n/2){
		int ans1=0,ans2=0;
		init();
		for(int i=0;i<v.size();i++){
			visit[v[i]] = true;
		}
		vector<int> v2;
		for(int i=0;i<n;i++){
			if(visit[i]==false){
				v2.push_back(i);
			}
		}
		for(int i=0;i<n/2;i++){
			for(int j=i;j<n/2;j++){
				ans1 += synergy[v[i]][v[j]];
				ans1 += synergy[v[j]][v[i]];
				ans2 += synergy[v2[i]][v2[j]];
				ans2 += synergy[v2[j]][v2[i]];
			}
		}
		answer = min(answer,abs(ans1-ans2));
		return;
	}
	if(iter>=n){
		return;
	}
	v.push_back(iter);
	dfs(iter+1,num+1);
	v.pop_back();
	dfs(iter+1,num);
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>synergy[i][j];
		}
	}
	dfs(0,0);
	cout<<answer<<"\n";
	return 0;
}
