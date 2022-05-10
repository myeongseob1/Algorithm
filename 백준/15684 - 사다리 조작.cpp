#include <iostream>

using namespace std;
int n,m,h;
int answer = 98765;
int stair[31][11];
bool end_game(){
	for(int j=1;j<=n;j++){
		int a = j;
		for(int i=1;i<=h;i++){
			if(stair[i][a]==1){
				a++;
			}
			else if(stair[i][a-1]==1){
				a--;
			}
		}
		if(a!=j) return false;
	}
	return true;
}
void dfs(int x, int num){
	if(num>3){
		return;
	}
	if(end_game()==true){
		answer = min(answer,num);
		return;
	}
	for(int i=x;i<=h;i++){
		for(int j=1;j<=n;j++){
			if(stair[i][j]==0&&stair[i][j-1]==0&&stair[i][j+1]==0){
				stair[i][j] = 1;
				dfs(i,num+1);	
				stair[i][j] = 0;
			}			
		}
	}	
}

int main(void){
	cin>>n>>m>>h;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		stair[a][b] = 1;
		
	}
	dfs(1,0);
	if(answer==98765){
		answer = -1;
	}
	cout<<answer<<"\n";
	return 0;
}
