#include <iostream>

using namespace std;

int map[15][15];
int n;
int answer;

bool deci(int x,int y){
	for(int i=0;i<n;i++){
		if(map[x][i]==1) return false;
		if(map[i][y]==1) return false;
	}
	for(int i=x,j=y;i>=0&&j>=0;i--,j--){
		if(map[i][j]==1) return false; 
	}
	for(int i=x,j=y;i<n&&j<n;i++,j++){
		if(map[i][j]==1) return false; 
	}
	for(int i=x,j=y;i<n&&j>=0;i++,j--){
		if(map[i][j]==1) return false; 
	}
	for(int i=x,j=y;i>=0&&j<n;i--,j++){
		if(map[i][j]==1) return false; 
	}

	return true;
}

void tracking(int iter){
	if(iter==n){
		answer++;
		return;
	}
	for(int i=0;i<n;i++){
		if(deci(i,iter)==true&&map[i][iter]==0){
			map[i][iter] = 1;
			tracking(iter+1);
			map[i][iter] = 0;
		}
	}
}

int main(void){
	cin>>n;
	tracking(0);
	cout<<answer<<"\n";
}
