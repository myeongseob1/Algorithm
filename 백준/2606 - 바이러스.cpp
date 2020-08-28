#include <iostream>
#include <algorithm>
#include <vector> 
#include <queue>
using namespace std;
int n,net;
int check[101];
vector<int> p[101];
int main(void){
	int a,b;
	int answer = 0;
	cin>>n>>net;
	for(int i=0;i<net;i++){
		cin>>a>>b;
		p[a].push_back(b);
		p[b].push_back(a);
	}
	if(p[1].size()==0){
		cout<<0<<"\n";
	}
	else{
		queue<int> q;
		q.push(1);
		check[1] = true;
		while(!q.empty()){
			int c = q.front();
			q.pop();
			answer++;
			for(int i=0;i<p[c].size();i++){
				int t = p[c][i];
				if(check[t]==0){
					q.push(p[c][i]);
					check[t]=1;		
				}
			}
		}
		cout<<answer-1<<"\n";		
	}
	
	return 0;
}
