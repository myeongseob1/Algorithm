#include <iostream>
#include <algorithm>

using namespace std;
int a[1000][3];
int n;
int dx[2] = {1,-1};
int c[1000];
void dfs(int start,int iter){
	if(iter==n){
		for(int i=0;i<n;i++){
			cout<<c[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	if(start>2||start<0){
		return;
	}
	
	c[iter] = a[iter][start];
	dfs(start-1,iter+1);
	dfs(start+1,iter+1);
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int i=0;i<2;i++){
		dfs(i,0);
		for(int i=0;i<n;i++){
			c[i] = 0;
		}

	}
	
	return 0;
}
