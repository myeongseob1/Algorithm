#include <iostream>
#include <queue>
#include <string>
using namespace std;

int pos[200001];
bool visit[200001];
vector<int> track[200001];
int n,k;
queue<int> q;

int main(void){
	cin>>n>>k;
	q.push(n);
	visit[n] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x==k) break;
		if(2*x<=200000){
			if(!visit[2*x]){
				visit[2*x] = true;
				pos[2*x] = pos[x] + 1;
				track[2*x].push_back(x);
				q.push(2*x);	
			}
		}
		if(x+1<=200000){
			if(!visit[x+1]){
				visit[x+1] = true;
				pos[x+1] = pos[x] + 1;
				track[x+1].push_back(x);
				q.push(x+1);	
			}
		}
		if(x-1>=0){
			if(!visit[x-1]){				
				visit[x-1] = true;
				pos[x-1] = pos[x] + 1;
				track[x-1].push_back(x);
				q.push(x-1);
			}
		}
	}
	vector<int> rslt;
	rslt.push_back(k);
	for(int i=k;i!=n;i=track[i][0]){
		rslt.push_back(track[i][0]);
	}

	cout<<pos[k]<<"\n";
	for(int i=rslt.size()-1;i>=0;i--){
		cout<<rslt[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
