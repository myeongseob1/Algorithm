#include <iostream>


using namespace std;
int n;
int map[129][129];
int ans0,ans1;
void dfs(int x,int y,int sz){
	int hyun = map[x][y];
	bool we = true;
	for(int i=x;i<x+sz;i++){
		for(int j=y;j<y+sz;j++){
			if(map[i][j]!=hyun){
				we = false;
				break;
			}
		}
		if(we==false) break;
	}
	if(we==true){
		if(hyun==0) ans0++;
		else if(hyun==1) ans1++;
	}else{
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				dfs(x+(i*(sz/2)),y+(j*(sz/2)),sz/2);
			}
		}	
	}
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	dfs(0,0,n);
	cout<<ans0<<"\n"<<ans1<<"\n";
	return 0;
}
