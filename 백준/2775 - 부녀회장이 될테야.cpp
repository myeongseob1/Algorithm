#include <iostream>

using namespace std;
int map[15][15];
int n;
int main(void){
	cin>>n;
	for(int i=1;i<15;i++){
		map[0][i] = i;
	}
	for(int i=1;i<15;i++){
		for(int j=1;j<15;j++){
			int sm = 0;
			for(int k=1;k<=j;k++){
				sm += map[i-1][k];
			}
			map[i][j] = sm;
		}
	}
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		cout<<map[a][b]<<"\n";
	}
	
	return 0;
}
