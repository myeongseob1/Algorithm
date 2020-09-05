#include <iostream>

using namespace std;
int n;
int answer = 0;
int plan[16][2];
void dfs(int amount,int iter){
	if(iter>=n+1){
		answer = max(answer,amount);
		return;
	}
	if(iter+plan[iter][0]<=n+1) dfs(amount+plan[iter][1],iter+plan[iter][0]);
	dfs(amount,iter+1);
}
int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>plan[i][0]>>plan[i][1];
	}
	dfs(0,1);
	cout<<answer<<"\n";
	return 0;
}
