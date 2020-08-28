#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int a[9][9];
int n,m;
int tmp[9][9];
vector<pair<int,int> > axis; 
void cctv(int x,int y, int direction){
	if(tmp[x][y]==6){
		return;
	}
	if(x<0||x>=n||y<0||y>=m){
		return;
	}
	if(direction == 1){
		if(x+1<n){
			tmp[x+1][y] = 9;
			cctv(x+1,y,direction);			
		}
		return;
	}	
	else if(direction == 2){
		if(y+1<m){
			tmp[x][y+1] = 9;
			cctv(x,y+1,direction);
		}
		return;
	}
	else if(direction == 3){
		if(x-1>=0){
			tmp[x-1][y] = 9;
			cctv(x-1,y,direction);
		}
		return;
	}
	else if(direction == 4){
		if(y-1>=0){
			tmp[x][y-1] = 9;
			cctv(x,y-1,direction);
		}
		return;
	}
}
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			tmp[i][j] = a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(tmp[i][j]==1){
				
			} 
		}
	}
	for(int i=1;i<=4;i++){
		cctv(2,2,i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<tmp[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
