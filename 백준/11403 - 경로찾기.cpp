#include <iostream>

using namespace std;

int n;
int map[101][101];

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j]==0&&map[i][k]==1&&map[k][j]==1) map[i][j] = 1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}
