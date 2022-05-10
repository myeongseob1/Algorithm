#include <iostream>

using namespace std;
int n;
int ans0,ans1,ans2;
int map[2200][2200];

void dfs(int x,int y,int size){
	bool we = true;
	int hyun = map[x][y];
	for(int i=x;i<x+size;i++){
		for(int j=y;j<y+size;j++){
			if(map[i][j]!=hyun){
				we = false;
				break;
			}
		}
	}
	if(we==true){
		if(hyun==-1){
			ans0++;
		}else if(hyun==0){
			ans1++;
		}else if(hyun==1){
			ans2++;
		}
	}else{
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				dfs(x+i*(size/3),y+j*(size/3),size/3);
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
	cout<<ans0<<"\n"<<ans1<<"\n"<<ans2<<"\n";
	return 0;
}
