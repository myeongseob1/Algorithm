#include <iostream>

using namespace std;

int map[65][65];
string answer = "";
int n; 

void dfs(int x,int y,int sz){
	int hyun = map[x][y];
	bool pos = true;
	for(int i=x;i<x+sz;i++){
		for(int j=y;j<y+sz;j++){
			if(hyun!=map[i][j]){
				pos = false;
				break;
			}
			if(pos==false) break;
		}
	}
	if(pos==true){
		if(hyun==1){
			answer.push_back('1');
		}
		if(hyun==0){
			answer.push_back('0');
		}
	}else{
		answer.push_back('(');
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				dfs(x+(i*sz/2),y+(j*sz/2),sz/2);
				if(i==1&&j==1){
					answer.push_back(')');
				}
			}
		}
	}
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	dfs(0,0,n);
	cout<<answer<<"\n";
	return 0;
}
