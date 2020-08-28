#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 200000;
bool check[MAX+1];
int dist[MAX+1];
int main(void){
	int n,k;
	queue<int> q;

	cin>>n>>k;
	
	check[n] = true;
	dist[n] = 0;
	q.push(n);
	while(!q.empty()){
		int x = q.front(); q.pop();
		if(2*x<MAX){
			int nx = 2*x;
			if(check[nx]==false){
				q.push(nx);
				dist[nx] = dist[x]+1;
				check[nx] = true; 
			}
		}
		if(x+1<=MAX){
			int nx = x+1;
			if(check[nx]==false){
				q.push(nx);
				dist[nx] = dist[x]+1;
				check[nx] = true; 
			}
		}
		if(x-1>=0){
			int nx = x-1;
				if(check[nx]==false){
				q.push(nx);
				dist[nx] = dist[x]+1;
				check[nx] = true; 
			}
		}
	}
	cout<<dist[k]<<"\n";
	return 0;
}
