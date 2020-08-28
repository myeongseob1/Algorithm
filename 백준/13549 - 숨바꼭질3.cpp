#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 200000;
int dist[MAX+1];
bool check[MAX+1];

int main(void){
	int n,k;
	queue<int> q;
	cin>>n>>k;
	
	q.push(n);
	dist[n] = 0;
	check[n] = true;
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(2*x<=MAX){
			int nx = 2*x;
			if(check[nx]==false){
				check[nx] = true;
				dist[nx] = dist[x]; 
				q.push(nx);
			}
		}
		if(x-1>=0){
			int nx = x-1;
			if(check[nx]==false){
				check[nx] = true;
				dist[nx] = dist[x]+1;
				q.push(nx);
			}
		}

		if(x+1<=MAX){
			int nx = x+1;
			if(check[nx]==false){
				check[nx] = true;
				dist[nx] = dist[x]+1; 
				q.push(nx);
			}
		}
	}
	cout<<dist[k]<<"\n";
	return 0;
}
