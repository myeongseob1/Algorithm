#include <iostream>
#include <queue>


using namespace std;

int dist[200001];
bool check[200001];
int main(void){
	int n,k;
	cin>>n>>k;
	queue<int> q;
	q.push(n);
	check[n] = true;
	dist[n] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(2*x<200001){
			int nx = 2*x;
			if(check[nx]==false){
				q.push(nx);
				dist[nx] = dist[x] +1;
				check[nx] = true;		
			}
		}
		if(x+1<200001){
			int nx = x+1;
			if(check[nx]==false){
				q.push(nx);
				dist[nx] = dist[x]+1;
				check[nx] = true;
			}
		}
		if(x-1>=0){
			int nx=x-1;
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
