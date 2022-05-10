#include <iostream>

using namespace std;
int n,m;
int map[101][101];
int main(void){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) map[i][j] = 1087654321;
		}
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b] = min(map[a][b],c);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				map[i][j] = min(map[i][k]+map[k][j],map[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
