#include <iostream>

using namespace std;

int map[101][101];
int cpy_map[101][101];
int n,m,r;

void init(){
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			cpy_map[i][j] = 0;
		}
	}
}

void cpy_re(){
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			map[i][j] = cpy_map[i][j];
		}
	}
}

void wheel(int num){
	init();
	if(num==1){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cpy_map[i][j] = map[n-1-i][j];
			}
		}
	}
	else if(num==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cpy_map[i][j] = map[i][m-1-j];
			}
		}		
	}
	else if(num==3){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cpy_map[i][j] = map[n-1-j][i];
			}
		}
		int tmp = n;
		n = m;
		m = tmp;
	}
	else if(num==4){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cpy_map[i][j] = map[j][m-1-i];
			}
		}
		int tmp = n;
		n = m;
		m = tmp;
		
	}
	else if(num==5){
		for(int i=0;i<n/2;i++){
			for(int j=0;j<m/2;j++){
				cpy_map[i][j+m/2] = map[i][j];
				cpy_map[i][j] = map[i+n/2][j];
				cpy_map[i+n/2][j] = map[i+n/2][j+m/2];
				cpy_map[i+n/2][j+m/2] = map[i][j+m/2];
			}
		}
	}
	else if(num==6){
		for(int i=0;i<n/2;i++){
			for(int j=0;j<m/2;j++){
				cpy_map[i+n/2][j+m/2] = map[i+n/2][j];
				cpy_map[i][j] = map[i][j+m/2];
				cpy_map[i+n/2][j] = map[i][j];
				cpy_map[i][j+m/2] = map[i+n/2][j+m/2];
			}
		}
		
	}
	cpy_re();
}

int main(void){
	cin>>n>>m>>r;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<r;i++){
		int t;
		cin>>t;
		wheel(t);
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<"\n";
	}		


	return 0;
}
