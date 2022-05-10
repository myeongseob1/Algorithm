#include <iostream>

using namespace std;

int n;
int a[16][2];
int res;
void dfs(int iter,int sum){
	if(iter>=n-1){
		if(a[n-1][0]==1&&iter==n-1){
			res = max(res,sum+a[n-1][1]); 	
		}else{
			res = max(res,sum);		
		}
		return;
	}
	if(iter+a[iter][0]<=n){
		dfs(iter+a[iter][0],sum+a[iter][1]);	
	}
	dfs(iter+1,sum);
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=0;i<n;i++){
		if(i+a[i][0]<=n){
			dfs(i,0);
		}
	}
	cout<<res<<"\n";
	return 0;
}
