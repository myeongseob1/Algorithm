#include <iostream>
#include <algorithm>

using namespace std;
long long int n,s;
long long int a[41];
long long int answer;

void dfs(int iter,int nu){
	if(iter>=n){
		return;
	}
	if(nu==s){
		answer++;
		return;
	}

	dfs(iter+1,nu);
	dfs(iter+1,nu+a[iter]);
	
}

int main(void){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dfs(i,a[i]);		
	}
	cout<<answer<<"\n";
	return 0;
}
